/* 
 *  * File:   funciones.cpp
 *   * Author: Daniel Espinoza
 *    * 
 *     * Created on 18 de agosto de 2018, 22:06
 *      */

#include "Funciones.h"

void agregar_Nodo(std::string a,std::string b,std::string c,Lista &linea)
{
    Lista estac ;
    estac = new estaciones;
    estac->codigo = a;
    estac->nombre = b;
    estac->combinacion = c;
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
    std::string partThree;
   
    ifstream archivo;
    //const char* delims = ";";
    archivo.open("linea"+linea+".txt");
    if (!archivo) {
            cerr << "No se pudo abrir el archivo linea"+linea+".txt";
            exit(1);   // detenerse y salir
        }
    while(getline(archivo,estacion)){
            
        size_t f = estacion.find(";");
        size_t fin = estacion.find("'");
        partOne = estacion.substr(0,f);
        partTwo = estacion.substr(f+1,fin);
        partThree = estacion.substr(fin+1,estacion.size());
        agregar_Nodo(partOne,partTwo,partThree,lineas);
        //std::cout << partOne << ";;;;"<< partTwo<< ";;;;"<<partThree<<endl;
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
                std::cout <<"\n codigo: "<< p->codigo;
                std::cout <<"\n Combinacion linea: "<< p->combinacion<<"\n";
                p=p->link;
            }
        }

}
/**
 * Identifica si el codigo pertenece a la estacino ingresada
 * @param l Linea a arevisar
 * @param cod Codigo de la estacion que buscamos
 * @return regresa un 1 si la estacion pertenece a la linea
 */
int busca_estacion(Lista l, string cod)
{
    int res=0;
    Lista p;
    p=l;
    if(p==NULL)
        cout<<"no existen estaciones";
    else
        {
            while(p->link!=NULL)
            {
                if(cod==p->codigo)
                {
                    res=1;
                }
                p=p->link;
            }
        }
    return res;
}
/**
 * Regresa la lista que continen  la estacion de origen
 * @param cod Codigo de la estacion de origen
 * @param a
 * @param b
 * @param c
 * @param d
 * @param e
 * @param f
 * @return Retorna la lista donde esta el inicio del recorrido
 */

