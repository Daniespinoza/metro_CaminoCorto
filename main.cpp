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

    Lista Linea1 = NULL;
    Lista Linea2 = NULL;
    Lista Linea4 = NULL;
    Lista Linea4a = NULL;
    Lista Linea5 = NULL;
    Lista Linea6 = NULL;
    
    generar_lista("1",Linea1);
    generar_lista("2",Linea2);
    generar_lista("4",Linea4);
    generar_lista("4a",Linea4a);
    generar_lista("5",Linea5);
    generar_lista("6",Linea6);
    
    /*MUESTRA LAS ESTACIONES DE CADA LINEA
    ver_lista(Linea1);
    ver_lista(Linea2);
    ver_lista(Linea4);
    ver_lista(Linea4a);
    ver_lista(Linea5);
    ver_lista(Linea6);
    */
    
    /*PROBANDO QUE SOLO MUESTRE LA LINEA QUE POSEA EL CÓDIGO CER
    string cod="CER";
    Lista aux;
    if(busca_estacion(Linea1,cod)==1)
    {
        aux=Linea1;
    }
    if(busca_estacion(Linea2,cod)==1)
    {
        aux=Linea2;
    }
    if(busca_estacion(Linea4,cod)==1)
    {
        aux=Linea4;
    }
    if(busca_estacion(Linea4a,cod)==1)
    {
        aux=Linea4a;
    }
    if(busca_estacion(Linea5,cod)==1)
    {
        aux=Linea5;
    }
    if(busca_estacion(Linea6,cod)==1)
    {
        aux=Linea6;
    }

    ver_lista(aux);
    */
    
    char* parametro = argv[1];
    
    if(strcmp(parametro,"-v") == 0){
        cout << "Aplicación desarrollada por:" << endl;
        cout << "- Nicolás Cortés." << endl;
        cout << "- Rodrigo Echeverría." << endl;
        cout << "- Daniel Espinoza." << endl;
    }
            
    return 0;
}

