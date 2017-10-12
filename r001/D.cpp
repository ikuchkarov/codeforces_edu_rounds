#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>

char field[1000][1000];
int visited[1000][1000];
int ans_for_area[100001];
int visit_flag = 1;

int dfs(int i, int j) {
	if (visited[i][j]) return 0;
	
	visited[i][j] = visit_flag;
	
	int pictures = 0;
	if (field[i-1][j] == '*') ++pictures; else pictures += dfs(i-1, j);
	if (field[i+1][j] == '*') ++pictures; else pictures += dfs(i+1, j);
	if (field[i][j-1] == '*') ++pictures; else pictures += dfs(i, j-1);
	if (field[i][j+1] == '*') ++pictures; else pictures += dfs(i, j+1);
	
	ans_for_area[visit_flag] = pictures;
	return pictures;
}

int main() {
	std::ios_base::sync_with_stdio(0);
	int n, m, k;
	std::cin >> n >> m >> k;
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			std::cin >> field[i][j];
		}
	
	for (int t = 0; t < k; ++t) {
		int i, j;
		std::cin >> i >> j;
		--i; --j;
		
		if (!visited[i][j]) {
			dfs(i, j);			
			++visit_flag;
		}
		std::cout << ans_for_area[visited[i][j]] << std::endl;
	}
}
