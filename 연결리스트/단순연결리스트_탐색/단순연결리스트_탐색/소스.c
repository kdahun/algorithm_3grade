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
		printf("노드가 비어있음.");
		return NULL;
	}
	Node* temp = head;
	
	head = temp->next;
	free(temp);

	return head;
}

void print_node(Node* head) {
	for (Node* p = head; p != NULL; p = p->next) {
		printf("%d -> ", p->data);
	}
	printf("NULL\n");
}

int node_count(Node* head) {
	int count = 0;
	for (Node* p = head; p != NULL; p = p->next) {
		count++;
	}
	return count;
}

int node_sum(Node* head) {
	int sum = 0;
	for (Node* p = head; p != NULL; p = p->next) {
		sum += p->data;
	}
	return sum;
}

int node_search(Node* head,int searchNum) {
	int count = 0;

	for (Node* p = head; p != NULL; p = p->next) {
		if (searchNum == p->data)count++;
	}

	return count;
}

Node* targetNodeDelete(Node* head, int targetNum) {
	for (Node* p = head; p != NULL; p = p->next) {
		if (targetNum == p->next->data) {
			Node* temp = p->next;
			p->next = p->next->next;
			return head;
		}
	}
	printf("찾는 숫자가 없음 \n");
	return head;
}

void main() {
	Node* head = NULL;

	int nodeNum;
	printf("노드의 개수 : ");
	scanf_s("%d", &nodeNum);
	
	for (int i = 0; i < nodeNum; i++) {
		printf("노드 #%d 데이터 : ", i + 1);
		int data;
		scanf_s("%d", &data);
		head = insertNode(head, data);
	}
	printf("\n");

	print_node(head);

	printf("연결 리스트 노드 개수 = %d\n\n", node_count(head));

	printf("연결 리스트의 데이터 합 = %d\n\n", node_sum(head));

	int searchNum;
	printf("탐색할 값을 입력하시오.");
	scanf_s("%d", &searchNum);
	printf("%d는 연결리스트에서 %d번 나타납니다.\n\n", searchNum,node_search(head,searchNum));

	head = targetNodeDelete(head, 5);
	print_node(head);
}