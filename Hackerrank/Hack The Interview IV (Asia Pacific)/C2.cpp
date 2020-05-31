
/**
**/

/**Which of the favors of your Lord will you deny ?**/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

#define ALL(x) (x).begin(), (x).end()
#define DBG(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << endl

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>
using indexed_set = tree<
                    TIn, null_type, less<TIn>,
                    rb_tree_tag, tree_order_statistics_node_update>;

/*
PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing
*/

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 1e5+7;
const int nmax2 = 300+7;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

//bool cmp(const PII &A,const PII &B)
//{
//
//}

/** 1 based indexing **/

/**
dp[i][j] = minimum cost to reach cost[i][j]
dp[i][j] = cost[i][j] +  min(dp[i-1][j],dp[i][j-1]) // with corner cases of first row and column
**/
int cost[nmax2][nmax2];
int num[nmax2][nmax2];

vector<PII>adj[nmax];

vector<int>dx = {-1,0,1,0};
vector<int>dy = {0,1,0,-1};

int dist[nmax];

void dijkstra(int par)
{
    fill(dist,dist+nmax,INF);

    dist[par] = 0;

    priority_queue< PII,vector<PII>,greater<PII> >PQ;
    PQ.push(MP(dist[par],par));

    while(!PQ.empty())
    {
        int now = PQ.top().second;
        int nd = PQ.top().first;
        PQ.pop();

        //cout<<"!!"<<now<<" "<<dist[now]<<" "<<nd<<endl;

        if(dist[now]<nd)
            continue;

        for(int i=0; i<adj[now].size(); i++)
        {
            int next = adj[now][i].first;
            int ed = adj[now][i].second;

            //cout<<"**"<<now<<" "<<next<<" "<<dist[now]+ed<<endl;
            //LL temp = min((LL)ed,dist[now]);
            //min_cost[next] = min(min_cost[next],(LL)ed);

            if(dist[next]>max(nd,ed))
            {
                //cout<<"##"<<next<<" "<<endl;
                dist[next] = max(nd,ed);
                PQ.push(MP(dist[next],next));
            }
        }
    }
}

int main()
{
    optimizeIO();

    int r,c;
    cin>>r>>c;

    int cnt = 0;

    for(int i=1; i<=r; i++)
        for(int j=1; j<=c; j++)
            cin>>cost[i][j], num[i][j] = cnt++;


    for(int i=1; i<=r; i++)
        for(int j=1; j<=c; j++)
        {
            for(int cc=0; cc<4; cc++)
            {
                int nr = i+dx[cc];
                int nc = j+dy[cc];

                if(nr >=1 && nr <= r && nc>=1 && nc<= c)
                {
                    adj[num[i][j]].push_back({num[nr][nc],abs(cost[i][j]-cost[nr][nc])});
                }
            }
        }

    dijkstra(0);

    cout<<dist[r*c-1]<<endl;



    return 0;
}

