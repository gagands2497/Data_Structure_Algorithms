//find all the connected components
//we will use set of sets of connected components
//use DFS for traversal
#include <bits/stdc++.h>

using namespace std;

void IO()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
}

void DFS(vector<int> *edges, int start, unordered_set<int> *component, bool *visited)
{
    visited[start] = true;
    component->insert(start);
    for (int i = 0; i < edges[start].size(); i++)
    {
        int next = edges[start][i];
        if (visited[next] == false)
        {
            DFS(edges, next, component, visited);
        }
    }
}

unordered_set<unordered_set<int> *> *getComponents(vector<int> *edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    unordered_set<unordered_set<int> *> *output;
    output = new unordered_set<unordered_set<int> *>();
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            int startIndex = i;
            unordered_set<int> *component = new unordered_set<int>();
            DFS(edges, startIndex, component, visited);
            output->insert(component);
        }
    }
    delete[] visited;
    return output;
}

void printComponent(unordered_set<int> *component)
{
    unordered_set<int>::iterator itr = component->begin();
    while (itr != component->end())
    {
        int index = *itr + 1;
        cout << index << " ";
        itr++;
    }
    cout << endl;
}

int main()
{
    IO();
    int n, e;
    cin >> n >> e;
    vector<int> *edges = new vector<int>[n];

    for (int i = 0; i < e; i++)
    {
        int s, d;
        cin >> s >> d;
        edges[s - 1].push_back(d - 1);
        edges[d - 1].push_back(s - 1);
    }
    unordered_set<unordered_set<int> *> *components = getComponents(edges, n);
    unordered_set<unordered_set<int> *>::iterator itr1 = components->begin();
    while (itr1 != components->end())
    {
        unordered_set<int> *component = *itr1;
        printComponent(component);
        delete component;
        itr1++;
    }
    //delete []components;
    //delete edges;
}