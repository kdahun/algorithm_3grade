# include<stdio.h>
# include<stdlib.h>

# define INF 1000000

typedef struct GraphType {
	int n;
	int** weight;
}GraphType;

int* distance;
int* found;
int* way;

void init_Graph(GraphType* g) {
	scanf_s("%d", &g->n);

	distance = (int*)malloc(sizeof(int) * g->n);
	found = (int*)malloc(sizeof(int) * g->n);
	way = (int*)malloc(sizeof(int) * g->n);

	g->weight = (int**)malloc(sizeof(int*) * g->n);

	for (int i = 0; i < g->n; i++) {
		g->weight[i] = (int*)malloc(sizeof(int) * g->n);
	}

	for(int i=0;i<g->n;i++){
		way[i] = 0;
		for (int j = 0; j < g->n; j++) {
			if(i==j)g->weight[i][j] = 0;
			else g->weight[i][j] = INF;
		}
	}
}

void insert_Edge(GraphType*g,int start,int end, int weight){
	if (start >= g->n || end >= g) {
		printf("정점 오류");
		return;
	}
	g->weight[start][end] = weight;
	g->weight[end][start] = weight;
}

void print_Graph(GraphType* g){
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			printf("%d ", g->weight[i][j]);
		}
		printf("\n");
	}
}

void print_status(GraphType* g) {
	static int step = 1;
	printf("STEP %d : ", step++);
	printf("distance: ");

	for (int i = 0; i < g->n; i++) {
		if (distance[i] == INF) printf(" * ");
		else printf("%2d ", distance[i]);
	}

	printf("\n\n found : ");

	for (int i = 0; i < g->n; i++) {
		printf("%2d ", found[i]);
	}
	printf("\n\n");
}

int choose(int n) {
	int i, min, minpos;

	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}

void shortest_path(GraphType* g, int start) {
	int i, u, w;
	for (i = 0; i < g->n; i++) {
		distance[i] = g->weight[start][i];
		found[i] = 0;
	}

	found[start] = 1;
	distance[start] = 0;

	for (i = 0; i < g->n; i++) {
		print_status(g);
		u = choose(g->n);
		found[u] = 1;
		for (w = 0; w < g->n; w++) {
			if (!found[w])
				if (distance[u] + g->weight[u][w] < distance[w]) {
					distance[w] = distance[u] + g->weight[u][w];
					way[w] = u;// u -> w(만약 여기까지 들어왔으면 u인덱스 다음에 w로 간다.)
				}
		}
	}
}

void printShortestWay(GraphType*g,int start,int end) {
	printf("시작 노드에서 노드 %d까지의 최단 경로는: ", end);
	if (distance[end] == INF || way[end] == -1) {
		printf("경로가 존재하지 않습니다.\n");
		return;
	}

	int node = end;
	int* path = (int*)malloc(sizeof(int) * g->n);

	int i = 0;

	while (node != start) {
		path[i] = node;
		node = way[node];
		i++;
	}
	path[i] = 0;

	printf("path : ");
	for (int j = i; j >= 0; j--) {
		printf("%d -> ", path[j]);
	}
}


void main()
{
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));

	init_Graph(g);

	insert_Edge(g, 0, 1, 7);
	insert_Edge(g, 0, 4, 3);
	insert_Edge(g, 0, 5,10);
	insert_Edge(g, 1, 2, 4);
	insert_Edge(g, 1, 3,10);
	insert_Edge(g, 1, 4, 2);
	insert_Edge(g, 1, 5, 6);
	insert_Edge(g, 2, 3, 2);
	insert_Edge(g, 3, 4,11);
	insert_Edge(g, 3, 5, 9);
	insert_Edge(g, 3, 6, 4);
	insert_Edge(g, 4, 6, 5);

	int start = 0;
	shortest_path(g, start);


	for (int i = 0; i < g->n; i++) {
		if (start != i) {
			printf("종점이 %d일 경우 : ", i);
			printShortestWay(g, start, i);
			printf("\n");
		}
	}
}