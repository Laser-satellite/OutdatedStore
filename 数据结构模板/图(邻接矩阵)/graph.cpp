#include<stdio.h>
#include<stdlib.h>

#include<iostream>
#include<vector>

typedef int T;
#define MAX_COUNT 20
typedef struct graph {
    int nodeCount;
    T nodes[MAX_COUNT]; // Ïñ¶Ñ
    int adjactMatrix[MAX_COUNT][MAX_COUNT];
} Graph;

Graph* createGraph();
int addNode(Graph* graph, T data);
void addEdge(Graph* graph, int srcIdx, int destIdx);
void clear(Graph* graph);

// vector<int> node[MAX_COUNT];