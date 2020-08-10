#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
vector<vector<int>> adj(maxn);
vector<int> parent(maxn, 0);
vector<int> siz(maxn, 0);
vector<int> component;
vector<bool> used(maxn, false);
vector<int> even;
vector<int> odd;
int n, m, k;


int find_repre(int n1)
{
    if(n1 == parent[n1])
        return n1;
    return parent[n1] = find_repre(parent[n1]);
}

void dfs(int x, int p)
{
    used[x] = true;
    component.emplace_back(x);
    for(int& i : adj[x])
    {
        if(i == p)
            continue;
        if(used[i] == true)
        {
            cout << (int) component.size() << '\n';
            for(int& j : component)
                cout << j << ' ';
            exit(0);
        }
        dfs(i, x);
    }
    component.pop_back();
    used[x] = false;
}

void dfs1(int x, int level, int p)
{
    used[x] = true;
    if(level & 1)
        odd.emplace_back(x);
    else
        even.emplace_back(x);
    for(int& i : adj[x])
    {
        if(p == i)
            continue;
        dfs1(i, level + 1, x);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(int i = 1; i < maxn; i++)
        parent[i] = i, siz[i] = 1;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if(x > k || y > k)
            continue;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
        int rx = find_repre(x);
        int ry = find_repre(y);
        if(rx == ry)
        {
            cout << "2\n";
            dfs(x, -1);
            return 0;
        }
        else
        {
            if(siz[rx] < siz[ry])
                swap(rx, ry);
            parent[ry] = rx;
            siz[rx] += siz[ry];
        }
    }
    cout << "1\n";
    for(int i = 1; i <= k; i++)
    {
        if(used[i] == false)
        {
            dfs1(i, 1, -1);
        }
    }
    assert((int) odd.size() >= (k + 1) / 2 || (int) even.size() >= (k + 1) / 2);
    if((int) odd.size() >= (k + 1) / 2)
    {
        while((int) odd.size() != (k + 1) / 2)
            odd.pop_back();
        for(int& i : odd)
            cout << i << ' ';
        return 0;
    }
    if((int) even.size() >= (k + 1) / 2)
    {
        while((int) even.size() != (k + 1) / 2)
            even.pop_back();
        for(int& i : even)
            cout << i << ' ';
        return 0;
    }
    return 0;
}
