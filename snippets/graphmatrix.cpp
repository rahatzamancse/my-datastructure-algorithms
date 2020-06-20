/// Name: Graph (Adjecency Matrix)
/// Description: Graph Library built for adjecency matrix
/// Detail: I need to add more functions to this
/// Guarantee: class GraphMatrix {
class GraphMatrix {
 public:
  vector< vector<int> > graph;

  GraphMatrix(int nodes): graph(vector<vector<int> >(nodes)) { }
  GraphMatrix(vector<vector<int> > graph): graph(graph) { }

  void dfs(int node) {
    stack<int> st;
    vector<bool> vis(graph.size());
    st.push(node);
    vis[node] = true;
    while (!st.empty()) {
      int x = st.top(); st.pop();

      // Do what you want to do

      REP(i, graph.size(), 0) {
        if (graph[x][i] && !vis[i]) {
          st.push(i);
          vis[i] = true;
        }
      }
    }
  }

  void bfs(int node) {
    queue<int> q;
    vector<bool> vis(graph.size());
    q.push(node);
    vis[node] = true;
    while (!q.empty()) {
      int x = q.front(); q.pop();

      // Do what is needed with node x

      REP(i, 0, graph.size()) {
        if (graph[x][i] && !vis[i]) {
          q.push(i);
          vis[i] = true;
        }
      }
    }
  }

  vector<pair<int, int> > dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    vector<int> dist(graph.size(), INT_MAX);
    vector<pair<int, int> > parents(graph.size());
    pq.emplace(0, src);
    dist[src] = 0;
    parents[src].first = -1;
    parents[src].second = 0;
    vector<bool> flag(graph.size());

    while (!pq.empty()) {
      int u = pq.top().second;
      pq.pop();
      flag[u] = true;

      REP(i, 0, graph.size()) {
        if (graph[u][i]) {
          int weight = graph[u][i];
          if (!flag[i] && dist[i] > dist[u] + weight) {
            dist[i] = dist[u] + weight;
            parents[i].first = u;
            parents[i].second = dist[i];
            pq.emplace(dist[i], i);
          }
        }
      }
    }
    return parents;
  }
};