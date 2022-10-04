#include "DFS.h"

#include <vector>

int main() {
	std::vector<std::vector<int> > adj_list = {
		{1, 2},
		{0, 2, 3},
		{0, 1, 3},
		{1, 2},
	};

	std::vector<bool> visited(4, false);

	DFS(adj_list, 0, visited);
}
