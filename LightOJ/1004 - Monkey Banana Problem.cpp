#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>

/*** typedef ***/

#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
#define stream istringstream
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define INF (1<<30)
#define PI 3.14159265358979323846264338327950
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define memsp(x) mem(x,MEMSET_INF)
#define memdp(x) mem(x,-1)
#define memca(x) mem(x,0)
#define eps 1e-9
#define pii pair<int,int>
#define pmp make_pair
#define vi vector<int>
#define vpii vector<pii>
#define si set<int>
#define msi map<string , int >
typedef long long i64;
typedef unsigned long long ui64;

/** function **/

#define SDi(x) scanf("%d",&x)
#define SDl(x) scanf("%lld",&x)
#define SDs(x) scanf("%s",x)
#define SD2(x,y) scanf("%d%d",&x,&y)
#define SD3(x,y,z) scanf("%d%d%d",&x,&y,&z)

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

int input[210][210];
int dp[210][210];

int main() {
    int tc,cas=1;
    cin>>tc;
    while(tc--) {
        int n;
        cin>>n;
        memdp(dp);
        printf("Case %d: ",cas++);
        FOR(i,1,n)
        FOR(j,1,i)
        SDi(input[i][j]);
        int k=n-1;
        for(int i=n+1; i<=2*n-1; i++,k--)
            for(int j=1; j<=k; j++)
                SDi(input[i][j]);
        dp[1][1]=input[1][1];
        FOR(i,2,n) {
            FOR(j,1,i) {
                dp[i][j]=max(dp[i-1][j]+input[i][j],dp[i-1][j-1]+input[i][j]);
            }//puts("");
        }
        k=n-1;
        for(int i=n+1; i<=2*n-1; i++,k--) {
            for(int j=1; j<=k; j++) {
                dp[i][j]=max(dp[i-1][j]+input[i][j],dp[i-1][j+1]+input[i][j]);
            }//puts("");
        }
        printf("%d\n",dp[2*n-1][1]);
    }
    return 0;
}
