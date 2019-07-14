
/*

Note :

The upper hand in this problem is that the index of the cities are already sorted.
So , can use a map to find if the given value exists or not.

Data Structure : STL Map

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

const int nmax = 70007;

map< int, vector<int> > M;

int main()
{
    optimizeIO();

    int n,x;
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        cin>>x;
        M[x].push_back(i);
    }

    int q,l,r,val;
    cin>>q;

    for(int i=1; i<=q; i++)
    {
        cin>>l>>r>>val;

        auto it = M.find(val);

        if(it==M.end())
            cout<<"0";
        else
        {
            auto et = lower_bound(it->S.begin(),it->S.end(),l);
            if(et==it->S.end() || (*et)>r) cout<<"0";
            else cout<<"1";
        }
    }

    return 0;
}













