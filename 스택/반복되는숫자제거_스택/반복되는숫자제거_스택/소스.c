#include<stdlib.h>
#include<stdio.h>

#define MAX_STACK 100

int top = -1;
int stack[MAX_STACK];

int is_empty() {
	return top == -1;
}
int is_full() {
	return top == MAX_STACK - 1;
}

void push(int item) {
	if (is_full()) {
		printf("스택이 가득 찼습니다.\n");
	}
	else {
		stack[++top] = item;
	}
}

int pop() {
	if (is_empty()) {
		printf("공백상태\n");
		exit(1);
	}
	else {
		return stack[top--];
	}
}

int peek() {
	if (is_empty()) {
		printf("공백상태\n");
		exit(1);
	}
	else {
		return stack[top];
	}
}

void main() {
	char c[100];
	int len;

	scanf_s(" %s", c, sizeof(c));
	len = strlen(c);

	push(c[0]);

	for (int i = 1; i < len; i++) {
		if (c[i] != peek()) {
			printf("%c", pop());
			push(c[i]);
		}
	}

	printf("%c", pop());
}