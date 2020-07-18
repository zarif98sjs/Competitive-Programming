
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

const int nmax = 30007;
const int nmax2 = nmax<<2;

struct node
{
    LL unmatched_op,unmatched_cl;

    void create_leaf(char ch)
    {
        if(ch=='(')
            unmatched_op = 1, unmatched_cl = 0;
        else
            unmatched_op = 0, unmatched_cl = 1;
    }

    void merge_nodes(node &A,node &B)
    {
        int match = min(A.unmatched_op,B.unmatched_cl);
        unmatched_op = A.unmatched_op + B.unmatched_op - match;
        unmatched_cl = A.unmatched_cl + B.unmatched_cl - match;
    }
};

string ara;

node Tree[nmax2];

void build(int cur,int start,int end)
{
    if(start==end)
    {
        Tree[cur].create_leaf(ara[start]);
        return;
    }

    int lc = 2*cur, rc = 2*cur+1;
    int mid = (start+end)/2;

    build(lc,start,mid);
    build(rc,mid+1,end);

    Tree[cur].merge_nodes(Tree[lc],Tree[rc]);

}

void query(node &res,int cur,int start,int end,int l,int r)
{
    if(start>=l && end<=r)
    {
        res = Tree[cur];
        return;
    }

    int lc = 2*cur, rc = 2*cur+1;
    int mid = (start+end)/2;

    if(r<=mid)
        query(res,lc,start,mid,l,r);
    else if(l>mid)
        query(res,rc,mid+1,end,l,r);
    else
    {
        node left,right;
        query(left,lc,start,mid,l,r);
        query(right,rc,mid+1,end,l,r);
        res.merge_nodes(left,right);
    }
}

void update(int cur, int start, int end, int updex, char ch)
{
    if (start == end)
    {
        Tree[cur].create_leaf(ch);
        return;
    }

    int lc = 2 * cur, rc = 2*cur+1, mid = (start + end) / 2;

    if (updex <= mid)
        update(lc, start, mid, updex, ch);
    else
        update(rc, mid+1, end, updex, ch);

    Tree[cur].merge_nodes(Tree[lc],Tree[rc]);
}


int main()
{
    //freopen("GSS1.txt","w",stdout);

    int n,m,t,x,y,tc;

    for(int i=1; i<=10; i++)
    {
        cin>>n;
        cin>>ara;
        //n = ara.size();
        ara = '0' + ara;

        build(1,1,n);

        cin>>t;
        node Ans;

        cout<<"Test "<<i<<":"<<endl;

        while(t--)
        {
            cin>>x;
            if(x==0)
            {
                query(Ans,1,1,n,1,n);
                if (Ans.unmatched_op == 0 && Ans.unmatched_cl==0)
                    cout<<"YES"<<endl;
                else
                    cout<<"NO"<<endl;

            }
            else
            {
                ara[x] = (ara[x] == '(') ? ')' : '(';
                update(1,1,n,x,ara[x]);
            }


        }

    }


    return 0;
}
