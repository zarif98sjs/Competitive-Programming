
/*

Note :

This problem needs Disjoint Set Data Structure

Now it is easy to see that the problem needs to be solved in reverse order of q.
So first of all merge all the edges that are never going to be removed,
then start adding the edges that were removed last and count the components.

Data Structure : Disjoint Set

*/


/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 100007;

vector<PII>E;
vector<int>Q;
bool nibona[nmax];


//Disjoint Set Union
int p[nmax];
int n_comp;
void initSet(int n)
{
    n_comp = n;
    for (int i = 0; i < n ; i++)
        p[i] = i;
}
int findSet(int i)
{
    return p[i] == i?i:p[i] = findSet(p[i]);
}
bool isSameSet(int i, int j)
{
    return findSet(i) == findSet(j);
}
void unionSet(int i, int j)
{
    if(!isSameSet(i, j))
        n_comp--;
    p[findSet(i)] = findSet(j);
}

int main()
{
    optimizeIO();

    int n,m,x,y,q;

    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        E.push_back(MP(x,y));

    }

    cin>>q;

    //memset(add,true,sizeof(add));

    for(int i=0; i<q; i++)
    {
        cin>>x;
        Q.push_back(x);
        Q[i]--;
        nibona[Q[i]] = true;
    }

    initSet(n);

    for(int i=0; i<m; i++)
    {
        if(!nibona[i])
        {
            //cout<<"noooo"<<endl;
            unionSet(E[i].F, E[i].S);
        }

    }

    vector<int> ans;

    for(int i=q-1; i>=0; i--) //from reverse , merging
    {
        ans.push_back(n_comp);
        unionSet(E[Q[i]].F, E[Q[i]].S);
    }

    reverse(ans.begin(),ans.end());

    for(auto w:ans)
        cout<<w<<" ";


    return 0;
}











