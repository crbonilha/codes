#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
const int maxn = 10010;

int n, m;
vector<ii> adj[maxn];
vector<ii> adj2[maxn];
int dist[maxn];

void dfs(int root, int u, int depth, int w);
int dijkstra();

int main() {
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		adj[a].push_back(ii(b, c));
		adj[b].push_back(ii(a, c));
	} 

	for(int i=1; i<=n; i++) {
		dfs(i, i, 0, 0);
	}

	printf("%d\n", dijkstra());
}

int dijkstra() {
	memset(dist, 0x3f, sizeof(int)*(n+1));
	priority_queue<ii> pq;
	pq.push(ii(0, 1));
	dist[1] = 0;

	while(!pq.empty()) {
		ii u = pq.top(); pq.pop();

		if(u.second == n) return dist[n];

		if(dist[u.second] != (-u.first)) continue;

		for(int i=0; i<(int)adj2[u.second].size(); i++) {
			if(dist[ adj2[u.second][i].first ] > dist[u.second]+adj2[u.second][i].second) {
				dist[ adj2[u.second][i].first ] = dist[u.second]+adj2[u.second][i].second;
				pq.push(ii(-dist[ adj2[u.second][i].first ], adj2[u.second][i].first));
			}
		}
	}
	return -1;
}

void dfs(int root, int u, int depth, int w) {
	if(depth == 2) {
		if(root != u) {
			adj2[root].push_back(ii(u, w));
		}
		return;
	}

	for(int i=0; i<(int)adj[u].size(); i++) {
		dfs(root, adj[u][i].first, depth+1, w+adj[u][i].second);
	}
}
