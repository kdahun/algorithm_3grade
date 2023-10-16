#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

typedef struct Queue {
	struct Node* front, * rear;
}Queue;

Queue* create() {
	Queue* newQueue = (Queue*)malloc(sizeof(Queue));
	newQueue->front = NULL;
	newQueue->rear = NULL;
	return newQueue;
}

Queue* push_front(Queue* q, int item) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = item;
	temp->next = NULL;
	if (q->front == NULL) {
		q->front = temp;
		q->rear = temp;
	}
	else {
		temp->next = q->front;
		q->front = temp;
	}
}
Queue* push_rear(Queue* q, int item) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = item;
	temp->next = NULL;
	if (q->front == NULL) {
		q->front = temp;
		q->rear = temp;
	}
	else {
		q->rear->next = temp;
		q->rear = temp;
	}
}

Queue* pop_front(Queue* q) {

}

void print_Queue(Queue* q) {
	for (Node* p = q->front; p != NULL; p = p->next) {
		printf("%d -> ", p->data);
	}
	printf("\n");
}

void main() {
	Queue* q = create();

	push_rear(q, 10);
	print_Queue(q);
	push_rear(q, 20);
	print_Queue(q);
	push_rear(q, 30);
	print_Queue(q);
}