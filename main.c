#include <stdio.h>
#include <stdlib.h>
#include "cs50.h"
#include "helpers.h"

#define MAP_FILENAME "metro-santiago.txt"
#define MAX_QUERY_RESULTS 10

/*
 * Returns the length of the shortest path found, or a negative number on error.
 *
 * The first argument must be an array of pointers to individual Stations.
 * The second argument is the number of Stations in the graph.
 * The third argument must be a pointer to the starting Station (which must be also pointed
 *      to by the list).
 * The fourth argument must be a pointer to the destination Station (which must be also
 *      pointed to by the list).
 */
int dijkstra(Station **graph, int n_stations, Station *start, Station *end)
{
    int path_length = 0;
    
    // init all distances to infinity and open all vertices
    for (int i = 0; i < n_stations; i++)
    {
        graph[i]->dist = 1000;
        graph[i]->closed = 0;
    }
    
    // init the distance to the starting node to 0 and close it
    start->dist = 0;
    start->closed = 1;
    start->prev = NULL;
    
    // make the nodes next to it have distance one
    for (int i = 0; i < start->n_adj; i++)
    {
        start->adj[i]->dist = start->dist + 1;
        start->adj[i]->prev = start;
    }
    
    while (!end->closed) {
        Station *best_candidate = graph[0];
        // find the closest open vertex
        for (int i = 0; i < n_stations; i++)
        {
            // immediately replace the best candidate with another one if it is closed
            if (best_candidate->closed)
            {
                best_candidate = graph[i];
                continue;
            }
            
            if (graph[i]->dist < best_candidate->dist && !graph[i]->closed)
                best_candidate = graph[i];
        }
        
        // close it
        best_candidate->closed = 1;
        
        for (int i = 0; i < best_candidate->n_adj; i++)
        {
            if (!best_candidate->adj[i]->closed )//&& best_candidate->adj[i]->dist < best_candidate->dist + 1)
            {
                best_candidate->adj[i]->dist = best_candidate->dist + 1; // all stations are adjacent to this one
                best_candidate->adj[i]->prev = best_candidate;
            }
        }
        
        
    }
    
    return path_length;
}

Station *select_station(Station **list, int n_stations,char* codigo)
{    
    // we use calloc to be able to check for null
    Station **candidates = calloc(MAX_QUERY_RESULTS, sizeof(Station *));
    
    
    //char *query;
    
    
    int i, results, selection;
    
    //printf("Acá va el codigo: %s\n",codigo);
    //printf("Acá va la query: %s\n",query);
    //printf("Acá va estacion: %s\n",estacion);
    
    //strcpy(query,estacion);
    
    //printf("Acá va la query: %s\n",query);    
    
    ////do {
    ////    printf("Search for a station: ");
    ////    query = GetString();
    ////    if (!query)
    ////        return NULL;
    
        //codigo = strtolow(codigo);
          //  printf("Acá va el codigo en minúsculas: %s\n",codigo);
        //query = strtolow(query); // ignore case during search
        // TODO: we're leaking memory here
    
        // TODO: we can do better than linear search
        for (i = 0, results = 0; i < n_stations && results < MAX_QUERY_RESULTS; i++)
        {
            //printf("Nombre de la estación en la lista: %s\n",strtolow(list[i]->name));
            // TODO: we're also leaking memory here
            //if (strstr(list[i]->code, codigo))
            if (!strcmp(list[i]->code, codigo))
            {
                candidates[results] = list[i];
                results++;
                //printf("Código de la estación en la lista: %s\n",list[i]->code);
                //printf("Código recibido: %s\n",codigo);
            }
        }
    
        if (results == 0)
        {
            printf("No hay estaciones con este nombre.\n");
            selection = 0; // just in case it something else
        }
        else if (results == 1)
        {
            // if we just found one match, go ahead and select it
            selection = 1;
            //break;
        }
        /*
        else
        {
            // print the matches we found
            for (i = 0; i < results; i++)
            {
                if (candidates[i])
                    printf("%d. %s\n", i + 1, candidates[i]->name);
                else
                    break;
            }
    
            do
            {
                printf("Select a station from the list (type the number, or 0 to search again): ");
                selection = GetInt();
            } while (selection < 0 || selection > results);
        }
        */
        
    //} while (selection < 1);
    
    selection--; // translate to programmer-counting lingo
    //printf("you selected \"%s\"\n", candidates[selection]->name);
    return candidates[selection];
}

int main(int argc, char** argv)
{
    if (argc < 2){
        printf("\n");
        printf("Forma de uso:\n");
        printf("Ver integrantes: ./programa -v\n");
        printf("Encontrar ruta más corta: ./programa -f [CODIGO_ESTACION_ORIGEN] [CODIGO_ESTACION_DESTINO]\n");
        printf("\n");
        exit(1);
    }
    
    char* parametro = argv[1];

    if(strcmp(parametro,"-v") == 0){
        imprimir_autores();
    }
    else{
        if(strcmp(parametro,"-f") == 0){
            
            Station *list[MAX_STATIONS];
            
            int n_stations = load_map(list, MAP_FILENAME);
            
            if (n_stations < 0){
                printf("Error: No se pudo abrir el archivo.\n");
                return 1;
            }
            
            char* estacion_origen = argv[2];
            char* estacion_destino = argv[3];
            
            Station *start, *end;
            
            //printf("Antes del start y end\n");
            //printf("%s\n",estacion_origen);
            //printf("%s\n",estacion_destino);
            
            start = select_station(list, n_stations,estacion_origen);
            
            end = select_station(list, n_stations,estacion_destino);
            
            //printf("Después del start y end\n");
            
            if (dijkstra(list, n_stations, start, end) < 0){
                printf("No se pudo encontrar el camino más corto.\n");
                return 2;
            }

            printf("\nRuta óptima desde %s hasta %s es:\n", start->name, end->name);

            printf("\n%s\n", end->name);
            
            Station *curr = NULL;
            curr = end->prev;
            while (curr != start)
            {
                printf(" | %s\n", curr->name);
                curr = curr->prev;
            }
            printf("%s\n\n", start->name);
            
        }
        else{
            printf("\n");
            printf("Argumentos incorrectos.\n");
            printf("\n");
        }
    }
    
    //printf("Metro de Madrid was loaded...\n");
    //printf("You can now search for a route between two stations.\n\n");
    
    
    
    //printf("Select the departure station:\n");
    //start = select_station(list, n_stations);
    //if (!start)
    //{
    //    printf("error: could not select departure station\n");
    //    return 3;
    //}
    
    
    //printf("\nSelect the destination station\n");
    //end = select_station(list, n_stations);
    //if (!end)
    //{
    //    printf("error: could not select destination station\n");
    //    return 4;
    //}
    
    //if (dijkstra(list, n_stations, start, end) < 0)
    //{
    //    printf("could not find a shortest path\n");
    //    return 2;
    //}
    //
    //printf("\nOptimal path from %s to %s is:\n", start->name, end->name);
    //
    //printf("\n%s\n", end->name);
    
    //Station *curr = NULL;
    //curr = end->prev;
    //while (curr != start)
    //{
    //    printf(" | %s\n", curr->name);
    //    curr = curr->prev;
    //}
    //printf("%s\n\n", start->name);
    
    return 0;
}