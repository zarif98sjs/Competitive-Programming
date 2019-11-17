
/**

Problem : SPOJ ADAAPPLE
Technique : HLD

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

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 3e5+7;
const LL LINF = 1e17;

#define root 0
#define LN 25

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

char str[nmax];

vector<int>adj[nmax] , cost[nmax] , indexx[nmax];

int ptr , chainNo , chainInd[nmax] ,chainHead[nmax] , posInBase[nmax];
int depth[nmax] , sptable[nmax][LN] , otherEnd[nmax] , subSize[nmax];

/*** Segment Tree ***/

int baseArray[nmax];
int st[nmax*6] , qt[nmax*6];
/**
segment tree build function:
uses the baseArray for construction
**/
void build_tree(int node,int s,int e)
{
    if(s==e-1)
    {
        st[node] = baseArray[s];
        return;
    }

    int lc = (node<<1) , rc = lc | 1 , m = (s+e)>>1;

    build_tree(lc,s,m);
    build_tree(rc,m,e);

    st[node] = st[lc] + st[rc];
}

/**
segment tree update function:
point update
**/
void update_tree(int node,int s,int e,int x)
{
    if(s>x || e<=x)
        return;

    if(s==x && s==e-1)
    {
        st[node] = 1 - st[node]; /// changing 0 to 1 and vice versa
        return;
    }

    int lc = (node<<1) , rc = lc | 1 , m = (s+e)>>1;

    update_tree(lc,s,m,x);
    update_tree(rc,m,e,x);

    st[node] = st[lc] + st[rc];

}

/**
segment tree query function:
Given S and E , it will return the maximum value of [S,E)
**/

void query_tree(int node,int s,int e, int S, int E)
{
    if(s>=E || e<=S)
    {
        qt[node] = 0;
        return;
    }

    if(s>=S && e<=E)
    {
        qt[node] = st[node];
        return;
    }

    int lc = (node<<1) , rc = lc | 1 , m = (s+e)>>1;

    query_tree(lc,s,m,S,E);
    query_tree(rc,m,e,S,E);

    qt[node] = qt[lc] + qt[rc];
}

/**

query_up:
It takes two nodes u and v , condition is that v is an ancestor of u
We query the chain in which the chain is present till chain head, then move to the next chain up
We do that till u and v are in the same chain , we query for the part of the chain and break

**/

int query_up(int u ,int v)
{
    if(u==v)
    {
        query_tree(1,0,ptr,posInBase[u],posInBase[u]+1);
        return qt[1];
    }

    int uchain , vchain = chainInd[v] , ans = 0;

    while(true)
    {
        uchain = chainInd[u];

        if(uchain==vchain)
        {
            /// Both u and v are in the same chain , so we need to query from u to v , update answer and break
            /// We break because we came from u up till v and we are done

            if(u==v)
                query_tree(1,0,ptr,posInBase[u],posInBase[u]+1);
            query_tree(1,0,ptr,posInBase[v],posInBase[u]+1);

            ans += qt[1]; /// update answer
            break;
        }

        /// We do query from chainHead of u till u . That is the whole chain from start till head
        query_tree(1,0,ptr,posInBase[chainHead[uchain]],posInBase[u]+1);
        ans += qt[1];

        u = chainHead[uchain]; /// move u to u's chainHead
        u = sptable[u][0]; /// then move to it's parent , that means we changed chains
    }

    return ans;
}

/*** LCA **/
void lca_init(int n)
{
    for(int j=1;(1<<j)<n;j++)
        for(int i=0;i<n;i++)
            if(sptable[i][j-1]!=-1)
                sptable[i][j] = sptable[sptable[i][j-1]][j-1];
}

int lca_query(int u,int v)
{
    if(depth[u]<depth[v])
        swap(u,v);

    int dis = depth[u] - depth[v];

    int log;
    for(log = 1;(1<<log)<=depth[u];log++);
    log--;

    ///making the levels same
    for(int i=log;i>=0;i--)
        if(dis &(1<<i))
            u = sptable[u][i];

    if(u==v)
        return u;

    for(int i=log;i>=0;i--)
        if(sptable[u][i]!=-1 && sptable[v][i]!=-1 && sptable[u][i]!=sptable[v][i])
        {
            u = sptable[u][i];
            v = sptable[v][i];
        }

    return sptable[u][0];
}

/**

We break the query to two queries , u to LCA(u,v) and LCA(u,v) to v

**/
void query(int u,int v)
{
    int lca = lca_query(u,v);

    int ans = query_up(u,lca);
    ans += query_up(v,lca);

    ans -= query_up(lca,lca);

    int dis = depth[u] + depth[v] - 2*depth[lca] + 1;
    if(ans==dis || ans==0)
        printf("YES\n");
    else
        printf("NO\n");

}

/**

change :
find it's position in the segment tree and update it

**/

void change(int idx)
{
    update_tree(1,0,ptr,posInBase[idx]);
}

/**

Heavy Light Decomposition :

Initially all entries of chainHead[] are set to -1
So , when a new chain is started , chain head is correctly assigned.
As we add a new node to chain , we will note its position in the baseArray.

In the first for loop we find the child node which has maximum subtree size.
The following if condition is failed for leaf nodes.
When the if condition passes, we expand the chain to special child.

In the second for loop we recursively call the function on all normal nodes.
chainNo++ ensures that we are creating a new chain for each normal child.

**/

void HLD(int curNode,int prev)
{
    if(chainHead[chainNo]==-1)
        chainHead[chainNo] = curNode; ///Assign chain head

    chainInd[curNode] = chainNo;
    posInBase[curNode] = ptr; /// Position of this node in baseArray which we will use in segment tree
    baseArray[ptr++] = str[curNode] - '0';

    int sc = -1; ///special child

    /// Loop to find special child
    for(int next:adj[curNode])
    {
        if(next!=prev)
            if(sc == -1 || subSize[sc]<subSize[next])
                sc = next;
    }

    if(sc!=-1)
        HLD(sc,curNode); /// Expand the chain

    for(int next:adj[curNode])
    {
        if(next!=prev && next!=sc)
        {
            /// New chains at each normal child
            chainNo++;
            HLD(next,curNode);
        }
    }
}

void dfs(int cur,int prev,int _depth = 0)
{
    sptable[cur][0] = prev;
    depth[cur] = _depth;
    subSize[cur] = 1;

    for(int i=0;i<adj[cur].size();i++)
    {
        int next = adj[cur][i];
        int idx = indexx[cur][i];

        if(next!=prev)
        {
            otherEnd[idx] = next;
            dfs(next,cur,_depth+1);
            subSize[cur] += subSize[next];
        }
    }
}

int main()
{
    //freopen("LightOj1029.txt","w",stdout);

    //optimizeIO();

    int n,q;
    scanf("%d %d",&n,&q);
    scanf("%s",str);

    for(int i=0;i<n;i++)
    {
        chainHead[i] = -1;
        for(int j=0;j<LN;j++)
            sptable[i][j] = -1;
    }

    for(int i=1;i<n;i++)
    {
        int u , v;
        scanf("%d %d",&u,&v);

        adj[u].push_back(v);
        indexx[u].push_back(i-1);
        adj[v].push_back(u);
        indexx[v].push_back(i-1);
    }


    dfs(root,-1);

    ptr = 0 , chainNo = 0;
    HLD(root,-1);

    build_tree(1,0,ptr);

    lca_init(n);

    while(q--)
    {
        int type;
        scanf("%d",&type);

        int l,r;

        if(type==1)
        {
            scanf("%d %d",&l,&r);
            query(l,r);
        }
        else
        {
            scanf("%d",&l);
            change(l);
        }
    }
    return 0;
}
