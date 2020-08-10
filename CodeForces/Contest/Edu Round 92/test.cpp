#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
int a[N];
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
        long long n, k;
        long long l1, l2, r1, r2;
        cin>>n>>k>>l1>>r1>>l2>>r2;

        long long ans = 2e18;

        if (l1 > l2)
            swap(l1, l2), swap(r1, r2);

        long long A, B, common;
        if (r1 < l2)
            A = l2-r1, B = r2-l1, common = 0;
        else
        {
            common = min(r1, r2)-l2;
            A = 0;
            B = max(r2, r1)-l1-common;
        }

        DBG(A);
        DBG(B);
        DBG(common);

        k-= common*n;
        if (k <= 0)
        {
            cout<<0<<endl;
            continue;
        }

        for (int i=1; i<=n; i++)
        {
            long long moves = i*A;
            if (B*i >= k) moves += k;
            else
            {
                moves += B*i;
                long long rem = k-B*i;
                moves += rem*2;
            }

            DBG(moves);
            ans = min(ans, moves);
        }
        cout<<ans<<endl;
    }
}
