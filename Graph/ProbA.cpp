#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

bool between(int x, int l, int r) {
	return l <= x && x <= r;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


int R, C;
bool GRID[210][210];
int vis[210][210];
queue<pii> BFS;

bool in_grid(int x, int y) {
	return between(x, 0, R - 1) && between(y, 0, C - 1);
}

bool in_jiggly(int i, int j, int x, int y, int r) {
	i -= x;
	j -= y;
	return i * i + j * j <= r * r;
}

int calc() {
	memset(vis, -1, sizeof vis);
	vis[0][0] = 0;
	BFS.push({0, 0});
	while (!BFS.empty()) {
		auto cur = BFS.front();
		BFS.pop();
		for (int i = 0; i < 4; i++) {
			auto next = cur;
			next.first += dx[i];
			next.second += dy[i];
			if (!in_grid(next.first, next.second)) continue;
			if (!GRID[next.first][next.second]) continue;
			if (vis[next.first][next.second] != -1) continue;
			vis[next.first][next.second] = vis[cur.first][cur.second] + 1;
			BFS.push(next);
		}
	}
	return vis[R - 1][C - 1];
}

int main() {
	while (true) {
		cin >> R >> C;
		if (R == 0 && C == 0) break;
		memset(GRID, true, sizeof GRID);
		
		int tembok;
		cin >> tembok;
		while (tembok--) {
			int x, y;
			cin >> x >> y;
			x--; y--;
			GRID[x][y] = false;
		}
		
		int jiggly;
		cin >> jiggly;
		while (jiggly--) {
			int x, y, r;
			cin >> x >> y >> r;
			x--; y--;
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (in_jiggly(i, j, x, y, r)) GRID[i][j] = false;
				}
			}
		}
		int ans = calc();
		if (ans == -1) cout << "Impossible." << endl;
		else cout << ans << endl;
	}
	return 0;
}