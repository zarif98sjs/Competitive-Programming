
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

bool isPos(string st,string ch,string s,int id)
{
    int n = st.size();

    bool ok = true;

    for(int i=0; i<n; i++)
    {
        if(st[i]!=ch[i] && st[i]!='?')
            ok = false;
    }

    if(ok==false)
        return false;

    n = s.size();
    int c = ch.size();

    for(int j=0; j<c; j++)
    {
        s[id+j] = ch[j];
    }

    int cnt=0;

    for(int i=0; i<n-c+1; i++)
    {
        string t = s.substr(i,c);

        if(t==chk)
        {
            cnt++;
        }
    }

    if(cnt==1)
        return true;

    return false;
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        string s;
        cin>>n>>s;

        string chk = "abacaba";
        int c = chk.size();

        int cnt=0;

        for(int i=0; i<n-c+1; i++)
        {
            string t = s.substr(i,c);

            if(t==chk)
            {
                cnt++;
            }
        }

        if(cnt==1)
        {
            cout<<"YES"<<endl;

            for(int i=0; i<n; i++)
            {
                if(s[i]=='?')
                    s[i]='d';
            }

            cout<<s<<endl;
        }
        else if(cnt>1)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            bool ok = false;

            for(int i=0; i<n-c+1; i++)
            {
                string t = s.substr(i,c);
                DBG(t);

                if(isPos(t,chk,s,i))
                {
                    for(int j=0; j<c; j++)
                    {
                        s[i+j] = chk[j];
                    }

                    ok = true;
                    break;
//
//                    DBG(s);
                }
            }

            int cnt=0;

            for(int i=0; i<n-c+1; i++)
            {
                string t = s.substr(i,c);

                if(t==chk)
                {
                    cnt++;
                }
            }

            if(cnt==1)
            {
                cout<<"YES"<<endl;

                for(int i=0; i<n; i++)
                {
                    if(s[i]=='?')
                        s[i]='d';
                }

                cout<<s<<endl;
            }
            else if(cnt>1 || ok==false)
            {
                cout<<"NO"<<endl;
            }

//            if(!ok)
//            {
//                cout<<"NO"<<endl;
//            }
//            else
//            {
//                cout<<"YES"<<endl;
//
//                for(int i=0; i<n; i++)
//                {
//                    if(s[i]=='?')
//                        s[i]='d';
//                }
//
//                cout<<s<<endl;
//            }
        }


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



