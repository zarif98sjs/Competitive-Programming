/*
    Author       :  Jan
    Problem Name :
    Algorithm    :
    Complexity   :
*/

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


using namespace std;

int cases;
int cap[101][101];

int main() {
    freopen("in.txt", "w", stdout);

    cases = 48;
    printf("%d\n", cases);
    while( cases-- ) {
        fprintf( stderr, "%d\n", cases );
        memset( cap, 0, sizeof(cap) );
        int n = 15 - rand() % 5;
//        if( cases % 5 == 4 ) n = 100;
//
//        if( cases % 3 ) n = 100 - rand() % 10;
//
//        if( cases == 17 ) n = 2;
//        if( cases == 18 ) n = rand() % 10 + 2;
//        if( cases == 19 ) n = 100;

        printf("%d\n", n);
        for( int i = 0; i < n; i++ ) {
            if( i ) putchar(' ');
            int k = rand() % 1000 +1;
            if( cases % 2 ) k = rand() % 10 + 10;
            if( rand() % 2 ) k = rand() % 20 + 20;
            printf("%d", k);
        }
        puts("");

        int save[10005][3];
        int m = rand() % 6;

        memset( cap, 0, sizeof(cap) );
        int k = 0;
        while( m-- ) {
            int i = rand() % n + 1;
            int j = rand() % n + 1;
            if( i == j || cap[i][j] ) {
                if( rand() % 2 ) m++;
                continue;
            }
            cap[i][j] = 1;
            save[k][0] = i;
            save[k][1] = j;
            int x = rand() % 1000 + 1;
            if( rand() % 5 || ( cases & 1 ) ) x = rand() % 100 + 20;
            save[k++][2] = x;
        }
        printf("%d\n", k);
        while( k-- ) {
            printf("%d %d %d\n", save[k][0], save[k][1], save[k][2]);
        }
        int fl[105] = {0};

        k = rand() % n;
        int taken = 0;
        while( k-- > 0 || taken == 0 ) {
            int u = rand() % n + 1;
            if( fl[u] ) continue;
            fl[u] = 1;
            taken++;
        }
        int A = taken;
        k = rand() % n;
        taken = 0;
        while( k-- > 0 || taken == 0 ) {
            int u = rand() % n + 1;
            if( fl[u] ) continue;
            fl[u] = 2;
            taken++;
        }
        int B = taken;
        printf("%d %d\n", A, B);
        bool flag1 = 0;
        for( int i = 1; i <= n; i++ ) if( fl[i] == 1 ) {
            if( flag1 ) putchar(' ');
            flag1 = true;
            printf("%d", i);
        }
        for( int i = 1; i <= n; i++ ) if( fl[i] == 2 ) {
            if( flag1 ) putchar(' ');
            flag1 = true;
            printf("%d", i);
        }
        puts("");
    }
    return 0;
}
