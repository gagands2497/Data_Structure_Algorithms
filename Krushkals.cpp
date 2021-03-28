#include <bits/stdc++.h>

using namespace std;

class edge
{
public:
    int source, destination, weight;
};

class UF
{
    int *parent;
    int size;

public:
    UF(int n) //how long the set is
    {
        parent = new int[n];
        size = n;
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int i)
    {
        while (i != parent[i])
        {
            i = parent[i];
        }
        return i;
    }

    void combine(int i, int j)
    {
        int iParent = findParent(i);
        int jParent = findParent(j);
        if (iParent == jParent) //They belong to the same set
            return;

        else if (i > j)
        {
            parent[iParent] = jParent;
        }
        else
        {
            parent[jParent] = iParent;
        }
    }

    bool sameSet(int i, int j)
    {
        int iParent = findParent(i);
        int jParent = findParent(j);
        if (iParent == jParent)
            return true;
        else
            return false;
    }

    void printSet()
    {
        for (int i = 0; i < size; i++)
        {
            cout << parent[i] << " ";
        }
        cout << endl;
    }
};

bool compare(edge e1, edge e2)
{
    return e1.weight < e2.weight;
}

edge *krushkals(edge *edges, int n, int e) //e is number of edges  n is for number of vertex
{
    edge *output = new edge[n - 1];
    sort(edges, edges + e, compare);
    int count = 0;
    int i = 0;

    UF *edgeSet = new UF(n);

    while (count < n - 1 && i < e)
    {
        int s = edges[i].source;
        int d = edges[i].destination;
        if (edgeSet->sameSet(s, d) == false) //for cycle detection
        {
            edgeSet->combine(s, d);
            output[count++] = edges[i];
        }
        i++;
    }
    return output;
}
int main()
{
}