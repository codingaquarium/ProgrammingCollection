
/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)

 */
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define stream istringstream
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define repv(i,n) for(int i=n-1; i>=0; i--)
#define repl(i,n) for(int i=1; i<=(int)n; i++)
#define replv(i,n) for(int i=n; i>=1; i--)


#define INF (1<<28)
#define PI 3.14159265358979323846264338327950
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<int,int>
#define pmp make_pair


#define sdi(x) scanf("%d",&x)
#define sdii(x,y) scanf("%d%d",&x,&y)
#define SDs(x) scanf("%s",x)
#define uu first
#define vv second

using namespace std;

typedef long long i64;
typedef unsigned long long ui64;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

int c[200], a[200];
int n, k;
int dp[1003][51];
int MOD = 100000007;
int call(int amount, int idx) {
    if (idx > n) {
        if (amount == k) return 1;
        return 0;
    }

    if (amount > k) return 0;
    if (amount == k) return 1;
    if (dp[amount][idx] != -1) return dp[amount][idx];
    int ret = 0;

    for (int take = 1; take <= c[idx]; take++) {
        if (amount + a[idx]*take <= k)
            ret += call(amount + a[idx] * take, idx + 1) % MOD;
        else break;
    }
    ret += call(amount, idx + 1) % MOD;
    return dp[amount][idx] = ret % MOD;
}
int main() {
    int t, kas = 0;
    cin >> t;
    while (t--) {
        mem(dp, -1);
        sdii(n, k);
        repl(i, n)sdi(a[i]);
        repl(i, n)sdi(c[i]);
        int ret = call(0, 1) % MOD;
        printf("Case %d: %d\n", ++kas, ret);
    }
}

