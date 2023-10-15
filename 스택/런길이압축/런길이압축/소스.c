#include<stdio.h>
#include<stdlib.h>

#define MAX_STACK_SIZE 100

typedef char element;
element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty() {
	return (top == -1);
}

int is_full() {
	return (top == (MAX_STACK_SIZE - 1));
}

void push(element item) {
	if (is_full()) {
		printf("스택 포화");
		return;
	}
	else stack[++top] = item;
}

element pop() {
	if (is_empty()) {
		printf("스택 공백");
		exit(1);
	}
	else return stack[top--];
}

element peek() {
	if (is_empty()) {
		printf("스택 공백");
		exit(1);
	}
	else return stack[top];
}

void main() {
	char c[100]; // char* c은 문자열 리터럴이여서 변경이 안되므로 c[]로 바꿔줌.

	scanf_s(" %s", c ,sizeof(c));

	int len = strlen(c);

	push(c[0]);

	for (int i = 1; i < len; i++) {
		if (c[i] >= 'A' && c[i] <= 'Z') {
			c[i] += 32;
		}
		
		if (peek() != c[i]) {
			int count = 0;
			char a;
			while (!is_empty()) {
				count++;
				a = pop();
			}
			printf("%d%c", count, a);
		}

		push(c[i]);
	}
	int count = 0;
	char a;
	while (!is_empty()) {
		count++;
		a = pop();
	}
	printf("%d%c", count, a);
}