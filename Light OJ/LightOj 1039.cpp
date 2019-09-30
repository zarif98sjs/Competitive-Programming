
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

const int nmax = 1e6+7;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

map<string,int>MAP;
map<string,int>vis;
map<string,int>level;

int bfs(string start,string last)
{
    if(MAP.find(start)!=MAP.end())
        return -1;
    if(MAP.find(last)!=MAP.end())
        return -1;

    if(start==last)
        return 0;

    queue<string> q;
    q.push(start);
    vis[start] = 1;
    level[start] = 0;

    while(!q.empty())
    {
        string now = q.front();
        q.pop();

        for(int i=0;i<now.size();i++)
        {
            string s1 = now;
            string s2 = now;

            s1[i] = (s1[i]-'a'-1+26)%26 + 'a';
            s2[i] = (s2[i]-'a'+1)%26 + 'a';

            //cout<<s1<<"  --  "<<s2<<endl;

            if(MAP.find(s1)==MAP.end())
            {
                if(vis.find(s1)==vis.end())
                {
                    q.push(s1);
                    //cout<<"hoiseeee1"<<endl;
                    vis[s1] = 1;
                    level[s1] = level[now] + 1;
                }
                else if (level[now]+1<level[s1])
                {
                    q.push(s1);
                    level[s1] = min(level[s1],level[now]+1);
                }
            }
            if(MAP.find(s2)==MAP.end())
            {

                if(vis.find(s2)==vis.end())
                {
                    q.push(s2);
                    //cout<<"hoiseeee2"<<endl;
                    vis[s2] = 1;
                    level[s2] = level[now] + 1;
                }
                else if (level[now]+1<level[s2])
                {
                    q.push(s2);
                    level[s2] = min(level[s2],level[now]+1);
                }
            }
        }
    }

    if(vis.find(last)==vis.end())
        return -1;
    else
        return level[last];
}

void init()
{
    MAP.clear();
    vis.clear();
    level.clear();
}


int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    for(int q=1;q<=tc;q++)
    {
        init();

        string st,en;
        cin>>st>>en;

        int n;
        cin>>n;

        for(int i=1;i<=n;i++)
        {
            string a,b,c;
            cin>>a>>b>>c;

            int cnt = 1;

            for(int x=0;x<a.size();x++)
            {
                for(int y=0;y<b.size();y++)
                {
                    for(int z=0;z<c.size();z++)
                    {
                        string temp = "";
                        temp.push_back(a[x]);
                        temp.push_back(b[y]);
                        temp.push_back(c[z]);
                        //cout<<temp<<endl;
                        MAP.insert({temp,cnt});
                        cnt++;
                    }
                }
            }

        }

//        for(auto x:MAP)
//        {
//            cout<<x.F<<endl;
//        }

        int ans = bfs(st,en);
        cout<<"Case "<<q<<": "<<ans<<endl;

    }


}


