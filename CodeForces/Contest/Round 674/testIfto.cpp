#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define N 300005
#define M 1000000007
#define pii pair<ll,ll>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

ll sil(ll a,ll b)
{
    return max((a/b)+(a%b!=0),0LL);
}

void solve()
{
    map<ll,ll>mp;
    ll cur=0;
    int n;
    cin>>n;
    ll ans=0;
    mp[0]=0;
    int last=-100;
    for(int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        cur+=x;
        if(mp[cur]||cur==0)
        {
            cout<<" -> "<<cur<<endl;
            cout<<" last : "<<last<<endl;
            if(mp[cur]>=last-1)
            {
                cout<<" -> "<<cur<<endl;
                cout<<" last : "<<last<<endl;
                ans++;
                last=i;
                //cout<<i<<endl;
            }
        }
        mp[cur]=i;
    }
    cout<<ans;
}

main()
{
    int t;
    t=1;
    while(t--)
    {
        solve();
    }
}

/**
8
-3 -2 -1 1 0 -1 -2 -3
**/

