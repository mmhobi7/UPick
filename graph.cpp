#include "graph.h"
#include <math.h>

graph::graph()
{
    index = 0;
}

void graph::insertEdge(restaurant *from, restaurant *to, int weight)
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
    theGraph[mapper[from]].push_back(make_pair(mapper[to], weight));
    theGraph[mapper[to]].push_back(make_pair(mapper[from], weight));
}

bool graph::isEdge(restaurant *from, restaurant *to)
{
    if (v.find(mapper[from]) == v.end() || v.find(mapper[to]) == v.end())
    {
        return false;
    }
    vector<pair<int, int>> adj = theGraph[mapper[from]];
    for (int i = 0; i < adj.size(); i++)
    {
        if (adj[i].first == mapper[to])
        {
            return true;
        }
    }
    return false;
}

int graph::getWeight(restaurant *from, restaurant *to)
{
    if (v.find(mapper[from]) == v.end() || v.find(mapper[to]) == v.end())
    {
        return 0;
    }
    vector<pair<int, int>> adj = theGraph[mapper[from]];
    for (int i = 0; i < adj.size(); i++)
    {
        if (adj[i].first == mapper[to])
        {
            return adj[i].second;
        }
    }
    return 0;
}

vector<restaurant *> graph::getAdjacent(restaurant *vertex)
{
    vector<restaurant *> adj;
    if (v.find(mapper[vertex]) == v.end())
    {
        return adj;
    }
    vector<pair<int, int>> list = theGraph[mapper[vertex]];

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

queue<restaurant *> graph::bfs(restaurant *src)
{
    // return top 100 restaurants from bfs
    std::queue<restaurant *> relatedRestaurants;
    std::queue<restaurant *> q;
    int v = mapper.size();
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    visited[mapper[src]] = true;
    q.push(src);

    while (!q.empty() && relatedRestaurants.size() <= 100)
    {
        // pop top element,
        restaurant *curr = q.front();
        relatedRestaurants.push(curr);
        q.pop();

        // add adj elements
        vector<restaurant *> adj = this->getAdjacent(curr);
        for (auto i = adj.begin(); i != adj.end(); i++)
        {
            if (!visited[mapper[*i]])
            {
                visited[mapper[*i]] = true;
                q.push(*i);
            }
        }
    }
    return relatedRestaurants;
}

long long graph::distance(restaurant *a, restaurant *b)
{
    pair<long long, long long> a_coord;
    pair<long long, long long> b_coord;

    return sqrt(abs(pow(b_coord.first - a_coord.first, 2)) + abs(pow(b_coord.second - a_coord.second, 2)));
}

int graph::getSize()
{
    return v.size();
}