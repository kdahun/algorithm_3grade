# include<stdio.h>
# include<stdlib.h>

# define INF 1000000

int distance[20000];
int found[20000];


typedef struct GraphNode
{
	int vertex;
	int weight;
	struct GrapNode* link;
}GraphNode;

typedef struct GraphType {
	int n;
	GraphNode* adj_list[20000];
}GraphType;

void init(GraphType* g) {
	int v;
	g->n = 0;
	for (v = 0; v < 20000; v++) {
		g->adj_list[v] = NULL;
	}
}

void insert_vertex(GraphType* g, int v) {
	if (((g->n) + 1) > 20000) {
		printf("그래프 : 정점의 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v,int weight) {
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		printf("그래프 : 정점 번호 오류");
		return;
	}

	node = (GraphNode*)malloc(sizeof(GraphNode));

	node->vertex = v;
	node->weight = weight;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

void print_adj_list(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		GraphNode* p = g->adj_list[i];
		printf("정점 %d의 인접 리스트", i);
		while (p != NULL) {
			printf("-> %d", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}

void print_status(GraphType* g) {
	static int step = 1;
	printf("STEP %d : ", step++);
	printf("distance: ");

	for (int i = 0; i < g->n; i++) {
		if (distance[i] == INF)
			printf(" * ");
		else {
			printf("%d ", distance[i]);
		}
	}

	printf("\n");
	printf(" found: ");
	for (int i = 0; i < g->n; i++)
		printf("%d ", found[i]);
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
		distance[i] = INF;
		found[i] = 0;
	}
	GraphNode* p = g->adj_list[start];
	while (p != NULL) {
		distance[p->vertex] = p->weight;
		p = p->link;
	}
	distance[start] = 0;
	found[start] = 1;

	for (i = 0; i < g->n - 1; i++) {
		print_status(g);
		u = choose(g->n);
		found[u] = 1;
		for (w = 0; w < g->n; w++) {
			if (!found[w]) {
				GraphNode* p = g->adj_list[u];
				int weight = -1;
				while (p != NULL) {
					if (p->vertex == w) {
						weight = p->weight;
						break;
					}
					p = p->link;
				}
				if(weight!=-1)
					if (distance[u] + weight < distance[w]) {
						distance[w] = distance[u] + weight;
					}
			}
		}
	}

}

int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));

	init(g);
	
	for (int i = 0; i < 7; i++) {
		insert_vertex(g, i);
	}

	insert_edge(g, 0, 1, 7);
	insert_edge(g, 1, 0, 7);
	insert_edge(g, 0, 4, 3);
	insert_edge(g, 4, 0, 3);
	insert_edge(g, 0, 5, 10);
	insert_edge(g, 5, 0, 10);
	insert_edge(g, 1, 2, 4);
	insert_edge(g, 2, 1, 4);
	insert_edge(g, 1, 3, 10);
	insert_edge(g, 3, 1, 10);
	insert_edge(g, 1, 4, 2);
	insert_edge(g, 4, 1, 2);
	insert_edge(g, 1, 5, 6);
	insert_edge(g, 5, 1, 6);
	insert_edge(g, 2, 3, 2);
	insert_edge(g, 3, 2, 2);
	insert_edge(g, 3, 4, 11);
	insert_edge(g, 4, 3, 11);
	insert_edge(g, 3, 5, 9);
	insert_edge(g, 5, 3, 9);
	insert_edge(g, 3, 6, 4);
	insert_edge(g, 6, 3, 4);
	insert_edge(g, 4, 6, 5);
	insert_edge(g, 6, 4, 5);

	print_adj_list(g);

	shortest_path(g, 0);
	return 0;
}