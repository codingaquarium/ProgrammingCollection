/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)
UVa - 10660 - Citizen attention offices
*/
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

using namespace std;

/*** typedef ***/

#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
#define stream istringstream
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define INF (1<<30)
#define PI acos(-1.0)
#define pb push_back
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define memsp(x) mem(x,MEMSET_INF)
#define memdp(x) mem(x,-1)
#define memca(x) mem(x,0)
#define eps 1e-9
#define pii pair<int,int>
#define pmp make_pair
#define ft first
#define sd second
#define vi vector<int>
#define vpii vector<pii>
#define si set<int>
#define msi map<string , int >
#define mis map<int , string >
typedef long long i64;
typedef unsigned long long ui64;

/** function **/

#define SDi(x) sf("%d",&x)
#define SDl(x) sf("%lld",&x)
#define SDs(x) sf("%s",x)
#define SD2(x,y) sf("%d%d",&x,&y)
#define SD3(x,y,z) sf("%d%d%d",&x,&y,&z)
#define pf printf
#define sf scanf

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

int dis(int x,int y,int p,int q){
    return abs(x-p) + abs(y-q);
}

int main()
{
#ifndef ONLINE_JUDGE
	READ("in.txt");
#endif
    int grid[5][5],tc,n,mindis,sum;
    int ansA , ansB , ansC , ansD , ansE ;
    cin>>tc;
    while(tc--){
        SDi(n);
        memca(grid);
        rep(i,n){
            int x,y,w;
            SD3(x,y,w);
            grid[x][y] = w;
        }
        mindis = 1<<28;
        FOR(a,0,24) FOR(b,a+1,24) FOR(c,b+1,24) FOR(d,c+1,24) FOR(e,d+1,24){
            sum = 0;
            rep(i,5) rep(j,5){
                int A = dis(i,j,a/5,a%5)*grid[i][j];
                int B = dis(i,j,b/5,b%5)*grid[i][j];
                int C = dis(i,j,c/5,c%5)*grid[i][j];
                int D = dis(i,j,d/5,d%5)*grid[i][j];
                int E = dis(i,j,e/5,e%5)*grid[i][j];
                sum+=min(min(A,min(B,C)),min(D,E));
            }
            if(sum < mindis){
                mindis = sum;
                ansA = a, ansB = b, ansC = c, ansD = d, ansE = e;
            }
        } pf("%d %d %d %d %d\n",ansA,ansB,ansC,ansD,ansE);
    }
    return 0;
}