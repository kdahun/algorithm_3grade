# include<stdio.h>
# include<stdlib.h>

# define MAX_QUEUE_SIZE 10

typedef struct {
	int data[MAX_QUEUE_SIZE];
	int front, rear;
	int count;
}QueueType;

int is_empty(QueueType* q) {
	return q->count != 0;
}

int is_full(QueueType* q) {
	return q->count != 5;
}

void init_queue(QueueType* q) {
	q->front = q->rear =q->count= 0;
	for (int i = 0; i < 5; i++) {
		q->data[i] = -1;
	}
}

void queue_print(QueueType* q) {
	printf("QUEUE(front = %d rear = %d) = ", q->front, q->rear);
	
	for (int i = 0; i < 5; i++) {
		if (q->data[i] == -1) {
			printf("%d | ", q->data[i]);
		}
		else {
			printf(" %d | ", q->data[i]);
		}
		
	}

	printf("\n");
}

void enqueue(QueueType* q, int item) {
	q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
	q->count++;
	q->data[q->rear] = item;
}

int dequeue(QueueType* q) {

	q->front = (q->front+1) % MAX_QUEUE_SIZE;
	q->data[q->front] = -1;
	q->count--;

	return q->data[q->front];
}

int main(void) {
	QueueType queue;
	
	int element=0;

	init_queue(&queue);
	
	while (is_full(&queue)) { // 포화상태 확인
		printf("정수를 입력하시오. : ");
		element++;
		enqueue(&queue, element);
		queue_print(&queue);
	}

	printf("포화상태입니다.");

	while (is_empty(&queue)) { // 공백상태 확인
		printf("정수를 입력하시오. : ");
		dequeue(&queue);
		queue_print(&queue);
	}

	printf("공백상태입니다.");
}