#include <iostream>

using namespace std;

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

int main()
{
    UF *s = new UF(10);
    s->combine(3, 4);
    s->printSet();
}