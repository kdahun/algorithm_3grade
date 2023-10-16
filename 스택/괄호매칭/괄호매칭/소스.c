#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;
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
        printf("스택 포화\n");
        return;
    }
    else {
        stack[++top] = item;
    }
}

element pop() {
    if (is_empty()) {
        printf("스택 공백\n");
        exit(1);
    }
    else {
        return stack[top--];
    }
}

element peek() {
    if (is_empty()) {
        printf("스택 공백\n");
        exit(1);
    }
    else {
        return stack[top];
    }
}

int main() {
    char* c = "((())(()))";
    
    int len = strlen(c);
    printf("%d\n\n", len);

    int count = 0;
    for (int i = 0; i < len; i++) {
        if (c[i] == '(') {
            count++;
            printf("%d", count);
            push(count);
        }
        else {
            printf("%d", pop());
        }
    }

    return 0; // main 함수는 int를 반환해야 합니다.
}
