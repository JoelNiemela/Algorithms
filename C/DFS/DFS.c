#include "DFS.h"

void DFS(int** adj, int* adjc, int pos, bool* visited) {
	visited[pos] = true;

	for (int i = 0; i < adjc[pos]; i++) {
		int node = adj[pos][i];
		if (!visited[node]) {
			DFS(adj, adjc, node, visited);
		}
	}
}
