# include<stdio.h>
# include<stdlib.h>
# include<malloc.h>
# include<Windows.h>

typedef struct Point {
	int x;
	int y;
}Point;

typedef struct Node {
	Point point;
	struct Node* link;
}Node;

typedef struct Stack {
	struct Node* top;
}Stack;

void push(Stack* s, Point point) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->link = s->top;
	temp->point = point;
	s->top = temp;
}

Point pop(Stack* s) {
	if (s->top == NULL) {
		printf("스택이 비었음");
		exit(1);
	}
	else {
		Node* temp = (Node*)malloc(sizeof(Node));
		Point point;

		temp = s->top;
		s->top = temp->link;
		point = temp->point;
		free(temp);
		return point;
	}
}

void printPoint(Stack* s) {
	for (Node* p = s->top; p != NULL; p = p->link) {
		printf("%d %d->", p->point.x, p->point.y);
	}
	printf("\n");
}

void main() {
	Stack* s = NULL;
	Point p = { 10,11 };

	push(&s, p); printPoint(&s);
	push(&s, p); printPoint(&s);
	push(&s, p); printPoint(&s);
	push(&s, p); printPoint(&s);
	pop(&s, p); printPoint(&s);
	pop(&s, p); printPoint(&s);
	pop(&s, p); printPoint(&s);
	pop(&s, p); printPoint(&s);
	pop(&s, p); printPoint(&s);
	pop(&s, p); printPoint(&s);
	pop(&s, p); printPoint(&s);
	pop(&s, p); printPoint(&s);

}