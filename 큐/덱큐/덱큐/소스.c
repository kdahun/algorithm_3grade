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

void push_rear(QueueNode* q, int item) {
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

void push_front(QueueNode* q, int item) {
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

int pop_front(QueueNode* q) {
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

int pop_rear(QueueNode* q) {
	if (q->front == NULL) {
		printf("큐가 공백상태 입니다.");
		exit(1);
	}
	else {

		if (q->front == q->rear) {
			int data = q->rear->data;
			q->rear = q->front = NULL;
			return data;
		}

		Node* temp = q->front;
		while (temp->next != q->rear) {
			temp = temp->next;
		}

		int data = q->rear->data;
		free(q->rear);
		q->rear = temp;
		q->rear->next = NULL;
		
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
	push_front(q, 10);
	printQueue(q);
	push_rear(q, 40);
	printQueue(q);
	push_front(q, 20);
	printQueue(q);
	push_front(q, 30);
	printQueue(q);
	pop_front(q);
	printQueue(q);


	pop_rear(q);
	printQueue(q);

	pop_rear(q);
	printQueue(q);
	printf("큐에서 나온거 : %d\n", pop_rear(q));
	printQueue(q);

	push_rear(q, 40);
	printQueue(q);

	pop_front(q);
	printQueue(q);

	push_rear(q, 40);
	printQueue(q);
}