#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Heap {
    Node* root;
} Heap;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Heap* createHeap() {
    Heap* newHeap = (Heap*)malloc(sizeof(Heap));
    newHeap->root = NULL;
    return newHeap;
}

void insert(Heap* heap, int data) {
    Node* newNode = createNode(data);

    if (heap->root == NULL) {
        heap->root = newNode;
        return;
    }

    // 힙의 마지막 노드를 찾기 위한 큐를 사용
    Node* current = NULL; // 초기화

    Node* queue[1000];
    int front = -1, rear = -1;
    queue[++rear] = heap->root;

    while (front != rear) {
        current = queue[++front];

        if (current->left == NULL) {
            current->left = newNode;
            break;
        }
        else if (current->right == NULL) {
            current->right = newNode;
            break;
        }
        else {
            // 노드가 가득 찼으면 자식 노드를 큐에 추가
            queue[++rear] = current->left;
            queue[++rear] = current->right;
        }
    }

    // Max heap의 특성을 유지하기 위한 재정렬
    while (newNode->data > current->data && current != heap->root) {
        int temp = newNode->data;
        newNode->data = current->data;
        current->data = temp;
        newNode = current;
        // 부모 노드로 이동
        for (int i = 0; i <= rear; i++) {
            if (queue[i]->left == newNode || queue[i]->right == newNode) {
                current = queue[i];
                break;
            }
        }
    }
}

void printHeap(Node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    printHeap(root->left);
    printHeap(root->right);
}

int main() {
    Heap* maxHeap = createHeap();

    int values[] = { 10, 20, 15, 30, 40 };
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        insert(maxHeap, values[i]);
    }

    printf("Max Heap: ");
    printHeap(maxHeap->root);
    printf("\n");

    return 0;
}
