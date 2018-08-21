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
//	    std::cout<< "guardando....." <<linea[i][j].codigo << " " << linea[i][j].nombre << " " << linea[i][j].siguiente << " "<< linea[i][j].anterior<<"\n";
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

int buscar_posicion(estaciones a[], std::string cod)
{
	int pos;
	std::string codigo;
	for(pos=0; pos<118; pos++)
	{
		codigo = a[pos].codigo;
		if(codigo.compare(cod)==0)
		{
			return pos;
		}

	}
	return -1;
}
int buscar_codigo(estaciones a[], std::string name)
{
	        int pos;
	        std::string nombre;
	        for(pos=0; pos<118; pos++)
		 {
		      nombre = a[pos].nombre;
	             if(nombre.compare(name)==0)
	             {
	        	  return pos;												
		      } 
                 }
		return -1;
}
void buscar_camino(estaciones a[][119], estaciones b[], int posicion_ini, int posicion_fin)
{
//        int l1=0,l2=0,l3=0,l4=0,l5=0,l6=0,dir=1;
	int dir=1;
	int fin = 0;
	int pos;
	estaciones recorrido[200];
	int i=1;
	std::string nodo_inicial = a[posicion_ini][posicion_ini+1].codigo;
	std::string nodo_final = a[posicion_fin][posicion_fin+1].codigo;
	std::string pos_encontrada;
	std::string cod_siguiente;
        std::string cod_anterior;
	cod_siguiente = a[posicion_ini][posicion_ini +1].siguiente;
        cod_anterior = a[posicion_ini][posicion_ini +1].anterior;
	recorrido[0].codigo=nodo_inicial;	
	while(fin !=1)
	{
            if(dir==1)
            {
		pos = buscar_posicion(b,cod_siguiente);
		pos_encontrada = a[pos][pos+1].codigo;
		if(pos_encontrada == nodo_final)
		{
			fin=1;
		}
		if(a[pos][pos+1].siguiente == "TERMINAL")
		{
			i=1;
                        dir=0;
			cod_anterior = a[posicion_ini][posicion_ini+1].anterior;
		}
		else
		{
			recorrido[i].codigo = pos_encontrada;
			cod_siguiente = a[pos][pos+1].siguiente;
		}
		i=i+1;
            }
            else
            {
		std::cout << "comienza busqueda hacia atras"<<" cod: "<<cod_anterior <<endl;
                pos = buscar_posicion(b,cod_anterior);
		pos_encontrada = a[pos][pos+1].codigo;
	//	break;
		if(pos_encontrada == nodo_final)
		{
			fin=1;
		}
		if(a[pos][pos-1].anterior == "INICIO")
		{
			i=1;
                        dir=1;
			cod_siguiente = a[posicion_ini][posicion_ini+1].siguiente;
		}
		else
		{
			std::cout <<"pos: " <<pos <<" pos_encontrada" << pos_encontrada << " cod_anterior" << cod_anterior<<endl;
			recorrido[i].codigo = pos_encontrada;
			cod_anterior = a[pos-1][pos].anterior;
		}
		i=i+1;
            }
	}
	for(int j=0; j<i;j++)
	{
		std::cout << recorrido[j].codigo << "-";
	}


}

