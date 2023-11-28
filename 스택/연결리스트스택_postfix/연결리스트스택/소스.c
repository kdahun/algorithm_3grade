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
    int j = 0; // 후위 표기식 문자 배열 인덱스

    for (int i = 0; i < len; i++) {
        char ch = infix[i];
        if (ch >= '0' && ch <= '9') {
            postfix[j++] = ch; // 피연산자는 그대로 출력
        }
        else if (ch == '(') {
            push_stack(s, ch);
        }
        else if (ch == ')') {
            while (s->top != NULL && s->top->data != '(') {
                postfix[j++] = pop(s); // '('를 만날 때까지 연산자를 출력
            }
            pop(s); // '('를 스택에서 제거
        }
        else if (is_operator(ch)) {
            while (s->top != NULL && prec(ch) <= prec(s->top->data)) {
                postfix[j++] = pop(s); // 스택의 연산자를 출력
            }
            push_stack(s, ch);
        }
    }

    while (s->top != NULL) {
        postfix[j++] = pop(s); // 남은 연산자 출력
    }

    postfix[j] = '\0'; // 문자열 종료
}

int evaluate_postfix(char postfix[]) {
    int len = strlen(postfix);
    Stack* s = create_stack();

    for (int i = 0; i < len; i++) {
        char ch = postfix[i];
        if (ch >= '0' && ch <= '9') {
            push_stack(s, ch - '0'); // 숫자면 스택에 푸시
        }
        else if (is_operator(ch)) {
            // 연산자를 만났을 때 스택에서 피연산자를 팝하고 연산 수행
            int operand2 = pop(s);
            int operand1 = pop(s);
            int result;
            switch (ch) {
            case '+': result = operand1 + operand2; break;
            case '-': result = operand1 - operand2; break;
            case '*': result = operand1 * operand2; break;
            case '/': result = operand1 / operand2; break;
            }
            push_stack(s, result); // 결과를 스택에 푸시
        }
    }

    // 최종 결과는 스택에 남아 있어야 합니다.
    return pop(s);
}

int main() {
    char infix[] = "(2+3)*4+9";
    printf("중위 표기식: %s\n", infix);

    char postfix[100]; // 후위 표기식을 저장할 배열
    infix_to_postfix(infix, postfix);

    printf("후위 표기식: %s\n", postfix);

    int result = evaluate_postfix(postfix);
    printf("계산 결과: %d\n", result);

    return 0;
}
