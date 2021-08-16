template <class T>
T po(T b, T p) /// Faster than recursive one
{
    T res = 1, x = b;
    while ( p ) {
        if ( p & 1 ) res = ( res * x );
        x = ( x * x );
        p >>= 1;
    }
    return res;
}