/// Name: Graph (Adjecency list)
/// Description: Graph Library built for adjecency list
/// Detail: I need to add more functions to this
/// Guarantee: class GraphList {

// a = [{b,5}, {c,10}]
// b = [{b,5}, {c,10}]
class GraphList {
 public:
  vector< vector<pair<int, int> > > graph;

  GraphList(int nodes): graph(vector<vector<pair<int, int> > >(nodes)) { }
  GraphList(vector<vector<pair<int, int> > > graph): graph(graph) { }

  void dfs(int node) {
    stack<int> st;
    vector<bool> vis(graph.size());
    st.push(node);
    vis[node] = true;
    while (!st.empty()) {
      int x = st.top(); st.pop();

      // Do what you want to do

      REP(i, graph[x].end(), graph[x].begin()) {
        if (!vis[i->first]) {
          st.push(i->first);
          vis[i->first] = true;
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

      REP(i, graph[x].begin(), graph[x].end()) {
        if (!vis[i->first]) {
          q.push(i->first);
          vis[i->first] = true;
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

      REP(i, graph[u].begin(), graph[u].end()) {
        int v = i->first;
        int weight = i->second;
        if (!flag[v] && dist[v] > dist[u] + weight) {
          dist[v] = dist[u] + weight;
          parents[v].first = u;
          parents[v].second = dist[v];
          pq.emplace(dist[v], v);
        }
      }
    }
    return parents;
  }
};
