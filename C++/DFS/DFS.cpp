#include "DFS.h"

void DFS(std::vector<std::vector<int> >& adj, int pos, std::vector<bool>& visited) {
	visited[pos] = true;

	for (const int node : adj[pos]) {
		if (!visited[node]) {
			DFS(adj, node, visited);
		}
	}
}
