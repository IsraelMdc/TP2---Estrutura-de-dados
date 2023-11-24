#include "xray.h"
#include <stdio.h>
#include <stdlib.h>


struct paciente
{
    char nome[50];
    int cpf;
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


int gen_idade()
{


    return idade;
};

int gen_cpf()
{


    return cpf;
};


PACIENTES *dv_create()
{
   PACIENTES *dv = (PACIENTES *)malloc(sizeof(PACIENTES)); // Allocate memory for the DynVec structure

   dv->n = 0;                                          // Initialize the number of elements to 0
   dv->n_max = 4;                                      // Allocate initially space for 4 elements
   PACIENTE**meliantes = (float *)malloc(dv->n_max * sizeof(float)); // Allocate memory for the vector data

   return dv; // Return a pointer to the created dynamic vector
}

PACIENTE * cria_meliante(int t_entrada)
{
    static int id = 1;
    PACIENTE *pacient = (PACIENTE *)malloc(sizeof(PACIENTE));
    pacient->idade = gen_idade();//func randint
    pacient->cpf = gen_cpf();
    pacient->id = id++;
    pacient->t_entrada = t_entrada;
    pacient->t_saida = 0;
    return pacient;
};

PACIENTES* lista_meliantes()
{
    PACIENTES **lista_pacientes = (PACIENTE **)malloc(sizeof(PACIENTES));

};