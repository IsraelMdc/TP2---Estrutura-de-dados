#include "xray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct paciente
{
    char nome[50];
    char cpf[12];
    int idade;
    int id;
    int t_entrada;
    int t_saida;
};

struct pacientes
{   
    int n;// quanditdade de meliantes 
    int n_max;// capacidade total de meliantes
    PACIENTE **meliantes;//vetor de meliantes
};


int gen_randint(int initial_number, int final_number)
{
    return initial_number + rand()%(final_number - initial_number + 1);
}

int gen_idade()
{    
    return gen_randint(0,100);
};

void gen_cpf(PACIENTE *pacient)
{
    char v[11];  
    for (int i = 0; i < 11 ; i++)
    {
        v[i] = gen_randint('0','9');
    }
    v[11] = "\0";
    strcpy(pacient->cpf, v);
};


PACIENTES *lista_meliantes()
{
   PACIENTES *dv = (PACIENTES *)malloc(sizeof(PACIENTES)); // Allocate memory for the DynVec structure

   dv->n = 0;                                          // Initialize the number of elements to 0
   dv->n_max = 4;                                      // Allocate initially space for 4 elements
   PACIENTE**meliantes = (PACIENTES **)malloc(dv->n_max * sizeof(PACIENTES)); // Allocate memory for the vector data

   return dv; // Return a pointer to the created dynamic vector
}

PACIENTE * cria_meliante(int t_entrada)
{
    static int id = 1;
    PACIENTE *pacient = (PACIENTE *)malloc(sizeof(PACIENTE));
    pacient->idade = gen_idade();//func randint
    gen_cpf(pacient);
    pacient->id = id++;
    pacient->t_entrada = t_entrada;
    pacient->t_saida = 0;
    return pacient;
};
