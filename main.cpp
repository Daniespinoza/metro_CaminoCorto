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
   
    estaciones lineas[119][119];

    generar_matriz(lineas);

    std::cout << "la matriz es: \n";
   mostrar_matriz(lineas);


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
	         /*char* estacion_origen = argv[2];
		  *             char* estacion_destino = argv[3];*/
	         /*¿funcion_magica_que_resuelve_todo(estacion_origen,estacion_destino)?*/
	            }
	 else{
	        cout << endl;
	        cout << "Argumentos incorrectos." << endl;
	        cout << endl;
	      }
	  }
    
}

