#include "pacient.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int time_unit = 0;
    Pacients *list_meliants = create_meliants();
    
    while (time_unit < 73000)
    {
        int gen_pacient_chance = gen_randint(0, 100);
        if (gen_pacient_chance <= 20)
        {
            Pacient *pacient = create_meliant(time_unit);
            meliant_insert(list_meliants ,pacient);
            int size_meliants = list_size(list_meliants);
            printf("%d\n", size_meliants);
        } 
        time_unit++;
    }

}