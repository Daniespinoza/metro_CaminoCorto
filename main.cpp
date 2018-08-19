/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Daniel Espinoza
 *
 * Created on 18 de agosto de 2018, 22:06
 */
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include "Funciones.cpp"
#include "Funciones.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

	std::string lineas[6] = {"1","2","4","4a","5","6"};
	std::string estacion;
        char delims[] =";";
    	ifstream archivo;
    for(int i = 0 ; i < 6 ; i++){

        archivo.open("linea"+lineas[i]+".txt");
        
        if (!archivo) {
            cerr << "No se pudo abrir el archivo linea"+lineas[i]+".txt";
            exit(1);   // detenerse y salir
        }
        
        while(getline(archivo,estacion)){
            
          /*  char *separados =strtok(estacion, delims);
            
            while(separados!=NULL){
              cout << separados; 
            }*/
            cout << estacion << endl;  
            
        }
        
        archivo.close();
        
    }
    
    
    
    return 0;
}

