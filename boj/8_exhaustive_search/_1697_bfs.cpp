#include <cstdio>
#include <queue>
#define MAX 200000

int N, K;

int bfs() {
	bool visited[MAX + 1] = {};
	std::queue<int> q;

	int ans = 0, seg = 1;
	q.push(N);
	while (!q.empty()) {
		int X, next_seg = 0;
		while (seg--) {
			X = q.front(), q.pop();
			visited[X] = true;

			if (X == K)
				return ans;
			if (X - 1 >= 0 && !visited[X - 1])
				q.push(X - 1), next_seg++;
			if (X + 1 <= MAX && !visited[X + 1])
				q.push(X + 1), next_seg++;
			if (2 * X <= MAX && !visited[2 * X])
				q.push(2 * X), next_seg++;
		}
		ans++, seg = next_seg;
	}
	return -1;
}

int main() {
	scanf("%d %d", &N, &K);
	printf("%d", bfs());
}