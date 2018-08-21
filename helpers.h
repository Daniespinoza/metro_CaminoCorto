#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR 100
#define MAX_ADJ 10
#define MAX_STATIONS 250

struct Station {
    char name[MAX_STR];
    char code[MAX_STR];
    struct Station *adj[MAX_ADJ];
    int n_adj;
    
    // useful for djikstra
    int dist;
    int closed;
    struct Station *prev;
};

typedef struct Station Station;

void imprimir_autores();

/*
 * Returns a COPY of the string converted to lowercase.
 * Does not free the original string!
 */
char *strtolow(char *string);


void print_station(Station *station);

/*
 * Loads the map from "filename" as a graph of Stations.
 * Returns a the number of stations it has read.
 * Stores references to all the stations it read in list[].
 */
int load_map(Station **list, const char *filename);