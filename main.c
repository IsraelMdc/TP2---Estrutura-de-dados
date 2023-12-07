#include "pacient.h"
#include "machine.h"
#include "exam.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //Declaración e inicialización de elementos contadores.
    int time_unit = 0;
    int count_show=0;
    int machine_quantity = 5;
    int laud_medium_time=0;
    int helth_time=0;
    int helth_cont=0;
    int bronkaite_time=0;
    int bronkaite_cont=0;
    int peneu_time=0;
    int peneu_cont=0;
    int femur_broken_time = 0;
    int femur_broken_cont=0;
    int aprendeu_time=0;
    int aprendeu_cont=0;

    //Declaración e inicialización de estructuras.
    Pacients *list_meliants = create_meliants();
    MachineList *machine_list_create = create_machine_list();
   
    ExameFila *exam_queue = exam_create();

    //Inicialización de la lista de máquinas
    MachineList *machine_list = initialize_machines(machine_list_create,machine_quantity);
    

    //Loop que simula la oficina
    while (time_unit < 60)
    {   

        //Posibilidad de que llegue el paciente.
        int gen_pacient_chance = gen_randint(1, 100);
        printf("%d \n", gen_pacient_chance);

        //Si llega un paciente, se le asigna a la lista de pacientes y se le pone en cola para su examen.
        if (gen_pacient_chance <= 20)
        {
            Pacient *pacient = create_meliant(time_unit);
            int id_pacient = get_pacient_id(pacient);
            meliant_insert(list_meliants ,pacient);
            exam_enqueue(exam_queue,id_pacient,time_unit);
            printf("\n--------------fila de exames---------------\n");
            exam_print(exam_queue);
            int size_meliants = list_size(list_meliants);
            printf("\n-----------------------------\n");
            printf("quantidade de pacientes atuais: %d\n", size_meliants);
            
            ExameNode *next_pacient = exam_dequeue(exam_queue);

            if(next_pacient !=NULL)
            {
                int machine_id=find_idle_machine(machine_list);
                if(machine_id!=-1)
                {
                    ExameNode *laud_node = exam_make(next_pacient, machine_id, machine_list, time_unit);
                    
                    int patient_id = get_pacient_node_id(laud_node);
                    exam_enqueue(exam_queue,patient_id,time_unit);

                }

             //Realización de convocatoria de informe y cómputo de métricas
            
                ExameNode *next_laud = exam_dequeue(exam_queue);

                // if(next_laud!=NULL){
                //     int id_radiologist = find_idle_radiologist(radiologist_list);
                //     if(id_radiologist!=-1){                
                //         laud_medium_time += laud_after_node->time_laud;
                    
                //         if(laud_after->gravidade == 1){
                //             helth_time +=laud_after_node->time_laud;
                //             helth_cont++;
                //         }
                //         else if(laud_after->gravidade == 2){
                //             bronkaite_time +=laud_after_node->time_laud;
                //             bronkaite_cont++;
                //         }
                //         else if(laud_after->gravidade== 3){
                //             peneu_time +=laud_after_node->time_laud;
                //             peneu_cont++;
                //         }
                //         else if(laud_after->gravidade == 4){
                //             femur_broken_time +=laud_after_node->time_laud;
                //             femur_broken_cont++;
                //         }
                //         else if(laud_after->gravidade == 4){
                //             aprendeu_time +=laud_after_node->time_laud;
                //             aprendeu_cont++;
                //         }
                    
            
            
            }
        }
        time_unit++;
        count_show++;
    }
    print_lista_pacientes(list_meliants);

}