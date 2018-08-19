/* 
 *  * File:   funciones.cpp
 *   * Author: Daniel Espinoza
 *    * 
 *     * Created on 18 de agosto de 2018, 22:06
 *      */

#include "Funciones.h"

void agregar_Nodo(std::string a,std::string b,Lista &linea)
{
    Lista estac ;
    estac = new estaciones;
    estac->codigo = a;
    estac->nombre = b;
    estac->link=linea;
    linea = estac;
   /* std::cout  << "\n agregando nombre: "<<b;
    std::cout  << "\n agregando codigo: "<< a << "\n";*/
}
void generar_lista(std::string linea,Lista &lineas)
{
    std::string estacion;
    std::string partOne;
    std::string partTwo;
   
    ifstream archivo;
    //const char* delims = ";";
    archivo.open("linea"+linea+".txt");
    if (!archivo) {
            cerr << "No se pudo abrir el archivo linea"+linea+".txt";
            exit(1);   // detenerse y salir
        }
    while(getline(archivo,estacion)){
            
        size_t f = estacion.find(";"); 
        partOne = estacion.substr(0,f);
        partTwo = estacion.substr(f+1,estacion.size());
        agregar_Nodo(partOne,partTwo,lineas);
        //std::cout << partOne << ";;;;"<< partTwo<< endl;
        }
        
        archivo.close();
}
void ver_lista(Lista l)
{
    Lista p;
    p=l;
    if(p==NULL)
        cout<<"no existen estaciones";
    else
        {
            while(p->link!=NULL)
            {
              
                std::cout << "nombre: "<< p->nombre;
                std::cout <<"\n codigo: "<< p->codigo<<"\n";
                p=p->link;
            }
        }

}
