# include<stdio.h>
# include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

typedef struct StackNode {
	struct Node* top;
}StackNode;

StackNode* create_stack() {
	StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
	new_node->top = NULL;
	return new_node;
}

void push(StackNode * s, int item) {
	Node* temp = (Node*)malloc(sizeof(Node*));
	temp->data = item;
	temp->next = s->top;
	s->top = temp;
}

int stack_pop(StackNode* s) {
	if (s->top == NULL) {
		printf("스택이 비어있음");
		exit(1);
	}
	else {
		Node* temp = s->top;
		int data = temp->data;
		s->top = temp->next;

		return data;
	}
}

void print_stack(StackNode* s) {
	for (Node* p = s->top; p != NULL; p = p->next) {
		printf("%d - > ", p->data);
	}
	printf("\n");
}

int pop(StackNode* s) {
	if (s->top == NULL) {
		printf("스택이 비어있음");
		exit(1);
	}
	else {
		StackNode* s2 = create_stack();
		for (Node* p = s->top; p != NULL; p = p->next) {
			push(s2, stack_pop(s));
		}
		printf("스택 2에 넣어준 상태 : ");
		print_stack(s2);
		stack_pop(s2);

		printf("스택 2에 1개 빼준 상태 : ");
		print_stack(s2);

		for (Node* p = s2->top; p != NULL; p = p->next) {
			push(s, stack_pop(s2));
		}
		printf("스택 1 상태 : ");
		print_stack(s);

	}
}



void main() {
	StackNode* s = create_stack();
	push(s, 10); print_stack(s);
	push(s, 20); print_stack(s);
	push(s, 30); print_stack(s);

	pop(s);
	pop(s);
}