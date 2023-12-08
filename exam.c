#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exam.h"
#include "machine.h"
#include "pacient.h"

struct ExameNode {
    int patient_id;
    int time_atend;
    char condition[20];
    int gravidade;
    struct ExameNode *next;
};

struct ExameFila {
    struct ExameNode *front;
    struct ExameNode *rear;
};


ExameFila *exam_create() {
    ExameFila *exam_q = (ExameFila *)malloc(sizeof(ExameFila));
    if (exam_q == NULL) {
        perror("Failed to create exam queue");
        exit(EXIT_FAILURE);
    }
    exam_q->front = exam_q->rear = NULL;
    return exam_q;
}

int exam_is_empty(ExameFila *exam_q) {
    return exam_q->front == NULL;
}

void exam_enqueue(ExameFila *exam_q, int patient_id, int time_atend) {
    ExameNode *node = (ExameNode *)malloc(sizeof(ExameNode));
    if (node == NULL) {
        perror("Failed to enqueue exam");
        exit(EXIT_FAILURE);
    }

    node->patient_id = patient_id;
    node->time_atend = time_atend;
    node->next = NULL;

    if (exam_is_empty(exam_q)) {
        exam_q->front = node;
    } else {
        exam_q->rear->next = node;
    }

    exam_q->rear = node;
}

ExameNode *exam_dequeue(ExameFila *exam_q) {
    assert(!exam_is_empty(exam_q));

    ExameNode *record = exam_q->front;
    exam_q->front = exam_q->front->next;

    if (exam_q->front == NULL) {
        exam_q->rear = NULL;
    }

    return record;
}

void exam_free(ExameFila *exam_q) {
    ExameNode *p = exam_q->front;
    while (p != NULL) {
        ExameNode *t = p->next;
        free(p);
        p = t;
    }
    free(exam_q);
}

void exam_print(ExameFila *exam_q) {
    if (exam_is_empty(exam_q)) {
        printf("Queue is empty\n");
        return;
    }

    for (ExameNode *p = exam_q->front; p != NULL; p = p->next) {
        printf("Patient ID: %d, time_atend: %d\n", p->patient_id, p->time_atend);
    }

    printf("\n");
}

// void exam_condition(ExameNode *laud_node)
// {
    

//     int chance = gen_randint(0,100);

//     if(chance<=30){
//             strcpy(pacient->condition,"saude normal");
//             pacient->gravidade = 1;
//         }
//     else if(chance>30 && chance<=50){
//             strcpy(pacient->condition,"bronquite");
//             pacient->gravidade = 2;
//         }
//     else if(chance>50 && chance<=70 ){
//             strcpy(pacient->condition,"pneumonia");
//             pacient->gravidade = 3;
//         }
//     else if(chance>70 && chance<=85){
//             strcpy(pacient->condition,"fratura de femur");
//             pacient->gravidade = 4;
//         }
//     else if(chance>85){
//             strcpy(pacient->condition,"apendicite");
//             pacient->gravidade = 4;
//         }

//     laud_node->gravidade=gravidade;
//     strcpy(laud_node->condition,condition);

// }

void exam_condition(ExameNode *laud_node)
{
    int chance = gen_randint(0, 100);

    if (chance <= 30) {
        strcpy(laud_node->condition, "saude normal");
        laud_node->gravidade = 1;
    } else if (chance > 30 && chance <= 50) {
        strcpy(laud_node->condition, "bronquite");
        laud_node->gravidade = 2;
    } else if (chance > 50 && chance <= 70) {
        strcpy(laud_node->condition, "pneumonia");
        laud_node->gravidade = 3;
    } else if (chance > 70 && chance <= 85) {
        strcpy(laud_node->condition, "fratura de femur");
        laud_node->gravidade = 4;
    } else if (chance > 85) {
        strcpy(laud_node->condition, "apendicite");
        laud_node->gravidade = 4;
    }
}


// ExameNode *exam_make(ExameNode *next_pacient, int machine_id,MachineList *machine_list, int time_unit){
//     struct ExamNode *laud_node = (struct ExamNode *)malloc(sizeof(struct ExamNode));
//     if (laud_node == NULL)
//     {
//         perror("Failed to create laud");
//         exit(EXIT_FAILURE);
//     }
//     mark_machine_as_busy(machine_list, machine_id);
//     // Preenchimento do nó com as informações do paciente e do exame
//     laud_node->patient_id = next_pacient->patient_id;
//     laud_node->timestamp = time_unit;
//     laud_node->gravidade = next_pacient->gravidade;
//     strcpy(laud_node->condition, next_pacient->condition);

//     exam_condition(laud_node);

//     laud_node->next = NULL;
//     return laud_node;
// }
    
ExameNode *exam_make(ExameNode *next_pacient, int machine_id, MachineList *machine_list, int time_unit) {
    // Alocação de memória para o novo nó de exame
    struct ExameNode *laud_node = (struct ExameNode *)malloc(sizeof(struct ExameNode));
    
    // Verifica se a alocação de memória foi bem-sucedida
    if (laud_node == NULL) {
        perror("Failed to create exam node");
        exit(EXIT_FAILURE);
    }

    // // Verifica se a máquina está disponível antes de marcá-la como ocupada
    // if (!is_machine_available(machine_list, machine_id)) {
    //     fprintf(stderr, "Error: Machine %d is not available\n", machine_id);
    //     // Trate o erro adequadamente (por exemplo, escolher outra máquina ou esperar)
    //     // ...
    // }
    
    // Marca a máquina como ocupada
    mark_machine_as_busy(machine_list, machine_id);

    // Preenchimento do nó com as informações do paciente e do exame
    laud_node->patient_id = next_pacient->patient_id;
    laud_node->time_atend= time_unit;
    laud_node->gravidade = next_pacient->gravidade;

    // Usa strncpy para evitar buffer overflow na cópia da condição do paciente
    strncpy(laud_node->condition, next_pacient->condition, sizeof(laud_node->condition) - 1);
    laud_node->condition[sizeof(laud_node->condition) - 1] = '\0';  // Garante a terminação nula

    // Chamada da função exam_condition (presumo que essa função faça algum processamento adicional)
    exam_condition(laud_node);

    // Configura o próximo ponteiro como NULL, indicando o final da lista
    laud_node->next = NULL;

    // Retorna o nó de exame criado
    return laud_node;
}

int get_pacient_node_id(ExameNode *laud_node)
{
    return (laud_node->patient_id);

};