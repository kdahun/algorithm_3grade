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
		printf("���� ��ȭ");
		return;
	}
	else stack[++top] = item;
}

element pop() {
	if (is_empty()) {
		printf("���� ����");
		exit(1);
	}
	else return stack[top--];
}

element peek() {
	if (is_empty()) {
		printf("���� ����");
		exit(1);
	}
	else return stack[top];
}

void main() {
	char c[100]; // char* c�� ���ڿ� ���ͷ��̿��� ������ �ȵǹǷ� c[]�� �ٲ���.

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