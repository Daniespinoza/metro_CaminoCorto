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
     * Estructura de datos con la información de una estación.
     * @param nombre Nombre de la estación.
     * @param codigo Código de la estación.
     * @param combinacion Línea con la que combina.
     * @param anterior Enlace con la estación anterior.  
     * @param link Enlace con la siguiente estación.
     */
struct estaciones {
        std::string nombre;
        std::string codigo;
        std::string  linea;
	std::string combinacion;
        std::string siguiente;
        std::string anterior;
        };
/**
     * Estructura de datos con la información de una estación.
     * @param nombre Nombre de la estación.
     * @param codigo Código de la estación.
     * @param combinacion Línea con la que combina.
     */
        void generar_matriz(estaciones [][119]);
        
/**
     * Estructura de datos con la información de una estación.
     * @param nombre Nombre de la estación.
     * @param codigo Código de la estación.
     * @param combinacion Línea con la que combina.
     */        
        void generar_arreglo(estaciones []);
/**
     * Estructura de datos con la información de una estación.
     * @param nombre Nombre de la estación.
     * @param codigo Código de la estación.
     * @param combinacion Línea con la que combina.
     */                
        void mostrar_arreglo(estaciones []);
        
/**
     * Estructura de datos con la información de una estación.
     * @param nombre Nombre de la estación.
     * @param codigo Código de la estación.
     * @param combinacion Línea con la que combina.
     */                        
        void mostrar_matriz(estaciones [][119]);
/**
 *      * Estructura de datos con la información de una estación.
 *           * @param nombre Nombre de la estación.
 *                * @param codigo Código de la estación.
 *                     * @param combinacion Línea con la que combina.
 *                          */
	void imprimir_autores();

/**
 *  *      * Estructura de datos con la información de una estación.
 *   *           * @param nombre Nombre de la estación.
 *    *                * @param codigo Código de la estación.
 *     *                     * @param combinacion Línea con la que combina.
 *      *                          */

	int buscar_posicion(estaciones [], std::string);
/**     
 *  *  *      * Estructura de datos con la información de una estación.
 *   *   *           * @param nombre Nombre de la estación.
 *    *    *                * @param codigo Código de la estación.
 *     *     *                     * @param combinacion Línea con la que combina.
 *      *      *                          */

	int buscar_codigo(estaciones [], std::string);


/**     
 *  *  *      * Estructura de datos con la información de una estación.
 *   *   *           * @param nombre Nombre de la estación.
 *    *    *                * @param codigo Código de la estación.
 *     *     *                     * @param combinacion Línea con la que combina.
 *      *      *                          */

	void buscar_camino(estaciones [][119], estaciones [], int , int );
#endif /* FUNCIONES_H */
