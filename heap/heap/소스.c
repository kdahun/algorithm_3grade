# include<stdio.h>
# include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
	struct Node* parent;
	struct Node* queue;
}Node;

typedef struct Queue {
	Node* front;
	Node* rear;
}Queue;

typedef struct Heap {
	Node* root;
}Heap;

Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
	newNode->queue = NULL;

	return newNode;
}

void inserNode(Heap*node,int data) {
	Node* temp = createNode(data);
	

	if (node->root == NULL) {
		node->root = temp;
	}
	else {
		
	}
	
}

void main() {
	Heap* maxHeap = NULL;


}