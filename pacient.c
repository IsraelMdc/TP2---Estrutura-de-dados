#include "pacient.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct paciente
{
    char name[50];
    char cpf[12];
    int age;
    int id;
    int t_in;
    int t_out;
};

struct pacientes
{   
    int n;// quanditdade de meliantes 
    int n_max;// capacidade total de meliantes
    Pacients **meliants;//vetor de meliantes
};


int gen_randint(int initial_number, int final_number)
{
    return initial_number + rand()%(final_number - initial_number + 1);
}

int gen_age()
{    
    return gen_randint(0,100);
};

void gen_cpf(Pacient *pacient)
{
    for (int i = 0; i < 11 ; i++)
    {
        pacient->cpf[i] = gen_randint('0','9');
    }
    pacient->cpf[11] = "\0";
};

void gen_name(Pacient *pacient)
{
    pacient->name[0] = gen_randint('A','Z');
    for (int i = 1; i < 50 ; i++)
    {
        pacient->name[i] = gen_randint('a','z');
    }
    pacient->cpf[50] = "\0";
}

Pacients *v_meliants()
{
   Pacients * v_meliants= (Pacients *)malloc(sizeof(Pacients)); // Allocate memory for the DynVec structure

   v_meliants->n = 0;                                          // Initialize the number of elements to 0
   v_meliants->n_max = 4;                                      // Allocate initially space for 4 elements
   Pacient**meliants = (Pacients **)malloc(v_meliants->n_max * sizeof(Pacients)); // Allocate memory for the vector data

   return v_meliants; // Return a pointer to the created dynamic vector
}

Pacient *create_meliant(int t_in)
{
    static int id = 1;
    Pacient *pacient = (Pacient *)malloc(sizeof(Pacient));
    gen_name(pacient);
    pacient->age = gen_age();
    gen_cpf(pacient);
    pacient->id = id++;
    pacient->t_in = t_in;
    pacient->t_out = 0;
    return pacient;
};

static void reallocate(Pacients *v_meliants)
{
   v_meliants->n_max *= 2;                                             // Double the capacity
   v_meliants->meliants = (float *)realloc(v_meliants->meliants, v_meliants->n_max * sizeof(float)); // Reallocate memory for the vector data
}


void meliant_insert(Pacients *v_meliants, Pacient *pacient)
{
   // Check if the capacity is enough, and if not, reallocate memory
   if (v_meliants->n == v_meliants->n_max)
      reallocate(v_meliants);

   v_meliants->meliants[v_meliants->n++] = pacient; // Insert the value and increment the size
}
