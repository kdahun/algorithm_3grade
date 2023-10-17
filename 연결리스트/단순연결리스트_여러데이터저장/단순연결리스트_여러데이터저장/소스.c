#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
	char name[10];
	int age;
	float heigh;
	struct Node* next;
}Node;

Node* insert_Node(Node* head, const char* name,int age,float heigh) {
	Node* temp = (Node*)malloc(sizeof(Node));

	strncpy_s(temp->name, sizeof(temp->name),name,_TRUNCATE); // 문자열을 복사

	temp->age = age;
	temp->heigh = heigh;
	temp->next = head;
	head = temp;
	return head;
}

void printNode(Node* head) {
	for (Node* p = head; p != NULL; p = p->next) {
		printf("Name  : %s\t", p->name);
	}
	printf("\n");
	for (Node* p = head; p != NULL; p = p->next) {
		printf("Age   : %d\t", p->age);
	}
	printf("\n");
	for (Node* p = head; p != NULL; p = p->next) {
		printf("Heigh : %.1f\t", p->heigh);
	}
	printf("\n");
}

void main() {
	Node* head = NULL;

	head = insert_Node(head, "dahun", 24, 1.5);
	printNode(head);
	head = insert_Node(head, "dahun2", 25, 1.6);
	printNode(head);
}