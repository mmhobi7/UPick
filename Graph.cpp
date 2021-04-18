#include "Graph.h"
void Graph::insertEdge(Restaurant *from, Restaurant *to, int weight)
{
    // add restaurant to mapper
    if (mapper.find(from) == mapper.end())
    {
        mapper[from] = index;
        reverseMapper[index] = from;
        index++;
    }
    if (mapper.find(to) == mapper.end())
    {
        mapper[to] = index;
        reverseMapper[index] = to;
        index++;
    }
    // add vertex to map
    if (v.find(mapper[from]) == v.end())
    {
        v.insert(mapper[from]);
    }
    if (v.find(mapper[to]) == v.end())
    {
        v.insert(mapper[to]);
    }

    // add to main graph map
    graph[mapper[from]].push_back(make_pair(mapper[to], weight));
    graph[mapper[to]].push_back(make_pair(mapper[from], weight));
}

bool Graph::isEdge(Restaurant *from, Restaurant *to)
{
    if (v.find(mapper[from]) == v.end() || v.find(mapper[to]) == v.end())
    {
        return false;
    }
    vector<pair<int, int>> adj = graph[mapper[from]];
    for (int i = 0; i < adj.size(); i++)
    {
        if (adj[i].first == mapper[to])
        {
            return true;
        }
    }
    return false;
}

int Graph::getWeight(Restaurant *from, Restaurant *to)
{
    if (v.find(mapper[from]) == v.end() || v.find(mapper[to]) == v.end())
    {
        return 0;
    }
    vector<pair<int, int>> adj = graph[mapper[from]];
    for (int i = 0; i < adj.size(); i++)
    {
        if (adj[i].first == mapper[to])
        {
            return adj[i].second;
        }
    }
    return 0;
}

vector<Restaurant *> Graph::getAdjacent(Restaurant *vertex)
{
    vector<Restaurant *> adj;
    if (v.find(mapper[vertex]) == v.end())
    {
        return adj;
    }
    vector<pair<int, int>> list = graph[mapper[vertex]];

    for (int i = 0; i < list.size(); i++)
    {
        // find vertex to add
        int key = list[i].first;
        if (v.find(key) != v.end())
        {
            adj.push_back(reverseMapper[key]);
        }
    }

    sort(adj.begin(), adj.end());
    return adj;
}

queue<Restaurant *> Graph::bfs(Restaurant* src) {
    // return top 100 restaurants from bfs
    std::queue<Restaurant*> relatedRestaurants;
    std::queue<Restaurant*> q;
    int v = mapper.size();
    bool* visited = new bool[v];
    for(int i = 0; i < v; i++) {
        visited[i] = false;
    }

    visited[mapper[src]] = true;
    q.push(src);

    while(!q.empty() && relatedRestaurants.size() <= 100) {
        // pop top element,
        Restaurant* curr = q.front();
        relatedRestaurants.push(curr);
        q.pop();

        // add adj elements
        vector<Restaurant*> adj = this->getAdjacent(curr);
        for(auto i = adj.begin(); i != adj.end(); i++) {
            if(!visited[mapper[*i]]) {
                visited[mapper[*i]] = true;
                q.push(*i);
            }
        }
    }
    return relatedRestaurants;
}

long long Graph::distance(Restaurant *a, Restaurant *b) {
    pair<long long, long long> a_coord;
    pair<long long, long long> b_coord;

    return sqrt(pow(b_coord.first - a_coord.first, 2) + pow(b_coord.second - a_coord.second, 2));
}
