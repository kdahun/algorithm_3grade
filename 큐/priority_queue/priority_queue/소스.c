#include<stdlib.h>
#include<stdio.h>
#include<Windows.h>
#include<malloc.h>

typedef struct Node {
    int data;
    struct Node* list;
}Node;

typedef struct Queue {
    struct Node* front, * rear;
}Queue;

void push(Queue* q, int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->list = NULL;


    if (q->front == NULL) {
        q->front = temp;
        q->rear = temp;

    }
    else {
        Node* save = NULL;

        for (Node* p = q->front; p != NULL; p = p->list) {
            /*if (p->data > data) {
                printf("p : %d  ", p->data);
                if (save != NULL)
                    printf(" save : %d\n\n", save->data);
            }*/

            if (p->data > temp->data)
            {
                temp->list = p;
                if (p == q->front)
                {
                    q->front = temp;
                }
                else
                {
                    save->list = temp;
                }
                return;
            }
            save = p;
        }

        q->rear->list = temp;
        q->rear = temp;
    }
}

int pop(Queue* q) {
    if (q->front == NULL) {
        printf("스택이 비어있음.");
        return -1;
    }
    else {
        Node* temp = (Node*)malloc(sizeof(Node));
        int data = q->front->data;

        temp = q->front;
        q->front = temp->list;
        if (q->front == NULL) {
            q->rear = NULL;
        }
        free(temp);
        return data;
    }
}

void print_queue(Queue* q) {
    for (Node* p = q->front; p != NULL; p = p->list) {
        printf("%d -> ", p->data);
    }
    printf("NULL\n");
}

void main() {
    srand(time(NULL));
    Queue q;
    q.front = NULL;
    q.rear = NULL;

    for (int i = 5; i > 0; i--) {
        int tmp = rand() % 10 + 1;
        push(&q, tmp);
        print_queue(&q);

    }

    for (int i = 0; i < 5; i++) {
        pop(&q);
        print_queue(&q);
    }
}