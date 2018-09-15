/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nicolas
 *
 * Created on 8 de septiembre de 2018, 16:35
 */

    /*Cantidad de vértices: 107 estaciones reales + 11 repetidas = 118.
     Linea 1: 27 estaciones.
     Linea 2: 22 estaciones.
     Linea 4: 23 estaciones.
     Linea 4a: 6 estaciones.
     Linea 5: 30 estaciones.
     Linea 6: 10 estaciones.

    Cantidad de aristas: 101 aristas reales + 11 para las combinaciones = 112.
     Linea 1: 26 aristas.
     Linea 2: 21 aristas.
     Linea 4: 22 aristas.
     Linea 4a: 5 aristas.
     Linea 5: 29 aristas.
     Linea 6: 9 aristas.

    Cantidad de combinaciones: 5 + 4 + 3 + 2 + 5 + 3 combinaciones reales + 11 repetidas = 33.
     Linea 1: San Pablo, Los Héroes, Baquedano, Los Leones, Tobalaba (5).
     Linea 2: La Cisterna, Franklin, Los Héroes, Santa Ana (4).
     Linea 4: Vicente Valdés, Vicuña Mackenna, Tobalaba (3).
     Linea 4a: La Cisterna, Vicuña Mackenna (2).
     Linea 5: Vicente Valdés, Ñuble, Baquedano, Santa Ana, San Pablo (5).
     Linea 6: Franklin, Ñuble, Los Leones (3).
     * Únicos: San Pablo, Los Héroes, Baquedano, Los Leones, Tobalaba, La Cisterna, Franklin
     * Santa Ana, Vicente Valdés, Vicuña Mackenna, Ñuble (11).
     */

#include "Funciones.h"
#include </usr/include/mpi/mpi.h>

//lista de adyacencia
vector< Node > ady[ max ];

//distancia[ u ] distancia de vértice inicial a vértice con ID = u
int distancia[ max ];

//para vértices visitados
bool visitado[ max ];

//priority queue propia del c++, usamos el comparador definido 
//para que el de menor valor este en el tope
priority_queue< Node , vector<Node> , cmp > Q;

//numero de vertices
int V = cantidad_estaciones;

//para la impresion de caminos
int previo[ max ];

/**
 * Función de inicialización.
 */
void init(){
    for( int i = 0 ; i <= V ; ++i ){
        distancia[ i ] = INF;  //inicializamos todas las distancias con valor infinito
        visitado[ i ] = false; //inicializamos todos los vértices como no visitados
        previo[ i ] = -1;      //inicializamos el previo del vertice i con -1
    }
}

//Paso de relajacion
void relajacion( int actual , int adyacente , int peso ){
    //Si la distancia del origen al vertice actual + peso de su arista es menor a la distancia del origen al vertice adyacente
    if( distancia[ actual ] + peso < distancia[ adyacente ] ){
        distancia[ adyacente ] = distancia[ actual ] + peso;  //relajamos el vertice actualizando la distancia
        previo[ adyacente ] = actual;                         //a su vez actualizamos el vertice previo
        Q.push( Node( adyacente , distancia[ adyacente ] ) ); //agregamos adyacente a la cola de prioridad
    }
}

//Impresion del camino mas corto desde el vertice inicial y final ingresados
int print(int destino, Estacion estaciones[], string ruta[], int index){
    
    ruta[index] = estaciones[destino].nombre;
    index++;
    
    if( previo[ destino ] != -1 )//si aun poseo un vertice previo
        return 1 + print(previo[destino],estaciones,ruta,index);//recursivamente sigo explorando
    //printf("%d " , destino );//terminada la recursion imprimo los vertices recorridos
}

void dijkstra(int inicial, int destino, Estacion estaciones[], string ruta[], int index){
    init(); //inicializamos nuestros arreglos
    Q.push( Node( inicial , 0 ) ); //Insertamos el vértice inicial en la Cola de Prioridad
    distancia[ inicial ] = 0;      //Este paso es importante, inicializamos la distancia del inicial como 0
    int actual , adyacente , peso;
    while( !Q.empty() ){
        actual = Q.top().first;            //Obtengo de la cola el nodo con menor peso, en un comienzo será el inicial
        Q.pop();                           //Sacamos el elemento de la cola
        if( visitado[ actual ] ) continue; //Si el vértice actual ya fue visitado entonces sigo sacando elementos de la cola
        visitado[ actual ] = true;         //Marco como visitado el vértice actual

        for( int i = 0 ; i < ady[ actual ].size() ; ++i ){ //reviso sus adyacentes del vertice actual
            adyacente = ady[ actual ][ i ].first;   //id del vertice adyacente
            peso = ady[ actual ][ i ].second;        //peso de la arista que une actual con adyacente ( actual , adyacente )
            if( !visitado[ adyacente ] ){        //si el vertice adyacente no fue visitado
                relajacion( actual , adyacente , peso ); //realizamos el paso de relajacion
            }
        }
    }
    puts("\n************** Impresión de camino más corto **************");
    
    string o = estaciones[inicial].nombre;
    string d = estaciones[destino].nombre;
    cout << "Origen: " << o << " -> " << "Destino: " << d << endl;
    
    printf("\n");
    cout << "Ruta más directa: ";
    
    int indice = print(destino,estaciones,ruta,index);
    
    for(int j = indice + 1; 0 <= j; j--){
        if(ruta[j] != ruta[j+1]){
            cout << ruta[j];
            if(j != 0){
                cout << " - ";
            }
        }
    }
    printf("\n");
}

/* 
 * MAIN
 */
int main(int argc, char** argv) {
    MPI_Init(0,0);
    cout << "hello" << endl;
    MPI_Finalize();

    if (argc < 2){
	      cout << endl;
	      cout << "Forma de uso:" << endl;
	      cout << "Ver integrantes: ./programa -v" << endl;
	      cout << "Encontrar ruta más corta: ./programa -f [CODIGO_ESTACION_ORIGEN] [CODIGO_ESTACION_DESTINO]" << endl;
              cout << endl;
	         exit(1);
	    }
    
    string parametro = argv[1];
     
    if(parametro == "-v"){
        imprimir_autores();
    }
    
    else{
    
        if(parametro == "-f"){

            // Se declara el arreglo que contendrá las estaciones
            Estacion estaciones[cantidad_estaciones];

            // Se lee el archivo y se llena el arreglo
            int cantidad_lineas = cargar_archivo("archivo.txt",estaciones);

            int largo = cantidad_lineas;
            
            // Se muestran las estaciones
            //mostrar_estaciones(estaciones,largo);
            
            int peso = 1; // Se asume igual distancia entre estaciones
            
            // La cantidad de aristas es la cantidad de estaciones -1 por cada línea
            //int E = cantidad_estaciones - 6;
            
            int num_origen, num_destino;
            int num_inicial, num_final;

            // Se ingresan las estaciones guardadas para poder aplicar dijkstra
            for (int i = 1; i <= cantidad_lineas; i++){
                
                if(estaciones[i].adyacente != 0){

                    // Se guarda el número asignado a las estaciones
                    num_origen = estaciones[i].numero;
                    num_destino = estaciones[i].adyacente;

                    // Se incresan al vector
                    ady[ num_origen ].push_back( Node( num_destino , peso ) );
                    ady[ num_destino ].push_back( Node( num_origen , peso ) );
                }
                
                if(estaciones[i].combinacion != 0){
                    num_origen = estaciones[i].numero;
                    num_destino = estaciones[i].combinacion;
                    ady[ num_origen ].push_back( Node( num_destino , peso ) );
                    ady[ num_destino ].push_back( Node( num_origen , peso ) );
                }
            }
            
            num_inicial = buscar_indice(argv[2],estaciones,largo);
            num_final = buscar_indice(argv[3],estaciones,largo);
            
            string ruta[cantidad_estaciones];
            int index = 0;
            cout << endl;
            
            dijkstra(num_inicial,num_final,estaciones,ruta,index);
            
            cout << endl;
        }
        else{
               cout << endl;
               cout << "Argumentos incorrectos." << endl;
               cout << endl;
             }
    }
    return 0;
}