//Strongly connected components
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> *edges, int start, bool *visited, stack<int> &finishStack)
{
    visited[start] = true;
    for (int i = 0; i < edges[start].size(); i++)
    {
        int adjacent = edges[start][i];
        if (!visited[adjacent])
        {
            dfs(edges, adjacent, visited, finishStack);
        }
    }
    finishStack.push(start);
}

void dfs2(vector<int> *edgesT, int start, unordered_set<int> *component, bool *visited)
{
    visited[start] = true;
    component->insert(start);
    for (int i = 0; i < edgesT[start].size(); i++)
    {
        int adjacent = edgesT[start][i];
        if (!visited[adjacent])
        {
            dfs2(edgesT, adjacent, component, visited);
        }
    }
}

unordered_set<unordered_set<int> *> *getSCC(vector<int> *edges, vector<int> *edgesT, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    stack<int> finishedVertices;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(edges, i, visited, finishedVertices);
        }
    }
    unordered_set<unordered_set<int> *> *output = new unordered_set<unordered_set<int> *>();
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    while (finishedVertices.size() != 0)
    {
        int element = finishedVertices.top();
        finishedVertices.pop();
        if (!visited[element])
        {
            unordered_set<int> *component = new unordered_set<int>();
            dfs2(edgesT, element, component, visited);
            output->insert(component);
        }
    }
    return output;
}

void printComponents(unordered_set<unordered_set<int> *> *components)
{
    unordered_set<unordered_set<int> *>::iterator i = components->begin();

    while (i != components->end())
    {
        unordered_set<int> *component = *i;
        unordered_set<int>::iterator j = component->begin();
        while (j != component->end())
        {
            cout << (*j) + 1 << " ";
            j++;
        }
        cout << endl;
        delete component;
        i++;
    }
}
signed main()
{
    int n, e;
    cin >> n >> e;
    vector<int> *edges = new vector<int>[n];
    vector<int> *edgesT = new vector<int>[n]; //for transpose edges

    for (int i = 0; i < e; i++)
    {
        int s, d;
        cin >> s >> d;
        edges[s - 1].push_back(d - 1);
        edgesT[d - 1].push_back(s - 1);
    }

    unordered_set<unordered_set<int> *> *components = getSCC(edges, edgesT, n);
    printComponents(components);
    delete components;
    delete[] edges;
    delete[] edgesT;
}