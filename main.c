#include "pacient.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int time_unit = 0;
    //criação da lista de pacientes(meliants)
    Pacients *list_meliants = create_meliants();
    
    //43200 unidades totais
    while (time_unit < 50)
    {
        //geração de aleatoriedade entre 1 em 100
        int gen_pacient_chance = gen_randint(0, 100);
        //verificação se a variável de aletoriedade é maior que 20
        if (gen_pacient_chance <= 20)
        {
            //criação do paciente(meliante)
            Pacient *pacient = create_meliant(time_unit);

            //print_pacient(pacient);

            //inserção do paciente ao vetor de pacientes (meliante vai pra dentro da lista de meliantes)
            meliant_insert(list_meliants ,pacient);

            //print do tamanho da lista de meliantes
            int size_meliants = list_size(list_meliants);
            printf("quantidade de pacientes atuais: %d\n", size_meliants);
        } 
        
        time_unit++;
    }
    print_lista_pacientes(list_meliants);
}