#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<malloc.h>

typedef struct Point {
	int x;
	int y;
}Point;

typedef struct Node {
	Point point;
	struct Node* link;
}Node;

typedef struct Queue {
	Node* front;
	Node* rear;
}Queue;

void push(Queue* queue, Point point) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->link = NULL;
	temp->point = point;
	if (queue->front == NULL) {
		queue->front = temp;
		queue->rear = temp;
	}
	else {
		queue->rear->link = temp;
		queue->rear = temp;
	}
}

Point pop(Queue* queue) {
	if (queue->front == NULL) {
		printf("큐가 비어있음.");
		exit(1);
	}
	else {
		Node* temp = (Node*)malloc(sizeof(Node));
		Point xy;

		temp = queue->front;
		queue->front = temp->link;
		xy = temp->point;
		if (queue->front == NULL)
			queue->rear = NULL;

		free(temp);

		return xy;
	}
}

void printQueue(Queue* queue) {
	for (Node* q = queue->front; q != NULL; q = q->link) {
		printf("%d %d->", q->point.x, q->point.y);
	}
	printf("NULL\n");
}

void main() {
	Queue q;
	q.front = NULL;
	q.rear = NULL;

	Point p;

	for (int i = 0; i < 5; i++) {
		p.x = i;
		p.y = i;

		push(&q, p);
		printQueue(&q);
	}

	for (int i = 0; i < 6; i++) {
		

		pop(&q);
		printQueue(&q);
	}
}