/* 
 * File:   main.cpp
 * Author: Daniel Espinoza
 *
 * Created on 18 de agosto de 2018, 22:06
 */
#include "Funciones.h"


/*
 * 
 */
int main(int argc, char** argv) {
    
    // SE DELARA UN ARREGLO DE ESTRUCTURAS
    estaciones estacion[118];
    // SE LLENA EL ARREGLO CON LOS CÓDIGOS DE LAS ESTACIONES
    generar_arreglo(estacion);
    
    //SE DECLARA UNA MATRIZ DE ESTACIONES
    estaciones lineas[119][119];
    
    generar_matriz(lineas);
    	
    std::cout << "\nLa matriz es: \n";
    mostrar_matriz(lineas);
    std::cout << "\n\n";
    
    
    if (argc < 2){
         cout << endl;
         cout << "Forma de uso:" << endl;
         cout << "Ver integrantes: ./programa -v" << endl;
         cout << "Encontrar ruta más corta: ./programa -f [CODIGO_ESTACION_ORIGEN] [CODIGO_ESTACION_DESTINO]" << endl;
         cout << endl;
            exit(1);
       }
     char* parametro = argv[1];
        if(strcmp(parametro,"-v") == 0){
         imprimir_autores();
	     }
	else{
	     if(strcmp(parametro,"-f") == 0){
                //ARGUMENTOS DE ENTRADA
                char* estacion_origen = argv[2];
                char* estacion_destino = argv[3];
                
                //COLUMNAS DONDE SE UBICAN LAS ESTRUCTURAS DE LAS ESTACIONES
                int posicion_ini = buscar_posicion(estacion,estacion_origen);
                int posicion_fin = buscar_posicion(estacion,estacion_destino);
                
                //SEÑALA PUNTO DE PARTIDA Y DE DESTINO
                cout << "INICIO: " << lineas[posicion_ini][posicion_ini +1].nombre << endl;
                cout << "FIN: " << lineas[posicion_fin][posicion_fin +1].nombre << endl;
                    
                viaje(lineas,posicion_ini ,posicion_fin );

	            }
	 else{
	        cout << endl;
	        cout << "Argumentos incorrectos." << endl;
	        cout << endl;
	      }
	  }
    
}

