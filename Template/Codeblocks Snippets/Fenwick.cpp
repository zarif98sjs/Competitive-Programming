struct Fenwick{

    vector<LL>BIT;
    int N;

    Fenwick (int n) : BIT(n+1,0) , N(n) {}

    inline int LSB(int x) {return x&(-x);} /// find the number with first bit set

    /// POINT update : adds val to index idx
    void add(int idx,LL val)
    {
        for(int i = idx ; i<=N ; i += LSB(i)) /// adding LSB , jumping to next segment covered by this index
            BIT[i] += val;
    }

    /// prefix sum upto index idx
    LL pref(int idx)
    {
        LL sum = 0;

        for(int i = idx ; i>0 ; i -= LSB(i)) /// removing LSB , jumping to next segment covering upto index
            sum += BIT[i];

        return sum;
    }

    void debug()
    {
        cout<<"Prefix Sum Array : ";
        for(int i=1;i<=N;i++)
            cout<<pref(i)<<" ";
        cout<<endl;
    }
};