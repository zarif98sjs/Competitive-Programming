#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 998244353LL

ll fact[100009],invfact[100009],cnt[30],cnt2[30];
char s[100009],name[25][100009];

ll bigmod(ll x,ll n)
{
    ll ans = 1LL;
    while(n)
    {
        if(n%2LL) ans=((ans%mod)*(x%mod))%mod;
        n/=2LL;
        x = ((x%mod)*(x%mod))%mod;
    }
    return ans;
}
ll invmod(ll x)
{
    return bigmod(x,mod-2LL);
}
void factorial()
{
    fact[0] = 1LL;
    invfact[0] = invmod(1LL);
    for(ll i=1LL;i<=100000LL;i++)
    {
        fact[i] = ((fact[i-1]%mod)*(i%mod))%mod;
        invfact[i]=invmod(fact[i]);
    }
    return ;
}
ll nCr(ll n,ll r)
{
    if(r>n) return 0LL;
    ll ans = ((fact[n]%mod)*(invfact[r]%mod))%mod;
    ans = ((ans%mod)*(invfact[n-r]%mod))%mod;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    factorial();

    int n,m,i,j,l;
    cin >> m;
    while(m--)
    {
        cin >> s;
        int len = strlen(s);
        ll ansmax = 0LL;
        int id = -1;
        for(i=0;i<26;i++)
            cnt[i]=0LL;
        for(i=0;i<len;i++)
            cnt[s[i]-'a']++;
        cin >> n;
        for(i=0;i<n;i++)
        {
            cin >> name[i];
            l = strlen(name[i]);
            for(j=0;j<26;j++) cnt2[j]=0LL;
            for(j=0;j<l;j++) cnt2[name[i][j]-'a']++;

            ll ans = 1LL;
            for(j=0;j<26;j++)
            {
                if(cnt2[j])
                {
                    ll ncr = nCr(cnt[j],cnt2[j]);
                    ans = ((ans%mod)*(ncr%mod))%mod;
                }
            }
            cout << ans << endl;
            if(ansmax<ans)
            {
                ansmax=ans;
                id = i;
            }
        }
        if(id==-1) cout << "No Research This Month" << endl;
        else cout << name[id] << endl;
    }



}
