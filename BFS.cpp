#include <bits/stdc++.h>

using namespace std;

//use stack instead of queue for DFS

void BFS(int **edges,int n)
{
    bool *visited = new bool[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            queue<int> waiting;
            waiting.push(i);
            visited[i] = true;
            while (waiting.empty() == false)
            {
                int curr = waiting.front();
                cout << curr << " ";
                waiting.pop();
                for (int j = 0; j < n; j++)
                {
                    if (visited[j])
                        continue;
                    if (edges[curr][j])
                    {
                        waiting.push(j);
                        visited[j] = true;
                    }
                }
            }
        }
    }
}


int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];

    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    BFS(edges,n);
}