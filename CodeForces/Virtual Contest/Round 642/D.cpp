
/** Which of the favors of your Lord will you deny ? **/

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
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>using indexed_set = tree<TIn, null_type, less<TIn>,rb_tree_tag, tree_order_statistics_node_update>;

/**

PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing

**/

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p);
template <class T>
ostream &operator <<(ostream &os, vector<T>&v);
template <class T>
ostream &operator <<(ostream &os, set<T>&v);

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e5+7;
const LL LINF = 1e17;

template <class T>
string to_str(T x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

class Node
{
public:
    int n;
    int rl;
    int rr;
    int v;

    Node(int n,int rl,int rr)
    {
        this->n = n;
        this->rl = rl;
        this->rr = rr;
        this->v = (rl+rr)/2;
    }
};

bool cmp(const Node &A,const Node &B)
{
    if(A.n==B.n)
        return A.rl < B.rl;
    return A.n > B.n;
}


int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        int N;
        cin>>N;

        queue<Node>q;
        vector<Node>v;

        Node one = Node(N,1,N);
        q.push(one);

        while(!q.empty())
        {
            Node node = q.front();
            q.pop();

//            cout<<node.n<<endl;

            v.push_back(node);

            int i1, i2;
            int i = node.n;
            i1 = (i-1)/2;
            i2 = i/2;

            int v = node.v;

            int r1l = node.rl;
            int r1r = r1l + i1 - 1;

            int r2l = v+1;
            int r2r = r2l + i2 - 1;

            if(i1>0)
                q.push(Node(i1,r1l,r1r));
            if(i2>0)
                q.push(Node(i2,r2l,r2r));
        }

        sort(ALL(v),cmp);

        vector<int>ans(N);

        int id = 1;
        for(auto x:v)
        {
//            cout<<x.v<<endl;
            ans[x.v-1] = id;
            id++;
        }

        for(int x:ans)
            cout<<x<<" ";
        cout<<endl;

    }

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
    for(int i=0; i<v.size(); i++)
    {
        os<<v[i]<<" " ;
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



