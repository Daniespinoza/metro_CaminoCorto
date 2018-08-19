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
     * @param link Enlace con la siguiente estación.
     */
struct estaciones {
        std::string nombre;
        std::string codigo;
        std::string  combinacion;
        struct estaciones *link;
        };
        typedef estaciones *Lista;


/**
     * Lee el archivo .txt de la línea de metro y crea una lista enlazada, donde cada nodo corresponde a una estación.
     * @param linea String con el número de la línea.
     * @param Linea Objeto vacío de tipo Lista.
     * @return Esta función no retorna.
     */
void generar_lista(std::string, Lista &);

/**
     * Agrega la información de la estación a una estructura de datos y esta es agregada como un nodo a la lista.
     * @param nombre Nombre de la estación.
     * @param codigo Código de la estación.
     * @param combinación La línea a la que se puede combinar desde esta estación.
     * @param lista La lista a la que se agregará el nodo.
     * @return Esta función no retorna.
     */
void agregar_Nodo(std::string,std::string,std::string,Lista &);

/**
     * Imprime por pantalla la información de cada estación de la línea.
     * @param lista Lista de la línea de metro que contiene las estaciones.
     * @return Esta función no retorna.
     */
void ver_lista(Lista l);

/**
     * Identifica si el codigo pertenece a la estación ingresada.
     * @param l Linea a revisar.
     * @param cod Código de la estacion a buscar.
     * @return Retorna 1 si la estación pertenece a la línea.
 */
int busca_estacion(Lista , string);

/**
     * Imprime los nombres de los autores de la aplicación.
     * @param Esta función no tiene parámetros.
     * @return Esta función no retorna.
     */
void imprimir_autores();

#endif /* FUNCIONES_H */
