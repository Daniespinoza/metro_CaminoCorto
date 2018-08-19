/*
 *  * To change this license header, choose License Headers in Project Properties.
 *   * To change this template file, choose Tools | Templates
 *    * and open the template in the editor.
 *     */

/* 
 *  * File:   funciones.h
 *   * Author: Daniel Espinoza
 *    *
 *     * Created on 18 de agosto de 2018, 22:06
 *      */

#include <string>
#include <regex>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


#ifndef FUNCIONES_H
#define FUNCIONES_H
/**
     * 
     * @param Estructura de estaciones
     */
struct estaciones {
        std::string nombre;
        std::string codigo;
        std::string  combinacion;
        struct estaciones *link;
        };
        typedef estaciones *Lista;


/**
     * 
     * @param linea{PARAMETER}.txt, Lista
     * @return genera lista con archivos txt
     */
void generar_lista(std::string, Lista &);
/**
     * 
     * @param nombre, codigo , lista
     * @return agrega nodo a lista
     */
void agregar_Nodo(std::string,std::string,std::string,Lista &);
/**
     * 
     * @param lista
     * @return visualizar lista
     */
void ver_lista(Lista l);

int busca_estacion(Lista , string);



#endif /* FUNCIONES_H */
