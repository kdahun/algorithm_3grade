# include<stdio.h>
# include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

typedef struct QueueNode {
	struct Node* front, * rear;
}QueueNode;

QueueNode* create() {
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->front = NULL;
	newNode->rear = NULL;

	return newNode;
}

void push(QueueNode*q,int item) {
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

int pop(QueueNode* q) {
	if (q->front == NULL) {
		printf("큐가 공백상태 입니다.");
		exit(1);
	}
	else {
		Node* temp = q->front;
		int data = temp->data;
		q->front = temp->next;
		if (q->front == NULL) {
			q->rear = q->front;
		}
		free(temp);
		return data;
	}
}

void printQueue(QueueNode* q) {
	for (Node* p = q->front; p != NULL; p = p->next) {
		printf("%d -> ", p->data);
	}
	printf("\n");
}

void main() {
	QueueNode* q = create();
	int data1 = 1;
	int data2 = 1;

	push(q, data1);
	push(q, data2);
	for (int i = 1; i < 10; i++) {
		int temp1 = pop(q);// data1(0)
		int temp2 = pop(q);// data2(1)
		data2 = temp1 + temp2; //(2)
		data1 = temp2; //(1)

		push(q, data1);
		push(q, data2);
	}
	printf("5번째 : %d", data2);
	
}