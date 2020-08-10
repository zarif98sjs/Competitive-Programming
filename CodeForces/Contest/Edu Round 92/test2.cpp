#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
int a[N];

long long C2(long long x)
{
    return x*(x-1)/2;
}

#ifndef ONLINE_JUDGE
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#else
#define DBG(x)
#endif

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while (t--)
    {
        long long m, d, w;
        cin>>m>>d>>w;

        w /= __gcd(w, d-1);
        long long z = min(m, d);

        DBG(w);
        DBG(z);

        long long choto = z/w, boro = z/w+1;
        long long chotocount = w-z%w, borocount = z%w;

        //        cout<<"---> "<<w<<" "<<z<<endl;
        //        cout<<choto<<" "<<chotocount<<endl;
        //        cout<<boro<<" "<<borocount<<endl;


        long long ans = chotocount*C2(choto) + borocount*C2(boro);
        cout<<ans<<endl;
    }
}
