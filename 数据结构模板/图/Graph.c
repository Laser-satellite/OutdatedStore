#include<stdio.h>
#include<stdlib.h>

typedef int T;
typedef struct node {
    T data;
    struct node* next;
} Node;
#define MAX_COUNT 100
typedef struct graph {
    int nodeCount;
    Node* nodes[MAX_COUNT];
} Graph;

Graph* createGraph() {
    Graph* new_graph = (Graph*)malloc(sizeof(Graph));
    new_graph->nodeCount = 0;
    for (int i = 0; i < MAX_COUNT; ++i) {
        new_graph->nodes[i] = NULL;
    }
    return new_graph;
}

void addNode(Graph* graph, T data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    graph->nodes[graph->nodeCount++] = new_node;
}

void addEdge(Graph* graph, int srcIdx, int destIdx) {
    Node* srcNode = graph->nodes[srcIdx];
    Node* destNode = graph->nodes[destIdx];
    srcNode->next = destNode;
}

void clear(Graph* graph) {
    for (int i = 0; i < graph->nodeCount; ++i) {
        free(graph->nodes[i]);
    }
}

void viewPath(Graph* graph) {
    for (int i = 0; i < graph->nodeCount; ++i) {
        printf("path of node %d:\n", i);
        
        Node* current = graph->nodes[i];
        printf("%d", current->data);
        int times = 1;
        while (current->next != NULL) {
            // ¼ì²â³É»·
            if (times > graph->nodeCount) {
                printf(" -> ...");
                break;
            }
            current = current->next;
            printf(" -> %d", current->data);
            times++;
        }
        printf("\n");
    }
}

int main() {

    Graph* graph = createGraph();
    
    addNode(graph, 0);
    addNode(graph, 1);
    addNode(graph, 2);
    addNode(graph, 3);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 0);

    viewPath(graph);


    clear(graph);
    free(graph);
    return 0;
}