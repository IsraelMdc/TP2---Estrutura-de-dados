#ifndef PACIENT_H
#define PACIENT_H

typedef struct pacientes Pacients;
typedef struct paciente Pacient;

Pacient *create_meliant(int t_in);

Pacients *create_meliants();

void meliant_insert(Pacients *meliants, Pacient *pacient);

int list_size(Pacients *meliants);

int gen_randint(int initial_number, int final_number);

void print_pacient(Pacient *pacient);

void print_lista_pacientes(struct pacientes *list_pacients);

#endif