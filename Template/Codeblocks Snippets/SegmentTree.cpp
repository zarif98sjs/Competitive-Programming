/**
Segment Tree (Point Update , Range Query)
=========================================
1 based indexing
**/

#define int long long

struct Node
{
    int sum;

    Node() /// change here
    {
        sum = 0;
    }

    void create_leaf(int val) /// change here
    {
        sum = val;
    }
};

Node merge_nodes(Node &a,Node &b) /// change here
{
    Node temp;
    temp.sum = a.sum + b.sum;

    return temp;
}

struct SegTree
{
    int n;
    vector<int>data;
    vector<Node>Tree;

    SegTree(int n)
    {
        this->n = n;
        int len = n+1;

        data = vector<int>(len);
        Tree = vector<Node>(len<<2);
    }

    void build()
    {
        build(1,1,n);
        return;
    }

    void build(int cur,int start,int end)
    {
        if(start==end)
        {
            Tree[cur].create_leaf(data[start]);
            return;
        }

        int mid = (start+end)>>1;
        int lc = cur<<1 , rc = lc1;

        build(lc,start,mid);
        build(rc,mid+1,end);

        Tree[cur] = merge_nodes(Tree[lc],Tree[rc]);
    }

    void update(int updex,int val)
    {
        update(1,1,n,updex,val);
    }

    void update(int cur,int start,int end,int updex,int val)
    {
        if(start==end)
        {
            Tree[cur].create_leaf(val);
            return;
        }

        int mid = (start+end)>>1;
        int lc = cur<<1 , rc = lc|1;

        /// binary search
        if(updex<=mid) update(lc,start,mid,updex,val);
        else update(rc,mid+1,end,updex,val);

        Tree[cur] = merge_nodes(Tree[lc],Tree[rc]); /// bottom up correction after update
    }

    Node query(int ql,int qr)
    {
        return query(1,1,n,ql,qr);
    }

    Node query(int cur,int start,int end,int ql,int qr)
    {
        if(end<ql || start>qr) return Node();

        if(start>=ql && end<=qr)
        {
            return Tree[cur];
        }

        int mid = (start+end)>>1;
        int lc = cur<<1 , rc = lc|1;

        /// query on both child
        Node ansL = query(lc,start,mid,ql,qr);
        Node ansR = query(rc,mid+1,end,ql,qr);

        return merge_nodes(ansL,ansR);
    }
};
