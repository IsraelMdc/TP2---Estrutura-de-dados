#include <stdio.h>
#include <stdlib.h>
#include "radiologist.h"

// Estrutura para representar um nó da fila
struct Node_Radiologist {
    int data;             // Identificador do radiologista
    int is_available;     // Indica se o radiologista está disponível (1) ou não (0)
    struct Node *next;    // Ponteiro para o próximo nó na fila
};

// Estrutura para representar uma fila de radiologistas
struct Queue_Radiologist {
    Node *front;   // Ponteiro para o início da fila
    Node *rear;    // Ponteiro para o final da fila
};

// Função para inicializar a fila
void initializeQueue(Queue *queue) {
    queue->front = queue->rear = NULL;
}

// Função para verificar se a fila está vazia
int isQueueEmpty(Queue *queue) {
    return queue->front == NULL;
}

// Função para enfileirar um radiologista na fila
void enqueue(Queue *queue, int radiologistID) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Failed to enqueue radiologist");
        exit(EXIT_FAILURE);
    }

    newNode->data = radiologistID;
    newNode->is_available = 1;  // Novo radiologista é marcado como disponível por padrão
    newNode->next = NULL;

    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Função para verificar a disponibilidade de um radiologista na fila
int checkRadiologistAvailability(Queue *radiologist_list) {
    if (!isQueueEmpty(radiologist_list)) {
        if (radiologist_list->front->is_available) {
            return radiologist_list->front->data;
        }
    }

    return -1;  // Indica que não há radiologistas disponíveis
}

// Função para obter o ID do radiologista na frente da fila
int front(Queue *queue) {
    if (isQueueEmpty(queue)) {
        fprintf(stderr, "Error: Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    return queue->front->data;
}
/*
int main() {
    Queue radiologistList;
    initializeQueue(&radiologistList);

    // Adicionando radiologistas à fila
    enqueue(&radiologistList, 1);
    enqueue(&radiologistList, 2);
    enqueue(&radiologistList, 3);

    // Verificando a disponibilidade de radiologistas
    int availableRadiologist = checkRadiologistAvailability(&radiologistList);

    if (availableRadiologist != -1) {
        printf("Radiologist %d is available.\n", availableRadiologist);
    } else {
        printf("No radiologists available.\n");
    }

    return 0;
}
*/

