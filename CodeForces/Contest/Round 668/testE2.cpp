#include "bits/stdc++.h"

using namespace std;
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
ostream &operator <<(ostream &os, set<T>&v);
struct node {
    node *l, *r;
    pair<int,int> val; int s, m, e, lazyadd;
    node(int _s, int _e): s(_s), e(_e), m((_s+_e)/2), val({0,0}), lazyadd(0), l(NULL), r(NULL) {
        if (s != e) l = new node(s, m), r = new node(m+1, e);
    }
    pair<int,int> value() { //returns the value of the current node after lazy propagating
        if (s == e) return {val.first + lazyadd, -s};
        val.first += lazyadd;
        l->lazyadd += lazyadd, r->lazyadd += lazyadd;
        lazyadd = 0;
        return val;
    }
    void add(int x, int y, int v) {
        if (s == x && e == y) lazyadd += v;
        else {
            if (x > m) r->add(x, y, v);
            else if (y <= m) l->add(x, y, v);
            else l->add(x, m, v), r->add(m+1, y, v);
            val = min(l->value(), r->value()); //Change here to max
        }
    }
    pair<int,int> query(int x, int y) {
        value();
        if (s == x && e == y) return value();
        if (x > m) return r->query(x, y);
        if (y <= m) return l->query(x, y);
        return min(l->query(x, m),r->query(m+1, y)); //Change here to max
    }
} *root;

const int N=3e5+5;
int n,q;
int a[N],b[N];
int ft[N];

int sum(int r){
	int an=0;
	for(int i=r; i>0; i-=(i&(-i))){
		an += ft[i];
	}
	return an;
}

void upd(int p, int v){
	for(int i=p; i<N; i+=(i&(-i))){
		ft[i] += v;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n>>q;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++){
		if(i<a[i]) b[i] = 1e9;
		else b[i] = i-a[i];
	}
	root = new node(1,n);
	for(int i=1; i<=n; i++) root->add(i,i,b[i]);

	vector<int> r;

	while(true){
		pair<int,int> pp = root->query(1,n);
		if(pp.first <= 0){
			pp.second = -pp.second;
			root->add(pp.second,pp.second,1e8);

			if(pp.second!=n) root->add(pp.second+1,n,-1);

			r.push_back(pp.second);
		}
		else break;
	}

	DBG(r);

	int p_min[r.size()]; p_min[0] = r[0];
	for(int i=1; i<r.size(); i++){
		p_min[i] = min(p_min[i-1],r[i]);
	}
	map<int,int> in_r;
	for(int i=0; i<r.size(); i++) in_r[r[i]] = i+1; //RMB +1

	memset(ft,0,sizeof(ft));

	//increasing y order
	pair<pair<int,int>,int> qry[q]; //yxi
	for(int i=0; i<q; i++){
		int x,y; cin>>x>>y;
		qry[i] = {{y,x},i};
	}
	sort(qry,qry+q);
	int ans[q];
	int ls=0;
	for(int i=0; i<q; i++){
		int y=qry[i].first.first, x=qry[i].first.second, po=qry[i].second;
		for(int j=ls; j<y; j++){
			if(in_r.count(n-j)) upd(in_r[n-j],1);
		}
		ls=y;

		int lo=0,hi=r.size()-1;
		if(p_min[r.size()-1] > x){ lo=r.size(); goto ahc;}
		while(lo<hi){
			int m=(lo+hi)/2;
			if(p_min[m] <= x) hi=m;
			else lo=m+1;
		}
		ahc: int cr=lo;
		cr -= sum(lo);
		ans[po]=cr;
	}
	for(int i=0; i<q; i++) cout<<ans[i]<<'\n';
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
