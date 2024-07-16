#define _CRT_SECURE_NO_WARNINGS
#define NMAX 10
#define white 1
#define grey 2
#define black 3
#include<stdio.h>
#include<stdlib.h>

int mat[NMAX][NMAX], wmat[NMAX][NMAX], nodes[NMAX], counter, nrnodes, bfs[NMAX], color[NMAX], time, ti[NMAX], tf[NMAX], visits[NMAX] = { 0 }, numvisits = 1, djD[NMAX], djT[NMAX];
char menu[200] = "1. Initialization\n2. Insert node\n3. Insert edge\n4. Delete node\n5. Delete edge\n6. Print matrix\n7. Depth-first search\n8. Prim's Algorithm\n9. Dijkstra's Algorithm\n10. Exit\nOption: ";

void initArrays() {
	int i,j;
	for (i = 0; i < NMAX; i++) {
		nodes[i] = 0;
		for (j = 0; j < NMAX; j++) {
			mat[i][j] = 0;
			wmat[i][j] = 999;
		}
	}
	printf("Initialization successful!\n\n");
}
void printMatrix() {
	int i, j;
	printf("\n");
	for (i = 0; i < NMAX; i++)
		printf("%d ", i);
	printf("\n-------------------\n");
	for (i = 0; i < NMAX; i++)
		printf("%d ", nodes[i]);
	printf("\n-------------------\n\n\n ");
	for (i = 0; i < NMAX; i++)
		printf(" %d", i);
	printf("\n  -------------------");
	for (i = 0; i < NMAX; i++) {
		printf("\n%d|", i);
		for (j = 0; j < NMAX; j++)
			printf("%d ", mat[i][j]);
	}
	printf("\n\n ");
	for (i = 0; i < NMAX; i++)
		printf(" %d", i);
	printf("\n  -------------------");
	for (i = 0; i < NMAX; i++) {
		printf("\n%d|", i);
		for (j = 0; j < NMAX; j++)
			printf("%d ", wmat[i][j]);
	}
		printf("\n\n");
}
void insertNode(int i) {
	if (!nodes[i])
		nodes[i]++;
	else
		printf("\nNode %d is already existent\n", i);
}
void insertEdge(int i, int j, int weight) {
	if (nodes[i] && nodes[j]) {
		mat[i][j] = 1;
		mat[j][i] = 1;
		wmat[i][j] = weight;
		wmat[j][i] = weight;
	}
	else
		printf("\nUnable to create an edge. One or more nodes are nonexistent!\n");
}
void deleteEdge(int i, int j) {
	if (!mat[i][j])
		printf("\nERROR! No edge to delete!\n");
	else {
		mat[i][j] = 0;
		mat[j][i] = 0;
		printf("\nEdge deletion successful!\n");
	}
}
void deleteNode(int i) {
	int j;
	if (!nodes[i])
		printf("\nERROR! Node nonexistent!\n");
	else {
		nodes[i] = 0;
		for (j = 0; j < NMAX; j++)
			if (mat[i][j])
				deleteEdge(i, j);
	}
}
void depthSearch(int k) {
	int i;
	printf("%d ", k);
	color[k] = grey;
	time++;
	ti[k] = time;
	for (i = 0; i < NMAX; i++)
		if (mat[i][k])
			if (color[i] == white)
				depthSearch(i);
	color[k] = black;
	time++;
	tf[k] = time;
}
void depthTraverse() {
	int i,j;
	printf("\n");
	for (i = 0; i < NMAX; i++)
			if (nodes[i])
				color[i] = white;
	time = 0;
	for (i = 0; i < NMAX; i++)
		for (j = 0; j < NMAX; j++)
				if (mat[i][j])
					if (color[i] == white)
						depthSearch(i);
	printf("\ntime:\n");
	for (i = 1; i < NMAX; i++)
		printf("[%d] %d %d\n", i, ti[i], tf[i]);
	printf("\n");
}
int prim() {
	int u, v, i, j, min, mincost = 0;
	visits[1] = 1;
	printf("\n");
	while (numvisits < nrnodes){		
		for (i = 1, min = 999; i <= nrnodes; i++)
			for (j = 1; j <= nrnodes; j++)
				if (wmat[i][j] < min)
					if (visits[i] != 0){
						min = wmat[i][j];
						u = i;
						v = j;
					}
		if (visits[u] == 0 || visits[v] == 0){
			printf("\n Edge %d:(%d %d) cost:%d", numvisits++, u, v, min);
			mincost += min;
			visits[v] = 1;
		}
		wmat[u][v] = wmat[v][u] = 9999;
	}
	return mincost;
}
int dijkstra() {
	return 1;
}
int main() {
	int opt, x, z, i, weight;
	while (1) {
		nrnodes = 0;
		counter = 0;
		for (i = 0; i < NMAX; i++)
			if (nodes[i])
				nrnodes++;
		printf("%s", menu);
		scanf("%d", &opt);
		printf("\n");
		switch (opt) {
		case 1:{
			initArrays();
			insertNode(1);
			insertNode(2);
			insertNode(3);
			insertNode(4);
			insertNode(5);
			insertNode(6);
			insertNode(7);
			insertNode(8);
			insertEdge(1, 2, 2);
			insertEdge(1, 4, 3);
			insertEdge(1, 3, 9);
			insertEdge(1, 7, 6);
			insertEdge(2, 5, 4);
			insertEdge(5, 3, 5);
			insertEdge(5, 6, 7);
			insertEdge(6, 3, 3);
			insertEdge(6, 8, 4);
			insertEdge(6, 7, 8);
			insertEdge(7, 8, 2);
			insertEdge(7, 4, 2);
			insertEdge(8, 4, 1);
			break;
		}
		case 2:{
			printf("Node to be inserted: ");
			scanf("%d", &x);
			insertNode(x);
			break;
		}
		case 3:{
			printf("Edge to be inserted and weight: ");
			scanf("%d %d %d", &x, &z, &weight);
			insertEdge(x, z, weight);
			break;
		}
		case 4:{
			printf("Node to be deleted: ");
			scanf("%d", &x);
			deleteNode(x);
			break;
		}
		case 5:{
			printf("Edge to be deleted: ");
			scanf("%d %d", &x, &z);
			deleteEdge(x, z);
			break;
		}
		case 6:{
			printMatrix();
			break;
		}
		case 7:{
			depthTraverse();
			break;
		}
		case 8:{
			printf("\n\nMin cost %d\n\n", prim());
			break;
		}
		case 9:{
			dijkstra();
			break;
		}
		case 10:{
			exit(1);
			break;
		}
		default:{
			printf("\Invalid option!\n\n");
			break;
		}
		}
	}
	return 0;
}