
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define ALL(x)      (x).begin(), (x).end()
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

#ifndef ONLINE_JUDGE
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#else
#define DBG(x)
#define endl "\n"
#endif

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p);
template <class T>
ostream &operator <<(ostream &os, vector<T>&v);
template <class T>
ostream &operator <<(ostream &os, multiset<T>&v);
template <class T>
ostream &operator <<(ostream &os, set<T>&v);



inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 1e5+7;

int col[nmax];
vector<int>adj[nmax];

int start[nmax];
int finish[nmax];
int tree[nmax];

int timer = 0;

void dfs(int u,int p)
{
    start[u] = ++timer;
    tree[timer] = u;

    for(int v:adj[u])
    {
        if(v!=p)
            dfs(v,u);
    }

    finish[u] = timer;
}

/** Mo's Algorithm **/
/*** 1 based indexing ***/

int block_size;

struct Query
{
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

int cnt[nmax];
int max_cnt[nmax]; /** this part is needed because when a value is removed , we need to check
                    if this value was the only one with maximum freq **/

LL max_cnt_val[nmax];
int mx = 0;

inline void init(int n)
{
    mx = 0;
    fill(cnt,cnt+nmax,0);
    fill(max_cnt,max_cnt+nmax,0);
    block_size = sqrt(n);
}

void remov(int idx);  // TODO: remove value at idx from data structure
void add(int idx);     // TODO: add value at idx from data structure
LL get_answer();  // TODO: extract the current answer of the data structure

inline void add(int idx)
{

    DBG(idx);
    int val = col[tree[idx]];
    cnt[val]++;
    max_cnt[cnt[val]]++;
    max_cnt_val[cnt[val]] += val;
    mx = max(mx,cnt[val]);

    DBG(mx);
    DBG(max_cnt_val[mx]);
}

inline void remov(int idx)
{
    DBG(idx);
    int val = col[tree[idx]];
    max_cnt[cnt[val]]--;
    max_cnt_val[cnt[val]] -= val;

    if(max_cnt[cnt[val]]==0) /** if this value was the NOT only one with maximum freq , then reduce mx **/
        mx--;

    cnt[val]--;

    DBG(mx);
    DBG(max_cnt_val[mx]);
}

inline LL get_answer()
{
    return max_cnt_val[mx];
}

vector<LL> mo_s_algorithm(vector<Query> queries)
{
    vector<LL> answers(queries.size()+1);
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries)
    {
        while (cur_l > q.l)
        {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r)
        {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l)
        {
            remov(cur_l);
            cur_l++;
        }
        while (cur_r > q.r)
        {
            remov(cur_r);
            cur_r--;
        }

        DBG(q.idx);
        DBG(q.l);
        DBG(q.r);

        answers[q.idx] = get_answer();
    }
    return answers;
}

//void DEBUG()
//{
//    for(int i=1;i<=n;i++)
//}

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    for(int i=1;i<=n;i++) cin>>col[i];

    int m = n-1;
    while(m--)
    {
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,-1);

    init(n); /** IMP **/
    vector<Query>qv;

    for(int i=1; i<=n; i++)
    {
        qv.push_back({start[i],finish[i],i});
    }

    auto ans = mo_s_algorithm(qv);

    for(int i=1; i<=n; i++)
        cout<<ans[i]<<" ";

    return 0;
}

/**

**/

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p)
{
    os<<"{"<<p.first<<", "<<p.second<<"} ";
    return os;
}
template <class T>
ostream &operator <<(ostream &os, vector<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" " ;
    }
    os<<" ]";
    return os;
}

template <class T>
ostream &operator <<(ostream &os, set<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" ";
    }
    os<<" ]";
    return os;
}


template <class T>
ostream &operator <<(ostream &os, multiset<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" ";
    }
    os<<" ]";
    return os;
}
