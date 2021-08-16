vector<int> compress(vector<int> &v) /// compress v to [1,max distinct number range]
{
    vector<int>c = v;
    map<int,int>m;

    for(int x:c) m[x] = 1;

    int val = 0;
    for(auto x:m) m[x.F] = ++val;

    for(int &x:c) x = m[x];

    return c;
}