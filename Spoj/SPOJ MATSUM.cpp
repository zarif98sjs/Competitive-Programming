
/*

Note : Basic 2D BIT Implementation
Data Structure : 2D BIT

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

const int nmax = 1024+5;

int c[nmax][nmax];
int ara[nmax][nmax];
int n;

inline int lowbit(int x)
{
    return x&(-x);
}

inline void update(int x,int y,int val)
{
    for(int i = x; i <= n; i += lowbit(i))
        for(int j = y; j <= n; j += lowbit(j))
            c[i][j] += val;
}

inline int sum(int x,int y)
{
    int s = 0;
    for(int i = x; i > 0; i -= lowbit(i))
        for(int j = y; j > 0; j -= lowbit(j))
            s += c[i][j];

    return s;
}

int main()
{
    optimizeIO();
    int tc;
    cin >> tc;
    for (int tcase = 1; tcase <= tc; tcase++)
    {
        cin >> n;

        memset(c,0,sizeof(c));
        memset(ara,0,sizeof(ara));

        string type;
        while (cin >> type)
        {
            if (type[0] == 'E')
                break;
            if (type == "SET")
            {
                int x, y;
                int val;
                cin >> x >> y >> val;
                x++, y++;
                int add = val - ara[x][y];
                //cout<<"add "<<add<<endl;
                ara[x][y] = val;
                update(x, y, add);
            }
            else
            {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                x1++, y1++;
                x2++, y2++;
                int v1 = sum(x2, y2);
                int v2 = sum(x2, y1-1);
                int v3 = sum(x1-1, y2);
                int v4 = sum(x1-1, y1-1);
                int ans = v1 - v2 - v3 + v4;
                //cout<<v1<<" "<<v2<<" "<<v3<<" "<<v4<<endl;
                cout << ans << endl;
            }
        }
    }



    return 0;
}
