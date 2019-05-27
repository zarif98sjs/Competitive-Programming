
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

const int nmax = 150007;

vector<PII>v;

bool cmp(const PII &a,const PII &b)
{
    return a.S>b.S;
}
int main()
{
    optimizeIO();

    int n,id,m;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>id>>m;
        v.push_back(MP(id,m));
    }

    stable_sort(v.begin(),v.end(),cmp);

    for(int i=0;i<n;i++)
    {
        cout<<v[i].F<<" "<<v[i].S<<endl;
    }

    return 0;
}










