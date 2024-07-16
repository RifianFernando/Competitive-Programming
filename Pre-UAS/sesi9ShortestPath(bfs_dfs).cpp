// BFS
#include <bits/stdc++.h>
using namespace std;

const int MAXV = 1e5;

int V, E;
vector adj[MAXV + 5];
bool visit[MAXV + 5];
queue Q;

void BFS(int start)
{
    visit[start] = true;
    Q.push(start);
    while (!Q.empty())
    {
        int cur = Q.front();
        cout << cur << endl;
        Q.pop();
        for (auto next : adj[cur])
        {
            if (!visit[next])
            {
                visit[next] = true;
                Q.push(next);
            }
        }
    }
}

int main()
{
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(visit, false, sizeof visit);
    BFS(0);
    return 0;
}

/*
5 7
1 2
1 4
1 5
2 3
2 4
3 4
4 5
*/

// BFS, Shortest Path

const int MAXV = 1e5;

int V, E;
vector adj[MAXV + 5];
int dist[MAXV + 5];
int pre[MAXV + 5];
queue Q;

void BFS(int start, int finish)
{
    dist[start] = 0;
    Q.push(start);
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        for (auto next : adj[cur])
        {
            if (dist[next] == -1)
            {
                dist[next] = dist[cur] + 1;
                pre[next] = cur;
                Q.push(next);
            }
        }
    }
    vector path;
    int cur = finish;
    while (cur != -1)
    {
        path.push_back(cur);
        cur = pre[cur];
    }
    reverse(path.begin(), path.end());
    for (auto p : path)
        cout << p + 1 << " ";
    cout << endl;
}

int main()
{
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dist, -1, sizeof dist);
    memset(pre, -1, sizeof pre);
    BFS(0, 6);
    return 0;
}

/*
7 11
1 2
1 3
2 3
2 4
2 5
3 5
4 5
4 6
4 7
5 6
6 7
*/

BFS, Shortest Path, Maze
#include
    using namespace std;

const int MAXN = 100;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool between(int x, int l, int r)
{
    return l <= x && x <= r;
}

int N, M;
string GRID[MAXN + 5];
queue > Q;
int dist[MAXN + 5][MAXN + 5];

bool inside(int x, int y)
{
    return between(x, 0, N - 1) && between(y, 0, M - 1);
}

void BFS(int sx, int sy, int fx, int fy)
{
    dist[sx][sy] = 0;
    Q.push({sx, sy});
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            auto next = cur;
            next.first += dx[i];
            next.second += dy[i];
            if (!inside(next.first, next.second))
                continue;
            if (GRID[next.first][next.second] == '#')
                continue;
            if (dist[next.first][next.second] != -1)
                continue;
            dist[next.first][next.second] = dist[cur.first][cur.second] + 1;
            Q.push(next);
        }
    }
    cout << dist[fx][fy] << endl;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> GRID[i];
    }
    memset(dist, -1, sizeof dist);
    BFS(0, 0, N - 1, M - 1);
    return 0;
}
/*
5 8
..#.....
.##.....
....#.#.
.####.#.
......#.
*/

DFS(with recursion)
#include
using namespace std;

const int MAXV = 1e5;

int V, E;
vector adj[MAXV + 5];
bool visit[MAXV + 5];

void DFS(int cur)
{
    visit[cur] = true;
    cout << cur << endl;
    for (auto next : adj[cur])
    {
        if (!visit[next])
            DFS(next);
    }
}

int main()
{
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(visit, false, sizeof visit);
    DFS(0);
    return 0;
}

/*
5 7
1 2
1 4
1 5
2 3
2 4
3 4
4 5
*/

DFS(with STL Stack)
#include
using namespace std;

const int MAXV = 1e5;

int V, E;
vector adj[MAXV + 5];
bool visit[MAXV + 5];
stack S;

void DFS(int start)
{
    visit[start] = true;
    S.push(start);
    while (!S.empty())
    {
        int cur = S.top();
        cout << cur << endl;
        S.pop();
        for (auto next : adj[cur])
        {
            if (!visit[next])
            {
                visit[next] = true;
                S.push(next);
            }
        }
    }
}

int main()
{
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(visit, false, sizeof visit);
    DFS(0);
    return 0;
}

/*
5 7
1 2
1 4
1 5
2 3
2 4
3 4
4 5
*/

Dijkstra
// MUST USE C++17
#include
    using namespace std;

const int INF = 1e9;

const int MAXV = 1e5;
typedef pair pii;

int V, E;
vector adj[MAXV + 5];
int dist[MAXV + 5];
priority_queue, greater > PQ;

void Dijkstra(int start, int finish)
{
    dist[start] = 0;
    PQ.push({0, start});
    while (!PQ.empty())
    {
        auto [curDist, curNode] = PQ.top();
        PQ.pop();
        for (auto [nextNode, w] : adj[curNode])
        {
            if (dist[nextNode] > curDist + w)
            {
                dist[nextNode] = curDist + w;
                PQ.push({dist[nextNode], nextNode});
            }
        }
    }
    for (int i = 0; i < V; i++)
        cout << dist[i] << " ";
    cout << endl;
}

int main()
{
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    Dijkstra(0, 7);
    return 0;
}

/*
8 11
1 2 3
1 3 5
2 3 1
2 4 6
2 5 3
3 5 4
4 5 2
4 6 7
5 7 5
6 8 4
7 8 3
*/

/*
1. Kalo kita expansi dari node yang tidak optimal, maka hasilnya tidak optimal

2. node dengan distance terkecil adalah node yang optimal

Proof by Contradiciton
Assume node u dengan dist[u] terkecil itu tidak optimal
Artinya, ada node v dengan dist[v]>dist[u] sedemikian sehingga dist[v]+W[v][u]*/