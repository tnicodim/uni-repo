#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct node {
    int key;
    struct node* next;
};

struct Graph {
    int nkeys;
    struct node** adjLists;
};

struct node* createNode(int k) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->key = k;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createAGraph(int keys) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->nkeys = keys;
    graph->adjLists = malloc(keys * sizeof(struct node*));
    int i;
    for (i = 0; i < keys; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int x, int y) {
    struct node* newNode = createNode(y);
    newNode->next = graph->adjLists[x];
    graph->adjLists[x] = newNode;
    newNode = createNode(x);
    newNode->next = graph->adjLists[y];
    graph->adjLists[y] = newNode;
}

void printGraph(struct Graph* graph) {
    int k;
    for (k = 0; k < graph->nkeys; k++) {
        struct node* temp = graph->adjLists[k];
        printf("\n[%d]:", k);
        while (temp) {
            printf(" -> %d", temp->key);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int x,y,N,A,i;
    printf("Number of nodes: ");
    scanf("%d", &N);
    struct Graph* graph = createAGraph(N);
    printf("Number of arcs: ");
    scanf("%d", &A);
    for (i = 1; i <= A; i++) {
        printf("Arcs: ");
        scanf("%d %d", &x, &y);
        addEdge(graph, x, y);
    }
    printGraph(graph);
    return 0;
}