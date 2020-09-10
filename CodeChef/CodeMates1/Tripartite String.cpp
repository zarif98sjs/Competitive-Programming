#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll cnt[50];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n,r,p,ans,t,i,j;
    cin>>t;
    while(t--)
    {
        cin >> n;
        for(i=2;i<=41;i++)
            cnt[i]=0LL;
        ll ans = 1LL;
        for(i=0;i<n;i++)
        {
            cin >> p;
            j=2LL;
            while(p>1LL)
            {
                ll c = 0LL;
                while(p%j==0LL)
                {
                    p/=j;
                    c++;
                }
                while(cnt[j]<c)
                {
                    ans *= j;
                    cnt[j]++;
                }
                j++;
            }
        }
        cin >> r;
        ans+=r;
        cout << ans << endl;
    }
}
