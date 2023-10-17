# include<stdio.h>
# include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* insertNode(Node* head, int item) {
	Node* temp = (Node*)malloc(sizeof(Node));

	temp->data = item;
 	temp->next = head;
	head = temp;

	return head;
}

Node* deleteNode(Node* head) {
	if (head == NULL) {
		printf("노드가 공백입니다.");
		return NULL;
	}
	else {
		Node* temp = head;
		head = temp->next;
		free(temp);
	}

	return head;
}

void printNode(Node* head) {
	for (Node* p = head; p != NULL; p = p->next) {
		printf("%d -> ", p->data);
	}
	printf("\n");
}

void main() {
	Node* headA = NULL;
	Node* headB = NULL;
	Node* headC = NULL;

	headA = insertNode(headA, 10);
	headA = insertNode(headA, 30);
	headA = insertNode(headA, 50);

	headB = insertNode(headB, 20);
	headB = insertNode(headB, 40);
	headB = insertNode(headB, 60);


	Node* tempA = headA;
	Node* tempB = headB;
	
	while (tempA != NULL) {
		headC = insertNode(headC, tempA->data);
		headC = insertNode(headC, tempB->data);
		tempA = tempA->next;
		tempB = tempB->next;
	}
	printNode(headC);
}