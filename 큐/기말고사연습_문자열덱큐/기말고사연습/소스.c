# include<stdio.h>
# include<stdlib.h>
#include <string.h>
typedef struct Node {
	char data[10];
	struct Node* next;
}Node;

typedef struct dequeue {
	
	struct Node* front;
	struct Node* rear;
}dequeue;


dequeue* init() {
	dequeue* createNode = (dequeue*)malloc(sizeof(dequeue));
	createNode->front = NULL;
	createNode->rear = NULL;

	return createNode;
}

void* insertFront(dequeue* head,const char* data) {
	Node* temp = (Node*)malloc(sizeof(Node));

	strncpy_s(temp->data, sizeof(temp->data), data, _TRUNCATE); // 문자열을 복사


	temp->next = NULL;

	if (head->front == NULL) {
		head->front = temp;
		head->rear = temp;
	}
	else {
		temp->next = head->front;
		head->front = temp;
	}
}

void* insertRear(dequeue* head, const char* data) {
	Node* temp = (Node*)malloc(sizeof(Node));

	strncpy_s(temp->data, sizeof(temp->data), data, _TRUNCATE); // 문자열을 복사

	temp->next = NULL;

	if (head->front == NULL) {
		head->front = temp;
		head->rear = temp;
	}
	else {
		head->rear->next = temp;
		head->rear = temp;
	}
}

void removeFront(dequeue* head) {
	if (head->front == NULL) {
		printf("덱 큐가 비어있습니다.");
		return;
	}
	else {
		Node* temp = (Node*)malloc(sizeof(Node));
		temp = head->front;
		head->front = temp->next;
		free(temp);
		if (head->front == NULL) {
			head->rear = NULL;
		}
	}
}

void removeRear(dequeue* head) {
	if (head->front == NULL) {
		printf("덱 큐가 비어있습니다");
		return;
	}
	else {
		if (head->front == head->rear) {
			head->rear = head->front = NULL;
			return;
		}

		Node* p = head->front;
		while (p->next != head->rear) {
			p = p->next;
		}
		free(head->rear);
		p->next = NULL;
		head->rear = p;
	}
}

void printDequeue(dequeue* head) {
	for (Node* p = head->front; p != NULL; p = p->next) {
		printf("%s -> ", p->data);
	}
	printf("\n");
}

void main() {
	dequeue* head = init();

	insertFront(head, "11"); printDequeue(head);
	insertFront(head, "12"); printDequeue(head);
	insertFront(head, "13"); printDequeue(head);
	insertFront(head, "14"); printDequeue(head);
	insertRear(head, "10"); printDequeue(head);

	removeFront(head); printDequeue(head);

	removeRear(head); printDequeue(head);
	removeRear(head); printDequeue(head);
	removeRear(head); printDequeue(head);
	removeRear(head); printDequeue(head);
	removeRear(head); printDequeue(head);
	removeRear(head); printDequeue(head);


	insertFront(head, "11"); printDequeue(head);
	insertFront(head, "12"); printDequeue(head);
	insertFront(head, "13"); printDequeue(head);
	insertFront(head, "14"); printDequeue(head);
	insertRear(head, "10"); printDequeue(head);

}