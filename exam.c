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

void exam_condition(ExameNode *laud_node)
{
    

    int chance = gen_randint(0,100);

    if(chance<=30){
            strcpy(pacient->condition,"saude normal");
            pacient->gravidade = 1;
        }
    else if(chance>30 && chance<=50){
            strcpy(pacient->condition,"bronquite");
            pacient->gravidade = 2;
        }
    else if(chance>50 && chance<=70 ){
            strcpy(pacient->condition,"pneumonia");
            pacient->gravidade = 3;
        }
    else if(chance>70 && chance<=85){
            strcpy(pacient->condition,"fratura de femur");
            pacient->gravidade = 4;
        }
    else if(chance>85){
            strcpy(pacient->condition,"apendicite");
            pacient->gravidade = 4;
        }

    laud_node->gravidade=gravidade;
    strcpy(laud_node->condition,condition);

}

ExameNode *exam_make(ExameNode *next_pacient, int machine_id,MachineList *machine_list, int time_unit){
    struct ExamNode *laud_node = (struct ExamNode *)malloc(sizeof(struct ExamNode));
    if (laud_node == NULL) {
        perror("Failed to create laud");
        exit(EXIT_FAILURE);
    }
    mark_machine_as_busy(machine_list, machine_id);
    // Preenchimento do nó com as informações do paciente e do exame
    laud_node->patient_id = next_pacient->patient_id;
    laud_node->timestamp = time_unit;
    laud_node->gravidade = next_pacient->gravidade;
    strcpy(laud_node->condition, next_pacient->condition);

    exam_condition(laud_node);

    laud_node->next = NULL;
    return laud_node;
}
    
int get_pacient_node_id(ExameNode *laud_node)
{
    return (laud_node->patient_id);

};