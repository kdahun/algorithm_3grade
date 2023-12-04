# include<stdio.h>
# include<stdlib.h>

typedef struct GraphType {
	int v;
	int e;
	int** weight;
}GraphType;

int* distance;
int* found;

void init(GraphType* g) {
	

	g->weight = (int**)malloc(sizeof(int*) * g->v);
	for (int i = 0; i < g->v; i++) {
		g->weight[i] = (int*)malloc(sizeof(int) * g->v);
	}

	for (int i = 0; i < g->v; i++) {
		for (int j = 0; j < g->v; j++) {
			g->weight[i][j] = 30000001;
		}
	}
}

void insert_edge(GraphType* g, int start, int end, int weight) {
	g->weight[start][end] = weight;
}

int choose(int v) {
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;

	for (i = 0; i < v; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}

void print_status(GraphType* g) {
	static int step = 1;
	printf("STEP %d : ", step++);
	printf("distance : ");
	for (int i = 0; i < g->v; i++) {
		if (distance[i] == 30000001) printf(" * ");
		else printf("%d ", distance[i]);
	}
	printf("\n");
	printf(" found: ");
	for (int i = 0; i < g->v; i++) {
		printf("%d ", found[i]);
	}
	printf("\n\n");
}

void shortest_path(GraphType* g, int start) {
	int i, u, w;
	
	for (i = 0; i < g->v; i++) {
		distance[i] = g->weight[start][i];
		found[i] = 0;
	}
	found[start] = 1;

	distance[start] = 0;

	for (i = 0; i < g->v - 1; i++) {
		//print_status(g);
		u = choose(g->v);
		found[u] = 1;
		for (w = 0; w < g->v; w++) {
			if (!found[w]) {
				if (distance[u] + g->weight[u][w] < distance[w]) {
					distance[w] = distance[u] + g->weight[u][w];
				}
			}
		}
	}
}

void main()
{
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
	int v, e; // v는 정점의 개수, e는 간선의 개수
	scanf_s("%d %d", &v, &e);
	g->v = v;
	g->e = e;
	init(g);

	distance = (int*)malloc(sizeof(int)*v);
	found = (int*)malloc(sizeof(int) * v);

	int start_point = 0;
	int start, end, weight;
	scanf_s("%d", &start_point);
	for (int i = 0; i < g->e; i++) {
		scanf_s("%d %d %d", &start, &end, &weight);
		insert_edge(g, start-1, end-1, weight);
	}

	shortest_path(g, start_point-1);

	for (int i = 0; i < v; i++) {
		if (distance[i] == 30000001) printf("INF\n");
		else printf("%d \n", distance[i]);
	}
}