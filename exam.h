#ifndef EXAM_H
#define EXAM_H
#include "machine.h"
#include "pacient.h"


typedef struct ExameFila ExameFila;
typedef struct ExameNode ExameNode;

ExameFila *exam_create();

int exam_is_empty(ExameFila *exam_q);

void exam_enqueue(ExameFila *exam_q, int patient_id, int timestamp);

ExameNode *exam_dequeue(ExameFila *exam_q);

void exam_free(ExameFila *exam_q);

void exam_print(ExameFila *exam_q);

ExameNode *exam_make(ExameNode *next_pacient, int machine_id, MachineList *machine_list, int time_unit);

void exam_condition(ExameNode *laud_node);

int get_pacient_node_id(ExameNode *laud_node);

#endif
