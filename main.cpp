#include <iostream>
#pragma warning(disable:4996)
using namespace std;

struct Edge {
        int source, destination, cost;
};

struct Graph {
        int vert, edg;
        struct Edge* edges;
};

void BellmanFord(Graph* graph, int src, int* costs, bool& inf);

int main() {

        int vertices, edges, tests, src, dest, src_now;
        src = INT_MAX;
        bool inf = false;
        scanf("%i", &vertices);
        scanf("%i", &edges);
        Graph* graph = (Graph*)malloc(sizeof(Graph));
        graph->edg = edges;
        graph->vert = vertices;
        graph->edges = (Edge*)malloc(sizeof(Edge) * edges);
        for (int i = 0; i < edges; i++) {
                scanf("%i\n%i\n%i", &graph->edges[i].source, &graph->edges[i].destination, &graph->edges[i].cost);
        }
        int * costs = (int*)malloc(sizeof(int) * vertices);
        scanf("%i", &tests);
        for (int i = 0; i < tests; i++) {
                scanf("%i\n%i", &src_now, &dest);
                if (src != src_now) {
                        src = src_now;
                        inf = false;
                        BellmanFord(graph, src, costs, inf);
                }
                if (costs[dest] != INT_MAX && inf == false) {
                        printf("%i\n", costs[dest]);
                }
                else if (inf == true) {
                        printf("-inf\n");
                }
                else {
                        printf("!\n");
                }
        }

        free(graph->edges);
        free(graph);
        free(costs);

        return 0;
}

void BellmanFord(Graph* graph, int src, int* costs, bool& inf) {
        int vertices = graph->vert;
        int edges = graph->edg;

        for (int i = 0; i < vertices; i++) {
                costs[i] = INT_MAX;
        }
        costs[src] = 0;

        for (int i = 1; i <= vertices - 1; i++) {
                for (int j = 0; j < edges; j++) {
                        int u = graph->edges[j].source;
                        int v = graph->edges[j].destination;
                        int cost = graph->edges[j].cost;
                        if (costs[u] != INT_MAX && costs[u] + cost < costs[v]) {
                                costs[v] = costs[u] + cost;
                        }
                }
        }

        for (int i = 0; i < edges; i++) {
                int u = graph->edges[i].source;
                int v = graph->edges[i].destination;
                int cost = graph->edges[i].cost;
                if (costs[u] != INT_MAX && costs[u] + cost < costs[v]) {
                        inf = true;
                }
        }
}
