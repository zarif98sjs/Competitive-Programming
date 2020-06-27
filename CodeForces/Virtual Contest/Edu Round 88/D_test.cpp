    #include <bits/stdc++.h>
    using namespace std;

    #define ris   return *this
    #define tmplt template<class T
    #define dbgo  debug& operator<<
    tmplt > struct rge { T b, e; };
    tmplt > rge<T> range(T i, T j) { return rge<T>{i, j}; }
    struct debug {
    #ifdef LOCAL
    ~debug(){cerr<<endl;}
    tmplt > dbgo(T x){cerr<<boolalpha<<x;ris;}
    tmplt, class C > dbgo(pair<T, C> x){ris<<"("<<x.first<<", "<<x.second<<")";}
    tmplt > dbgo(rge<T> x){*this<<"[";for(auto it=x.b;it!=x.e;it++){*this<<", "+2*(it==x.b)<<*it;}ris<<"]";}
    tmplt > dbgo(vector<T> x){ris<<range(x.begin(),x.end());}
    #else
    tmplt > dbgo(const T&){ris;}
    #endif
    };
    #define nav(...) << "[ " << #__VA_ARGS__ ": " << (__VA_ARGS__) << " ] "
    using ll = long long;

    #define forn(i, n) for(int i = 0; i < int(n); i++)
    #define ford(i, n) for(int i = n-1; i >= 0; i--)

    template<typename T>
    void min_self(T& a, T b) {
        a = min(a, b);
    }
    template<typename T>
    void max_self(T& a, T b) {
        a = max(a, b);
    }

    const int mxN = 100*1000+5;
    const int mxB = 65;
    const int B = 31;
    const int inf = 1e9+5;
    int dp[mxN][mxB];


    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int n;
        cin >> n;
        vector<int> a(n);
        forn(i, n) cin >> a[i];
        forn(i, mxN) forn(j, mxB) dp[i][j] = -inf;
        for(int i = 0; i < n; i++) {

            dp[i][a[i]+B] = 0;
            if(i > 0) {
                for(int j = 0; j <= a[i]+B; j++) {
                    max_self(dp[i][a[i]+B], dp[i-1][j] + j - B);
                }
            }

            for(int j = a[i]+B+1; j < mxB; j++) {
                max_self(dp[i][j], a[i] + (i == 0 ? -inf : dp[i-1][j]));
            }

        }

        int ans = 0;
        forn(i, n) forn(j, 2*B) cout<<i<<" , "<<j<<" : "<<dp[i][j];
        cout << ans << '\n';
    }













    // Spend more time thinking, it won't hurt

    // Read statement carefully
    // Solve on paper first!
    // Make your infinity big enough
    // Overflows (long long)

    // Author: blondie
