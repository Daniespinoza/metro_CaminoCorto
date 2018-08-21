//
//  helpers.c
//  metro-graph
//
//  Created by Elias Hernandis on 25/12/2016.

#include "helpers.h"

void imprimir_autores(){
    printf("\n");
    printf("Aplicación desarrollada por:\n");
    printf("- Nicolás Cortés.\n");
    printf("- Rodrigo Echeverría.\n");
    printf("- Daniel Espinoza.\n");
    printf("\n");
}


char *strtolow(char *string)
{
    unsigned long len = strlen(string);
    char *lower = malloc((len + 1) * sizeof(char));

    for (int i = 0; i < len; i++)
        lower[i] = tolower(string[i]);

    return lower;
}

void print_station(Station *station)
{
    printf("%s\n", station->name);
    for (int i = 0; i < station->n_adj; i++)
        printf(" | %s\n", station->adj[i]->name);
}

int load_map(Station **list, const char *filename)
{
    if (!filename)
        return -1;

    FILE *map = fopen(filename, "r");
    if (!map)
        return -2;

    char buffer[MAX_STR];
    Station *prev, *curr = NULL;
    int i = 0;

    while (!feof(map))
    {
        // read each line
        fgets(buffer, MAX_STR, map);

        // skip over if its a comment (also, reset current and prev stations)
        if (buffer[0] == '#')
        {
            prev = NULL;
            curr = NULL;
            continue;
        }

        // remember the previous station
        prev = curr;
        curr = malloc(sizeof(Station));

        char codigo[MAX_STR];
        char nombre[MAX_STR];
        
        memset(codigo, 0, sizeof codigo);
        memset(nombre, 0, sizeof nombre);
        
        //printf("%s\n",buffer);
        int z = 0;
        for(z; z < strlen(buffer);z++){
            //printf("%c\n",buffer[z]);
            if(buffer[z] != '|'){
                codigo[z] = buffer[z];
            }
            else{
                z = z + 1;
                break;
            }
        }
        
        //printf("%s\n",codigo);
        
        strcpy(curr->code,codigo);
        
        for(int y = 0; z < strlen(buffer);y++){
            if(buffer[z] != '|'){
                nombre[y] = buffer[z];
                //printf("%c\n",nombre[z]);
            }
            else{
                break;
            }
            z = z + 1;
        }
        
        //printf("%s\n",nombre);
        
        strcpy(curr->name, nombre);
        
        
        // read the name of the station
        //strcpy(curr->name, strtok(buffer, "|"));

        // check if we found it before
        int found_before = 0;
        for (int j = 0; j < i; j++)
        {
            if (strcmp(curr->name, list[j]->name) == 0)
            {
                // forget about this duplicate and point to the older one
                free(curr);
                curr = list[j];

                found_before = 1;
                break;
            }
        }

        // some init if we didn't know about the station
        if (!found_before)
        {
            list[i] = curr;
            i++;
            curr->n_adj = 0;
        }

        if (prev)
        {
            // link the previous station to this one, if not done already
            int in_adj = 0;
            for (int j = 0; j < prev->n_adj; j++)
            {
                if (prev->adj[j] == curr)
                {
                    in_adj = 1;
                    break;
                }
            }

            if (!in_adj)
            {
                prev->adj[prev->n_adj] = curr;
                prev->n_adj++;
            }

            // link this station to the previous one, if not done already
            in_adj = 0;
            for (int j = 0; j < curr->n_adj; j++)
            {
                if (curr->adj[j] == prev)
                {
                    in_adj = 1;
                    break;
                }
            }

            if (!in_adj)
            {
                curr->adj[curr->n_adj] = prev;
                curr->n_adj++;
            }
        }
    }

    fclose(map);
    return i;
}