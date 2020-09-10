
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
ostream &operator <<(ostream &os, set<T>&v);

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e5+7;

int main()
{
    optimizeIO();

    string s;
    cin>>s;

    s += ";";

    int n = s.size();

    string temp = "";
    vector<string>a;
    vector<string>b;

    bool is_ch = false;

    for(int i=0; i<n; i++)
    {
        if(s[i]!= ',' && s[i]!=';')
        {
            temp += s[i];

            if(s[i]>='a' && s[i]<='z') is_ch = true;
            if(s[i]>='A' && s[i]<='Z') is_ch = true;
            if(s[i]=='.') is_ch = true;
        }

        if(s[i] == ',' || s[i]==';')
        {
            int t = temp.size();

            if(t==0)
            {
                b.push_back(temp);
                continue;
            }

            if(temp[0]=='0')
            {
                if(t==1)a.push_back(temp);
                else b.push_back(temp);
            }
            else
            {
                if(is_ch) b.push_back(temp);
                else a.push_back(temp);
            }

            temp = "";
            is_ch = false;
        }
    }

    DBG(a);
    DBG(b);

    if(a.size()==0)
    {
        cout<<"-"<<endl;
    }
    else
    {
        cout<<"\"";
        for(int i=0; i<(int)a.size(); i++)
        {
            if(i==0) cout<<a[i];
            else cout<<","<<a[i];
        }
        cout<<"\""<<endl;
    }

    if(b.size()==0)
    {
        cout<<"-"<<endl;
    }
    else
    {
        cout<<"\"";
        for(int i=0; i<(int)b.size(); i++)
        {
            if(i==0) cout<<b[i];
            else cout<<","<<b[i];
        }
        cout<<"\""<<endl;
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
