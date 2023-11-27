#include "machine.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct machine
{
    //0 máquina disponível e 1 máquina ocupada
    int is_ocuppied;
    //numero de identificação da máquina
    int id_machine;
};

struct machines_status
{
    int n;                            // quantidade de maquinas 
    int n_free;                       // quantidade de maquinas livres
    int n_max = 5;                    // capacidade total de maquinas
    
    struct machine **machines_vector; // vetor de meliantes

};
