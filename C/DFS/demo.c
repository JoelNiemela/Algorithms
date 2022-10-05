#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "DFS.h"

int main() {
	int node_count = 4;
	int adjc[] = {2, 3, 3, 3};

	int** adj_list = malloc(node_count * sizeof(int*));
	for (int i = 0; i < node_count; i++) {
		adj_list[i] = malloc(adjc[i] * sizeof(int));
	}

	adj_list[0][0] = 2;
	adj_list[0][1] = 3;
	adj_list[1][0] = 0;
	adj_list[1][1] = 2;
	adj_list[1][2] = 3;
	adj_list[2][0] = 0;
	adj_list[2][1] = 1;
	adj_list[2][2] = 3;
	adj_list[3][0] = 2;
	adj_list[3][1] = 3;

	bool visited[node_count];
	memset(visited, 0, node_count * sizeof(bool));

	DFS(adj_list, adjc, 0, visited);
}
