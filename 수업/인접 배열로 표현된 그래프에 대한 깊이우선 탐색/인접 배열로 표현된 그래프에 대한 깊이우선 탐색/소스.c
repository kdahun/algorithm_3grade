# include<stdio.h>
# include<stdlib.h>

typedef struct GraphType {
	int n;
	int** adj_mat;
	int* visited;
}GraphType;

void initGraph(GraphType*g) {

	printf("������ ���� �Է� : ");

	scanf_s("%d", &g->n); // ������ ���� �Է�

	g->adj_mat = (int**)malloc(sizeof(int*) * g->n);

	g->visited = (int*)malloc(sizeof(int) * g->n);

	for (int i = 0; i < g->n; i++) {
		g->visited[i] = 0;
		g->adj_mat[i] = (int*)malloc(sizeof(int) * g->n);
	}

	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			g->adj_mat[i][j] = 0;
		}
	}


}

void insert_edge(GraphType* g, int start, int end) {
	if (start >= g->n || end >= g->n) {
		printf("�׷��� ���� ��ȣ ����");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

void printGraph(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			printf("%d ", g->adj_mat[i][j]);
		}
		printf("\n");
	}
}

void dfs_mat(GraphType* g, int v) {
	int w;
	g->visited[v] = 1;

	printf("���� %d", v);

	for (w = 0; w < g->n; w++) {
		if (g->adj_mat[v][w] && !g->visited[w]) {
			dfs_mat(g, w);
		}
	}
}

void main() {
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
	initGraph(g);

	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);

	printGraph(g);

	printf("\n���� �켱 Ž��\n");

	dfs_mat(g, 0);
}