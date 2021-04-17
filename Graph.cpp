#include "Graph.hpp"
void Graph::insertEdge(Restaurant* from, Restaurant* to, int weight)
{
    // add restaurant to mapper
    if(mapper.find(from) == mapper.end()) {
        mapper[from] = index++;
    }
    if(mapper.find(to) == mapper.end()) {
        mapper[to] = index++;
    }
    // add vertex to map
    if(v.find(mapper[from]) == v.end()) {
        v.insert(mapper[from]);
    }
    if(v.find(mapper[to]) == v.end()) {
        v.insert(mapper[to]);
    }

    // add to main graph map
    graph[mapper[from]].push_back(make_pair(mapper[to], weight));
}

bool Graph::isEdge(Restaurant* from, Restaurant* to)
{
    if(v.find(mapper[from]) == v.end() || v.find(mapper[to]) == v.end()) {
        return false;
    }
    vector<pair<int,int>> adj = graph[mapper[from]];
    for(int i = 0; i < adj.size(); i++) {
        if(adj[i].first == mapper[to]) {
            return true;
        }
    }
    return false;
}

int Graph::getWeight(Restaurant* from, Restaurant* to)
{
    if(v.find(mapper[from]) == v.end() || v.find(mapper[to]) == v.end()) {
        return 0;
    }
    vector<pair<int,int>> adj = graph[mapper[from]];
    for(int i = 0; i < adj.size(); i++) {
        if(adj[i].first == mapper[to]) {
            return adj[i].second;
        }
    }
    return 0;

}

vector<Restaurant*> Graph::getAdjacent(Restaurant* vertex)
{
    vector<Restaurant*> adj;
    if(v.find(mapper[vertex]) == v.end()) {
        return adj;
    }
    vector<pair<int,int>> list = graph[mapper[vertex]];

    for(int i = 0; i < list.size(); i++) {
        // find vertex to add
        int key = list[i].first;
        if(v.find(key) != v.end()) {
            unordered_map<Restaurant*, int>::iterator iter;
            for(iter = mapper.begin(); iter != mapper.end(); iter++) {
                if(iter->second == key) {
                    adj.push_back(iter->first);
                    break;
                }
            }
        }
    }
    sort(adj.begin(), adj.end());
    return adj;
}
