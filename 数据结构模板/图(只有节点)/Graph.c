#include<stdio.h>
#include<stdlib.h>

typedef int T;
#define MAX_LINKS 100
typedef struct node {
    T data;
    struct node* links[MAX_LINKS];
} Node;
#define MAX_COUNT MAX_LINKS+1
typedef struct graph {
    int nodeCount;
    Node* nodes[MAX_COUNT];
} Graph;
Node* newNode(T data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    for (int i = 0; i < MAX_LINKS; ++i) {
        new_node->links[i] = NULL;
    }
    return new_node;
}
Graph* createGraph() {
    Graph* new_graph = (Graph*)malloc(sizeof(Graph));
    new_graph->nodeCount = 0;
    for (int i = 0; i < MAX_LINKS; ++i) {
        new_graph->nodes[i] = NULL;
    }
    return new_graph;
}
int addNode(Graph* graph, T data) {
    Node* new_node = newNode(data);
    graph->nodes[graph->nodeCount++] = new_node;
    return graph->nodeCount - 1;
}
void addEdge(Graph* graph, int srcIdx, int destIdx) {
    for (int i = 0; i < MAX_LINKS; ++i)
        if (graph->nodes[srcIdx]->links[i] != NULL) {
            graph->nodes[srcIdx]->links[i] = graph->nodes[destIdx];
            return;
    }
}

