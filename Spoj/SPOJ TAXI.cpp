
    /*Which of the favors of your Lord will you deny ?*/

    #include<bits/stdc++.h>
    using namespace std;

    #define LL long long
    #define PII pair<int,int>
    #define PL pair<LL,LL>
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

    const int MAX = 650;
    const LL LINF = 1e17;

    string to_str(LL x)
    {
        stringstream ss;
        ss<<x;
        return ss.str();
    }

    vector<PL>p;
    vector<PL>t;

    vector< int > graph[MAX];
    int n, m, match[MAX], dist[MAX];
    int NIL=0;

    bool bfs()
    {
        int i, u, v, len;
        queue< int > Q;
        for(i=1; i<=n; i++)
        {
            if(match[i]==NIL)
            {
                dist[i] = 0;
                Q.push(i);
            }
            else dist[i] = INF;
        }
        dist[NIL] = INF;
        while(!Q.empty())
        {
            u = Q.front(); Q.pop();
            if(u!=NIL)
            {
                len = graph[u].size();
                for(i=0; i<len; i++)
                {
                    v = graph[u][i];
                    if(dist[match[v]]==INF)
                    {
                        dist[match[v]] = dist[u] + 1;
                        Q.push(match[v]);
                    }
                }
            }
        }
        return (dist[NIL]!=INF);
    }

    bool dfs(int u)
    {
        int i, v, len;
        if(u!=NIL)
        {
            len = graph[u].size();
            for(i=0; i<len; i++)
            {
                v = graph[u][i];
                if(dist[match[v]]==dist[u]+1)
                {
                    if(dfs(match[v]))
                    {
                        match[v] = u;
                        match[u] = v;
                        return true;
                    }
                }
            }
            dist[u] = INF;
            return false;
        }
        return true;
    }

    int hopcroft_karp()
    {
        int matching = 0, i;
        // match[] is assumed NIL for all vertex in graph
        // All nodes on left and right should be distinct
        while(bfs())
            for(i=1; i<=n; i++)
                if(match[i]==NIL && dfs(i))
                    matching++;
        return matching;
    }

    void clear()
    {
        for(int j=0;j<MAX;j++)
            graph[j].clear();
        memset(match,NIL,sizeof match);
    }


    int main()
    {
        optimizeIO();

        int tc;
        cin>>tc;
        while(tc--)
        {
            int people,taxi;
            double speed,limit;
            cin>>people>>taxi>>speed>>limit;

            clear();

            n = taxi;
            m = people;

            p.clear();
            t.clear();

            for(int i=1;i<=people;i++)
            {
                LL x,y;
                cin>>x>>y;
                p.push_back(MP(x,y));
            }
            for(int i=1;i<=taxi;i++)
            {
                LL x,y;
                cin>>x>>y;
                t.push_back(MP(x,y));
            }

            int ts = t.size();
            int ps = p.size();

            for(int i=0;i<ts;i++)
            {
                LL tx = t[i].F;
                LL ty = t[i].S;

                for(int j=0;j<ps;j++)
                {
                    LL px = p[j].F;
                    LL py = p[j].S;

                    LL dis = abs(tx-px)+abs(ty-py);
                    dis*=200;

                    if(dis<=limit*speed)
                    {
                        graph[i+1].push_back(taxi+j+1);
                        graph[taxi+j+1].push_back(i+1);
                    }
                }
            }

            int ans = hopcroft_karp();
            cout<<ans<<endl;
        }


        return 0;
    }
