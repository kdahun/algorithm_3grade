#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<malloc.h>

typedef struct Point {
	int x, y;
}Point;

typedef struct Node {
	Point point;
	struct Node* list;
}Node;

typedef struct Queue {
	Node* front, *rear;
}Queue;


void push(Queue *q,Point p) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->list = NULL;
	temp->point = p;

	if (q->front == NULL) {
		q->front = temp;
		q->rear = temp;
	}
	else {
		q->rear->list = temp;
		q->rear = temp;
	}
}

Point pop(Queue* q) {
	if (q->front == NULL) {
		printf("큐에 아무것도 없음");
		exit(1);
	}
	else {
		Node* temp = (Node*)malloc(sizeof(Node));
		Point point;

		temp = q->front;
		point = temp->point;
		q->front = temp->list;
		if (q->front == NULL) {
			q->rear = NULL;
		}
		free(temp);
		return point;
	}
}

void print_queue(Queue* q) {
	for (Node* p = q->front; p != NULL; p = p->list) {
		printf("%d %d -> ", p->point.x, p->point.y);
	}
	printf("NULL\n");
}

void main(){
	Queue q;
	q.front = NULL;
	q.rear = NULL;

	for (int i = 0; i < 5; i++) {
		Point point = { i,i };
		push(&q, point);
		print_queue(&q);
	}
	for (int i = 0; i < 5; i++) {
		pop(&q);
		print_queue(&q);
	}

}