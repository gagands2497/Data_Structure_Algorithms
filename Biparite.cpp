#include <bits/stdc++.h>

using namespace std;

bool isBiparite(vector<int> *edges, int n)
{
    unordered_set<int> sets[2]; //set 1 and 2
    vector<int> pending;
    sets[0].insert(0);
    pending.push_back(0);

    while (pending.size() > 0)
    {
        int current = pending.back();
        pending.pop_back();
        int currSet = sets[0].count(current) > 0 ? 0 : 1;
        for (int j = 0; j < edges[current].size(); j++)
        {
            int neighbour = edges[current][j];
            if (sets[0].count(neighbour) == 0 && sets[1].count(neighbour) == 0)
            {
                sets[1 - currSet].insert(neighbour);
                pending.push_back(neighbour);
            }
            else if (sets[currSet].count(neighbour) > 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        vector<int> *edges = new vector<int>[n];
        int e;
        cin >> e;
        for (int i = 0; i < n; i++)
        {
            int s, d;
            cin >> s >> d;
            edges[s].push_back(d);
            edges[d].push_back(s);
        }

        bool flag = isBiparite(edges, n);
        string ans = flag ? "BI-COLOURABLE" : "NOT BICOLOURABLE";
        cout << ans << endl;
    }
}