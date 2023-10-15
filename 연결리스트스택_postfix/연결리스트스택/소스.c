#include <stdio.h>
#include <stdlib.h>

 
typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Stack {
    struct Node* top;
} Stack;

Stack* create_stack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push_stack(Stack* s, char data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = s->top;
    s->top = temp;
}

char pop(Stack* s) {
    if (s->top == NULL) {
        printf("스택이 비어있음\n");
        exit(1);
    }
    else {
        Node* temp = s->top;
        char data = temp->data;
        s->top = temp->next;
        free(temp);
        return data;
    }
}

void print_stack(Stack* s) {
    for (Node* q = s->top; q != NULL; q = q->next) {
        printf("%c - >", q->data);
    }
    printf("\n");
}

int prec(char op) {
    switch (op) {
    case '(': case ')': return 0;
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    }
    return -1;
}

void infix_to_postfix(char exp[]) {
    int i = 0;
    char ch, top_op;
    int len = strlen(exp);

    Stack* s = create_stack();

    for (i = 0; i < len; i++) {
        ch = exp[i];
        switch (ch) {
        case '+':
        case '-':
        case '*':
        case '/':
            while (s->top != NULL && (prec(ch) <= prec(s->top->data))) {
                printf("%c", pop(s));
            }
            push_stack(s, ch);
            break;
        case '(':
            push_stack(s, ch);
            break;
        case ')':
            top_op = pop(s);
            while (top_op != '(') {
                printf("%c", top_op);
                top_op = pop(s);
            }
            break;
        default:
            printf("%c", ch);
            break;
        }
    }

    while (s->top != NULL) {
        printf("%c", pop(s));
    }
}

int main() {
    char* s = "(2+3)*4+9";
    printf("중위표시수식 %s\n", s);
    printf("후위표시수식 ");
    infix_to_postfix(s);
    printf("\n");
    return 0;
}
