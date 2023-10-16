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
	if (q->front == NULL) {
		printf("덱큐가 비었습니다.");
		exit(1);
	}
	else {
		Node* temp = q->front;
		int data = temp->data;

		if (q->front == q->rear) {
			q->front = q->rear = NULL;

			return data;
		}

		q->front = temp->next;
		free(temp);

		return data;
	}
}

Queue* pop_rear(Queue* q) {
	if (q->front == NULL) {
		printf("덱큐가 비었습니다.");
		exit(1);
	}
	else {
		int data = q->rear->data;
		if (q->front == q->rear) {
			q->front = q->rear = NULL;

			return data;
		}

		Node* temp = q->front;

		while (temp->next != q->rear) {
			temp = temp->next;
		}

		free(q->rear);
		q->rear = temp;
		q->rear->next = NULL;
		return data;
	}
}

void print_Queue(Queue* q) {
	for (Node* p = q->front; p != NULL; p = p->next) {
		printf("%d -> ", p->data);
	}
	printf("\n");
}

void main() {
	Queue* cpu[3];
	for (int i = 0; i < 3; i++) {
		cpu[i] = create();
	}

	int done = 0;

	push_front(cpu[0], 10);
	push_front(cpu[0], 20);
	push_front(cpu[0], 30);

	push_front(cpu[1], 40);
	push_front(cpu[1], 50);

	push_front(cpu[2], 60);

	while (done != 3) {
		for (int i = 0; i < 3; i++) {
			if (cpu[i]->front != NULL) {
				printf("%d : %d\n", i, pop_rear(cpu[i]));
				if (cpu[i]->front == NULL) {
					done++;
				}
			}
			else {
				for (int j = 0; j < 3; j++) {
					if (cpu[j]->front != NULL) {
						push_front(cpu[i], pop_front(cpu[j]));
						if (cpu[j]->front == NULL) {
							done++;
						}
						printf("%d : %d\n", i, pop_rear(cpu[i]));

						break;
					}
				}
			}
		}
	}
}