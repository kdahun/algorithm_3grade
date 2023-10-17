# include<stdio.h>
# include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* insertNode(Node* head, int data) {

	Node* newNode = (Node*)malloc(sizeof(Node));
	

	newNode->data = data;
	newNode->next = NULL;

	if (head == NULL) {
		head = newNode;
		return head;
	}

	if (head->data > data) {
		newNode->next = head;
		head = newNode;
		return head;
	}

	Node* temp = head;
	
	while (temp->next != NULL) {
		if (temp->next->data > data) {
			newNode->next = temp->next;
			temp->next = newNode;
			return head;
		}
		temp = temp->next;
	}
	temp->next = newNode;
	return head;
	//여기에서는 연결
}

Node* insertNode2(Node* head, int item) {
	Node* temp = (Node*)malloc(sizeof(Node));

	temp->data = item;

	temp->next = head;
	head = temp;

	return head;
}

void printNode(Node* head) {
	for (Node* p = head; p != NULL; p = p->next) {
		printf("%d -> ",p->data);
	}
	printf("\n");
}

Node* mixNode(Node* headC, Node* headA, Node* headB) {
	while (headA != NULL && headB != NULL) {
		if (headA->data > headB->data) {
			headC = insertNode2(headC, headB->data);
			headB = headB->next;
		}
		else {
			headC = insertNode2(headC, headA->data);
			headA = headA->next;
		}
		printNode(headC);
	}

	if (headA != NULL) {
		while (headA != NULL) {
			headC = insertNode2(headC, headA->data);
			headA = headA->next;
		}
	}
	if (headB != NULL) {
		while (headB != NULL) {
			headC = insertNode2(headC, headB->data);
			headB = headB->next;
		}
	}
	return headC;
}

void main() {
	Node* headA = NULL;
	Node* headB = NULL;
	Node* headC = NULL;

	headA = insertNode(headA, 20);
	headA = insertNode(headA, 40);
	headA = insertNode(headA, 10);
	headA = insertNode(headA, 70);
	printNode(headA);

	headB = insertNode(headB, 90);
	headB = insertNode(headB, 50);
	headB = insertNode(headB, 30);
	headB = insertNode(headB, 80);
	printNode(headB);

	headC = mixNode(headC, headA, headB);

	printNode(headC);
}