/* 
 *  * File:   funciones.cpp
 *   * Author: Daniel Espinoza
 *    * 
 *     * Created on 18 de agosto de 2018, 22:06
 *      */

#include "Funciones.h"


void imprimir_autores(){
    cout << endl;
    cout << "Aplicación desarrollada por:" << endl;
    cout << "- Nicolás Cortés." << endl;
    cout << "- Rodrigo Echeverría." << endl;
    cout << "- Daniel Espinoza." << endl;
    cout << endl;
}



void generar_arreglo(estaciones linea[])
{
    std::string estacion;
    std::string cod;
    
    ifstream archivo;
    //const char* delims = ";";
    archivo.open("linea.txt");
    if (!archivo) {                                                                                                                                                                                                     
            cerr << "No se pudo abrir el archivo linea.txt";
            exit(1);   // detenerse y salir
        }
    int i=0;
    while(getline(archivo,estacion)){
        size_t puntoYcoma = estacion.find(";");
        cod = estacion.substr(0,puntoYcoma);

        linea[i].codigo = cod; 
        i++;
    }
}
void generar_matriz(estaciones linea[][119])
{
    std::string estacion;
    std::string cod;
    std::string name;
    std::string termi;
    std::string combi;
    std::string str1="1";
    std::string str2="2";
    int x;
    estaciones estacione[118];
    generar_arreglo(estacione);

    ifstream archivo;
    //const char* delims = ";";
    archivo.open("linea.txt");
    if (!archivo) {                                                                                                                                                                                                     
            cerr << "No se pudo abrir el archivo linea.txt";
            exit(1);   // detenerse y salir
        }
    int i=0,j=1;
    while(getline(archivo,estacion)){
	if(j==119)
		j=0;
        size_t puntoYcoma = estacion.find(";");
        size_t comilla = estacion.find("'");
        size_t arroba = estacion.find("@");
	name = estacion.substr(puntoYcoma+1,comilla-puntoYcoma-1);
        cod = estacion.substr(0,puntoYcoma);
        combi = estacion.substr(comilla+1,arroba-comilla-1);
        termi = estacion.substr(arroba+1,estacion.size()-1);
	x = std::atoi(termi.c_str());
        if(j==i+1)
        {
            linea[i][j].codigo = cod;
            linea[i][j].nombre = name;
	    linea[i][j].combinacion = combi;

            if(x==1 )
            {
                linea[i][j].siguiente = "TERMINAL";
                linea[i][j].anterior = linea[i-1][j-1].codigo;
            }
            else
            {
                if(x == 2 )
                {
                    linea[i][j].siguiente = estacione[i+1].codigo;
                    linea[i][j].anterior = "INICIO";
                }
                else
                {
                    linea[i][j].siguiente = estacione[i+1].codigo;
                    linea[i][j].anterior = linea[i-1][j-1].codigo;
                }
            }
	    std::cout<< "guardando....." <<linea[i][j].codigo << " " << linea[i][j].nombre << " " << linea[i][j].siguiente << " "<< linea[i][j].anterior<<"\n";
            i++;
	    j=i+1;
        }
        else
        {
		if(j==118 && i==118)		
		{

		}

            j++;
        }
     
        
    }
    
}

void mostrar_arreglo(estaciones linea[])
{
    int i;
    for(i=0;i<118;i++)
    {
        std::cout<< linea[i].codigo<<"\n";
    }
}


void mostrar_matriz(estaciones linea[][119])
{
    int i;
    for(i=0;i<119;i++)
    {
        for(int j=0; j<119;j++)
        {
		if(j==i+1){
                std::cout<< linea[i][j].nombre<<"";
                std::cout<<"   " <<linea[i][j].anterior<<"";
                std::cout<<"  " <<linea[i][j].codigo<<"";
                std::cout<< "  "<< linea[i][j].siguiente<<"";
		std::cout<<"  " <<linea[i][j].combinacion<<"\n";
		}
        }
        
    }
}
