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
    int i=0;
    while(linea[i].nombre!=""){
        std::cout<< linea[i].nombre;
        if(linea[i+1].nombre!=""){
            cout << " - ";
        }
        i++;
    }
    cout << endl;
    /*for(i=0;i<118;i++)
    {
        std::cout<< linea[i].codigo<<"\n";
    }*/
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
/**
 * 
 * @param a Matriz de adyasencias de las estaciones
 * @param b Arreglo para buscar posicion de codigos en matriz
 * @param optimo Guarda el camino optimo encontrado
 * @param ruta Guarda la ruta actualmente en revision
 * @param ubicacion Posicionen la que actualmente se encuantra el programa
 * @param posicion_fin Pocision de la estacion final
 * @param largo Valor entero con cantidad de estaciones en la ruta
 * @param minimo El valor mas bajo de una ruta completa 
 */
void Ruta_R(estaciones a[][119],estaciones optimo[],estaciones ruta[],estaciones arreglo[],int ubicacion, int posicion_fin,int largo, int minimo, int combinaciones)
{
    std::string nodo_final = a[posicion_fin][posicion_fin+1].codigo;
    std::string nombre_nodo_final = a[posicion_fin][posicion_fin+1].nombre;
    int pos_com;
    std::string cod_siguiente;
    cod_siguiente = a[ubicacion][ubicacion +1].siguiente;
    while(cod_siguiente!="TERMINAL" or a[ubicacion][ubicacion+1].codigo==nodo_final)
    {
        //añade a la ruta el numero de pocicon de la estacion
        ruta[largo]=a[ubicacion][ubicacion+1];
        if(a[ubicacion][ubicacion+1].nombre==nombre_nodo_final)
        {
            if(largo<minimo)
            {
              optimo=ruta;
              std::cout << "Se ha encontrado una ruta en Ruta_R: ";
              mostrar_arreglo(ruta);
            }
        }
        if(a[ubicacion][ubicacion+1].combinacion!="0" and ruta[largo].combinacion!=a[ubicacion][ubicacion+1].codigo)
        {
            combinaciones++;
            if(combinaciones<=4)
            {
                pos_com=buscar_codigo(arreglo,a[ubicacion][ubicacion+1].combinacion);
                Ruta_C(a,optimo,ruta,arreglo,pos_com,posicion_fin,largo,minimo,combinaciones);
            }
        }
        cod_siguiente = a[ubicacion][ubicacion +1].siguiente;
        ubicacion++;
        largo++;

    }
}
void Ruta_L(estaciones a[][119],estaciones optimo[],estaciones ruta[],estaciones arreglo[],int ubicacion, int posicion_fin,int largo, int minimo, int combinaciones)
{
    std::string nodo_final = a[posicion_fin][posicion_fin+1].codigo;
    std::string nombre_nodo_final = a[posicion_fin][posicion_fin+1].nombre;
    int pos_com;
    std::string cod_anterior;
    cod_anterior = a[ubicacion][ubicacion +1].anterior;
    while(cod_anterior!="INICIO" or a[ubicacion][ubicacion+1].codigo==nodo_final)
    {
        ruta[largo]=a[ubicacion][ubicacion+1];
        if(a[ubicacion][ubicacion+1].nombre==nombre_nodo_final)
        {
            if(largo<minimo)
            {
              optimo=ruta;
              std::cout << "Se ha encontrado una ruta en Ruta_L: ";
              mostrar_arreglo(ruta);
            }
        }
        if(a[ubicacion][ubicacion+1].combinacion!="0" and ruta[largo].combinacion!=a[ubicacion][ubicacion+1].codigo)
        {
            combinaciones++;
            if(combinaciones<=4)
            {
                pos_com=buscar_codigo(arreglo,a[ubicacion][ubicacion+1].combinacion);
                Ruta_C(a,optimo,ruta,arreglo,pos_com,posicion_fin,largo,minimo,combinaciones);
            }
        }
        cod_anterior= a[ubicacion][ubicacion +1].anterior;
        ubicacion--;
        largo++;
    }
}
void viaje(estaciones a[][119], int posicion_ini, int posicion_fin)
{
    int largo = 0, minimo=99999;
    std::string nodo_inicial = a[posicion_ini][posicion_ini+1].codigo;
    std::string nombre_nodo_inicial = a[posicion_ini][posicion_ini+1].nombre;
    std::string nodo_final = a[posicion_fin][posicion_fin+1].codigo;
    std::string nombre_nodo_final = a[posicion_fin][posicion_fin+1].nombre;
    estaciones estacion[118];
    // SE LLENA EL ARREGLO CON LOS CÓDIGOS DE LAS ESTACIONES
    generar_arreglo(estacion);
    std::string cod_siguiente;
    std::string cod_anterior;
    
    cod_siguiente = a[posicion_ini][posicion_ini +1].siguiente;
    cod_anterior = a[posicion_ini][posicion_ini +1].anterior;
    
    //Se declara un arreglo de estructuras, que contendrá las estaciones que conforman el recorrido
    estaciones recorrido[200];
    estaciones optimo[200];
    int combinaciones=0;
    //Ruta_R recorre desde la estacion inicial hacia la derecha
    Ruta_R(a,optimo,recorrido,estacion,posicion_ini,posicion_fin,largo,minimo,combinaciones);
    Ruta_L(a,optimo,recorrido,estacion,posicion_ini,posicion_fin,largo,minimo,combinaciones);
    if(a[posicion_ini][posicion_ini +1].combinacion!="0")
    {
        combinaciones++;
        //Ruta_C llama Ruta_R y Ruta_L desde la estacion de combinacion en al sisuiente linea
        int comb;
        std::string cod_com;
        cod_com = a[comb][comb +1].siguiente;
    }
    //mostrar_arreglo(optimo);
}
void Ruta_C(estaciones a[][119],estaciones optimo[],estaciones ruta[],estaciones arreglo[],int ubicacion, int posicion_fin,int largo, int minimo, int combinaciones)
{
    std::string siguiente = a[ubicacion][ubicacion+1].combinacion;
    int ubicacionc = buscar_codigo(arreglo,siguiente);
    Ruta_R(a,optimo,ruta,arreglo,ubicacionc,posicion_fin,largo,minimo,combinaciones);
    Ruta_L(a,optimo,ruta,arreglo,ubicacionc,posicion_fin,largo,minimo,combinaciones);
    
}
/*
void buscar_camino(estaciones a[][119], estaciones b[], int posicion_ini, int posicion_fin)
{
        //int l1=0,l2=0,l3=0,l4=0,l5=0,l6=0,dir=1;
        //SE GUARDAN LOS CÓDIGOS DE LAS ESTACIONES DE INICIO Y FIN
	std::string nodo_inicial = a[posicion_ini][posicion_ini+1].codigo;
        std::string nombre_nodo_inicial = a[posicion_ini][posicion_ini+1].nombre;
	std::string nodo_final = a[posicion_fin][posicion_fin+1].codigo;
        
	std::string pos_encontrada;
        std::string nombre_pos_encontrada;
	std::string cod_siguiente;
        std::string cod_anterior;
        
	cod_siguiente = a[posicion_ini][posicion_ini +1].siguiente;
        cod_anterior = a[posicion_ini][posicion_ini +1].anterior;
        
        //Se declara un arreglo de estructuras, que contendrá las estaciones que conforman el recorrido
	estaciones recorrido[200];
        
        //EL RECORRIDO PARTE CON LA ESTACIÓN DE INICIO
	recorrido[0].codigo=nodo_inicial;
        recorrido[0].nombre=nombre_nodo_inicial;

        int fin = 0;
        int dir=1;
        int pos;
        int i=1;
        
	while(fin !=1)
	{
            if(dir==1)
            {
                //SE BUSCA EL NÚMERO DE LA ESTACIÓN SIGUIENTE
		pos = buscar_posicion(b,cod_siguiente);
                //SE GUARDA EL CÓDIGO DE LA ESTACIÓN SIGUIENTE
		pos_encontrada = a[pos][pos+1].codigo;
                nombre_pos_encontrada = a[pos][pos+1].nombre;
                
		if(pos_encontrada == nodo_final)
		{
			fin=1;
		}
                //SI LA ESTACIÓN SIGUIENTE ES ADEMÁS UN TERMINAL
		if(a[pos][pos+1].siguiente == "TERMINAL")
		{
			i=1;
                        dir=0;
                        //AHORA EMPIEZA A BUSCAR EN LA OTRA DIRECCIÓN DE LA LÍNEA
			cod_anterior = a[posicion_ini][posicion_ini+1].anterior;
		}
		else
		{
			recorrido[i].codigo = pos_encontrada;
                        recorrido[i].nombre = nombre_pos_encontrada;
			cod_siguiente = a[pos][pos+1].siguiente;
		}
		i=i+1;
            }
            else
            {
		//std::cout << "comienza busqueda hacia atras"<<" cod: "<<cod_anterior <<endl;
                pos = buscar_posicion(b,cod_anterior);
		pos_encontrada = a[pos][pos+1].codigo;
                //break;
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
			//std::cout <<"pos: " <<pos <<" pos_encontrada" << pos_encontrada << " cod_anterior" << cod_anterior<<endl;
			recorrido[i].codigo = pos_encontrada;
			cod_anterior = a[pos-1][pos].anterior;
		}
		i=i+1;
            }
	}
        cout << endl;
	for(int j=0; j<i;j++)
	{
		std::cout << recorrido[j].nombre;
                if(j+1<i){
                    cout << " - ";
                } 
	}
        cout << endl;
}*/