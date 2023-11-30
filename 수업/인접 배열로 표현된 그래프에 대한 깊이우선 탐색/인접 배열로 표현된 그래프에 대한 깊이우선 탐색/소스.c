# include<stdio.h>
# include<stdlib.h>

typedef struct GraphType {
	int n;
	int** adj_mat;
	int* visited;
}GraphType;

void initGraph(GraphType*g) {

	printf("정점의 개수 입력 : ");

	scanf_s("%d", &g->n); // 정점의 개수 입력

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
		printf("그래프 정점 번호 오류");
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

	printf("정점 %d", v);

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

	printf("\n깊이 우선 탐색\n");

	dfs_mat(g, 0);
}