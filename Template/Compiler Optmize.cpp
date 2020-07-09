#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")


/**

#pragma GCC optimize("Ofast")
- tells the compiler to optimize the code for speed to make is as fast as possible (and not look for space)

#pragma GCC optimize("unroll-loops")
- tells the compiler to unroll loops.
normally if we have a loop there is a ++i instruction somewhere.
We normally dont care because code inside the loop requires much more time but in this case there is only one instruction inside the loop so we want the compiler to optimize this.

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
- we want to tell the compiler that our cpu has simd instructions and allow him to vectorize our code

**/
