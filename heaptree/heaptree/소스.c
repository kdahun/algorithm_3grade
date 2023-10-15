#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
    struct node* queueLink;
    struct node* stackLink;
} node;

typedef struct heapType {
    struct node* root;
    struct node* queue;
    struct node* stack;
    struct node* lastDeletedNode;
} heapType;


// 부모와 자식 간의 우선순위 비교 및 교환
void compareWithParents(node* newNode) {
    node* tempPointer = newNode;
    while (tempPointer->parent != NULL && tempPointer->data > tempPointer->parent->data) {
        int temp = tempPointer->data;
        tempPointer->data = tempPointer->parent->data;
        tempPointer->parent->data = temp;
        tempPointer = tempPointer->parent;
    }
}

// 노드를 삽입하고 최대 힙 속성을 유지하는 함수
void insertNode(heapType* heap, int data) {
    node* newNode = (node*)malloc(sizeof(node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode->queueLink = NULL;
    newNode->stackLink = NULL;

    if (!(heap->root)) {
        heap->root = newNode;
        heap->queue = newNode;
        heap->stack = newNode;
        heap->lastDeletedNode = NULL;
    }
    else {
        if (!(heap->queue->left)) {
            heap->queue->left = newNode;
            newNode->parent = heap->queue;

            // 최대 힙 속성을 유지
            compareWithParents(newNode);

            newNode->stackLink = heap->stack;
            heap->stack->queueLink = newNode;
            heap->stack = newNode;
        }
        else if (heap->queue->right == NULL && heap->queue->left != NULL) {
            heap->queue->right = newNode;
            newNode->parent = heap->queue;

            // 최대 힙 속성을 유지
            compareWithParents(newNode);

            newNode->stackLink = heap->stack;
            heap->stack->queueLink = newNode;
            heap->stack = newNode;
        }
        else if ((heap->queue->left) && (heap->queue->right)) {
            heap->queue = heap->queue->queueLink;

            heap->queue->left = newNode;
            newNode->parent = heap->queue;

            // 최대 힙 속성을 유지
            compareWithParents(newNode);

            newNode->stackLink = heap->stack;
            heap->stack->queueLink = newNode;
            heap->stack = newNode;
        }
    }
}


// 자식과 부모 간의 우선순위 비교 및 교환
void compareWithChilde(node* root) {
    int temp;
    node* tempPointer = root;
    while (tempPointer->left) {
        if (tempPointer->left && tempPointer->right) {
            if (tempPointer->left->data > tempPointer->right->data && tempPointer->data < tempPointer->left->data) {
                temp = tempPointer->data;
                tempPointer->data = tempPointer->left->data;
                tempPointer->left->data = temp;
                tempPointer = tempPointer->left;
            }
            else if (tempPointer->left->data < tempPointer->right->data && tempPointer->data < tempPointer->right->data) {
                temp = tempPointer->data;
                tempPointer->data = tempPointer->right->data;
                tempPointer->right->data = temp;
                tempPointer = tempPointer->right;
            }
        }
        else if (tempPointer->left && !(tempPointer->right)) {
            if (tempPointer->left->data > tempPointer->data) {
                temp = tempPointer->data;
                tempPointer->data = tempPointer->left->data;
                tempPointer->left->data = temp;
            }
            else {
                break;
            }
        }
        else {
            break;
        }
    }
}

// 노드를 삭제하고 최대 힙 속성을 유지하는 함수
int deleteNode(heapType* heap) {
    int rootNodeData = heap->root->data;
    int lastInsertedNodeData = heap->stack->data;

    heap->root->data = lastInsertedNodeData;

    node* temp = heap->stack;
    heap->stack = heap->stack->stackLink;
    heap->stack->queueLink = NULL;

    if (temp->parent->right == temp) {
        temp->parent->right = NULL;
    }
    else {
        temp->parent->left = NULL;
    }
    free(temp);

    // 최대 힙 속성을 유지
    compareWithChilde(heap->root);

    return rootNodeData;
}



// heapType 초기화
heapType* resetHeapType() {
    heapType* newHeap = (heapType*)malloc(sizeof(heapType));
    newHeap->root = NULL;
    newHeap->queue = NULL;
    newHeap->stack = NULL;
    newHeap->lastDeletedNode = NULL;



    return newHeap;
}

// 전위 순회 함수
void preorderTraversal(node* root) {
    if (root != NULL) {
        printf("%d ", root->data); // 현재 노드 출력
        preorderTraversal(root->left); // 왼쪽 서브트리 순회
        preorderTraversal(root->right); // 오른쪽 서브트리 순회
    }
}

int main() {
    heapType* heap = resetHeapType();

    // 데이터를 삽입
    insertNode(heap, 5);
    printf("Preorder Traversal: ");
    preorderTraversal(heap->root);
    printf("\n");
    insertNode(heap, 3);
    printf("Preorder Traversal: ");
    preorderTraversal(heap->root);
    printf("\n");
    insertNode(heap, 7);
    printf("Preorder Traversal: ");
    preorderTraversal(heap->root);
    printf("\n");
    insertNode(heap, 1);
    printf("Preorder Traversal: ");
    preorderTraversal(heap->root);
    printf("\n");
    insertNode(heap, 4);
    printf("Preorder Traversal: ");
    preorderTraversal(heap->root);
    printf("\n");
    // 루트 노드 삭제
    int deletedData = deleteNode(heap);
    printf("Deleted Max Node: %d\n", deletedData);

    return 0;
}
