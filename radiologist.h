#ifndef RADIOLOGIST_H
#define RADIOLOGIST_H

typedef struct Queue_Radiologist Queue;
typedef struct Node_Radiologist Node;


void initializeQueue(Queue *queue);

int isQueueEmpty(Queue *queue);

void enqueue(Queue *queue, int radiologistID);

int checkRadiologistAvailability(Queue *radiologist_list);

int front(Queue *queue);


#endif
