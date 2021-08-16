template <class T>
T bm(T b, T p, T m ) /// Faster than recursive one
{
    T res = 1 % m, x = b % m;
    while ( p )
    {
        if ( p & 1 )
            res = ( 1LL * res * x ) % m;
        x = ( 1LL* x * x ) % m;
        p >>= 1;
    }
    return res;
}
