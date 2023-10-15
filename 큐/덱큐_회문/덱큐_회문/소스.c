# include<stdio.h>
# include<stdlib.h>

typedef struct Node {
	char data;
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

void push_rear(QueueNode* q, char item) {
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

void push_front(QueueNode* q, char item) {
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

char pop_front(QueueNode* q) {
	if (q->front == NULL) {
		printf("큐가 공백상태 입니다.");
		exit(1);
	}
	else {
		Node* temp = q->front;
		char data = temp->data;
		q->front = temp->next;
		if (q->front == NULL) {
			q->rear = q->front;
		}
		free(temp);
		return data;
	}
}

char pop_rear(QueueNode* q) {
	if (q->front == NULL) {
		printf("큐가 공백상태 입니다.");
		exit(1);
	}
	else {

		if (q->front == q->rear) {
			char data = q->rear->data;
			q->rear = q->front = NULL;
			return data;
		}

		Node* temp = q->front;
		while (temp->next != q->rear) {
			temp = temp->next;
		}

		char data = q->rear->data;
		free(q->rear);
		q->rear = temp;
		q->rear->next = NULL;

		return data;
	}
}

void printQueue(QueueNode* q) {
	for (Node* p = q->front; p != NULL; p = p->next) {
		printf("%c -> ", p->data);
	}
	printf("\n");
}

void main() {
	QueueNode* q = create();
	char c[100] = "madam, I'm Adam";
	int count = 0;


	for (int i = 0; i < strlen(c); i++) {
		if (c[i] >= 'A' && c[i] <= 'Z') {
			c[i] += 32;
		}
		if (c[i] >= 'a' && c[i] <= 'z') {
			count++;
			push_front(q, c[i]);
		}
	}
	printQueue(q);

	for (int i = 0; i < count/2; i++) {
		char c1 = pop_front(q);
		char c2 = pop_rear(q);
		printf("%c   %c\n", c1, c2);
	}

}