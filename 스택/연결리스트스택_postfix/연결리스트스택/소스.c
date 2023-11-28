#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("������ �������\n");
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

int is_operator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int prec(char op) {
    switch (op) {
    case '(': case ')': return 0;
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    }
    return -1;
}

void infix_to_postfix(char infix[], char postfix[]) {
    int len = strlen(infix);
    Stack* s = create_stack();
    int j = 0; // ���� ǥ��� ���� �迭 �ε���

    for (int i = 0; i < len; i++) {
        char ch = infix[i];
        if (ch >= '0' && ch <= '9') {
            postfix[j++] = ch; // �ǿ����ڴ� �״�� ���
        }
        else if (ch == '(') {
            push_stack(s, ch);
        }
        else if (ch == ')') {
            while (s->top != NULL && s->top->data != '(') {
                postfix[j++] = pop(s); // '('�� ���� ������ �����ڸ� ���
            }
            pop(s); // '('�� ���ÿ��� ����
        }
        else if (is_operator(ch)) {
            while (s->top != NULL && prec(ch) <= prec(s->top->data)) {
                postfix[j++] = pop(s); // ������ �����ڸ� ���
            }
            push_stack(s, ch);
        }
    }

    while (s->top != NULL) {
        postfix[j++] = pop(s); // ���� ������ ���
    }

    postfix[j] = '\0'; // ���ڿ� ����
}

int evaluate_postfix(char postfix[]) {
    int len = strlen(postfix);
    Stack* s = create_stack();

    for (int i = 0; i < len; i++) {
        char ch = postfix[i];
        if (ch >= '0' && ch <= '9') {
            push_stack(s, ch - '0'); // ���ڸ� ���ÿ� Ǫ��
        }
        else if (is_operator(ch)) {
            // �����ڸ� ������ �� ���ÿ��� �ǿ����ڸ� ���ϰ� ���� ����
            int operand2 = pop(s);
            int operand1 = pop(s);
            int result;
            switch (ch) {
            case '+': result = operand1 + operand2; break;
            case '-': result = operand1 - operand2; break;
            case '*': result = operand1 * operand2; break;
            case '/': result = operand1 / operand2; break;
            }
            push_stack(s, result); // ����� ���ÿ� Ǫ��
        }
    }

    // ���� ����� ���ÿ� ���� �־�� �մϴ�.
    return pop(s);
}

int main() {
    char infix[] = "(2+3)*4+9";
    printf("���� ǥ���: %s\n", infix);

    char postfix[100]; // ���� ǥ����� ������ �迭
    infix_to_postfix(infix, postfix);

    printf("���� ǥ���: %s\n", postfix);

    int result = evaluate_postfix(postfix);
    printf("��� ���: %d\n", result);

    return 0;
}
