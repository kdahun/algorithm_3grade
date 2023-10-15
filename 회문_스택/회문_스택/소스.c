# include<stdio.h>
# include<stdlib.h>
# include<string.h>

typedef struct Node {
	char data;
	struct Node* next;
}Node;

typedef struct StackNode {
	struct Node* top;
}StackNode;

StackNode* create() {
	StackNode* new_node = (StackNode*)malloc(sizeof(StackNode*));

	new_node->top = NULL;
	return new_node;
}

void push(StackNode* s, char item) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = item;
	temp->next = s->top;
	s->top = temp;
}

char pop(StackNode* s) {
	if (s->top == NULL) {
		printf("스택이 공백상태입니다\n");
	}
	else {
		Node* temp = s->top;
		char data=temp->data;

		s->top = temp->next;
		free(temp);
		return data;
	}
}

void print_stack(StackNode* s) {
	for (Node* q = s->top; q != NULL; q = q->next) {
		printf(" %c ->", q->data);
	}
	printf("\n");
}

void main() {
	StackNode* s1 = create();
	StackNode* s2 = create();

	char c[100] = "race car";
	char c1[100]="";

	printf("%s\n", c);

	int count = 0;

	for (int i = 0; i < strlen(c); i++) {

		if (c[i] >= 'A' && c[i] <= 'Z') {
			c[i] += 32;
		}

		if (c[i] >= 'a' && c[i] <= 'z') {
			c1[count++] = c[i];
		}
	}

	int c1Len = strlen(c1);

	printf("%s\n\n", c1);

	for (int i = 0; i < c1Len/2; i++) {
		push(s1, c1[i]);
		push(s2, c1[c1Len - i - 1]);
	}

	for (int i = 0; i < c1Len / 2; i++) {
		printf("%c %c\n", pop(s1), pop(s2));
	}

}