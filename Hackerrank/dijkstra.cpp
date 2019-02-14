/*
 * Complete the 'minCost' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

int minCost(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    typedef std::tuple<int, int> tup;
    // create graph
    vector<vector<int>> G(g_nodes+1);
    for(int i=0; i<=g_nodes; i++)
        G[i].resize(g_nodes+1);
    for(int i=1; i<=g_nodes; i++) {
        for(int j=1; j<=g_nodes; j++) {
            G[i][j] = 1;
        }
    }
    for(int i=0; i<g_from.size(); i++) {
        G[g_from[i]][g_to[i]] = g_weight[i];
    }
    // dijkstra
    vector<int> dist(g_nodes+1);
    int infty{std::numeric_limits<int>::max()};
    fill(dist.begin(), dist.end(), infty);
    dist[1] = 0;
    priority_queue<tup, std::vector<tup>, std::greater<tup>> queue;
    for(int i=1; i<=g_nodes; i++) {
        queue.push(std::make_tuple(dist[i], i));
    }
    while(!queue.empty()) {
        auto el = queue.top();
        queue.pop();
        auto id = std::get<1>(el);
        for(int j=1; j<=g_nodes; j++) {
            if(j != id) {
                auto new_dist = dist[id] + G[id][j];
                if(new_dist < dist[j]) { // overflow
                    dist[j] = new_dist;
                    queue.push(std::make_tuple(dist[j], j));
                }
            }
        }
    }
    return dist[g_nodes];
}

