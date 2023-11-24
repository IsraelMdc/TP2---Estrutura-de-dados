#include "pacient.h"
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int time_unit = 0;
    Pacients *list_meliants = create_meliants();
    
    while (time_unit < 43200)
    {
        int gen_pacient_chance = gen_randint(0, 100);
        if (gen_pacient_chance <= 20)
        {
            Pacient *pacient = create_meliant(time_unit);
            meliant_insert(list_meliants ,pacient);

        } 
        
        time_unit++;
    }
    

    
}