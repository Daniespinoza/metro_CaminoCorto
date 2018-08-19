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
    
    //std::string lineas[6] = {"1","2","4","4a","5","6"};
    
    generar_lista("1",Linea1);
    generar_lista("2",Linea2);
    generar_lista("4",Linea4);
    generar_lista("4a",Linea4a);
    generar_lista("5",Linea5);
    generar_lista("6",Linea6);
    
    /*for(int i = 0; i < 6; i++)
    {
        //std::string lista = "Linea"+lineas[i];
        string numero_linea = lineas[i];
        
        if(numero_linea == "1"){
            generar_lista(numero_linea,Linea1);
        }
            
        if(numero_linea == "2"){
            generar_lista(numero_linea,Linea2);
        }
            
        if(numero_linea == "4"){
            generar_lista(numero_linea,Linea4);
        }
            
        if(numero_linea == "4a"){
            generar_lista(numero_linea,Linea4a);
        }
            
        if(numero_linea == "5"){
            generar_lista(numero_linea,Linea5);
        }
            
        if(numero_linea == "6"){
            generar_lista(numero_linea,Linea6);
        }
    }
    */
    ver_lista(Linea1);
    ver_lista(Linea2);
    ver_lista(Linea4);
    ver_lista(Linea4a);
    ver_lista(Linea5);
    ver_lista(Linea6);
    
    return 0;
}

