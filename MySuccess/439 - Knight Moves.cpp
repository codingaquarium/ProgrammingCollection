/*
Shiakh Shiam Rahman 
UVa : 439 - Knight Moves
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<utility>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#include<list>
#include<iterator>
#include <bitset>
using namespace std;

#define REP(i,n) for(__typeof(n) i=0; i<(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define CLEAR(t) memset((t), 0, sizeof(t))
typedef long long int64;
typedef long double d64;
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define PI 3.1415926535897932384626433832
#define INF (1<<30)
#define eps 1e-8
#define pb push_back
#define ppb pop_back
#define bg begin
#define U unsigned
#define pii pair<int,int>
template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T sq(T n) { return n*n; }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }
template< class T > T power(T N,T P){ if(P==0) return 1; return (P==1)?  N: N*power(N,P-1); }

int main()
{
    READ("in.txt");
    int m,n,p,q;
    char ch[100],so[10],ds[10];
    char s,d,ff;
    while(gets(ch))
    {
        sscanf(ch,"%c%d%c%c%d",&s,&n,&ff,&d,&q);
        sscanf(ch,"%s %s",so,ds);
        m = s-96;
        p = d-96;
        pii sor,dis;
        sor = make_pair(m,n);
        dis = make_pair(p,q);
        queue < pii > Q;
        Q.push(sor);
        map < pii,bool > m;
        map < pii,int > distan;
        while(!Q.empty())
        {
            pii e = Q.front();
            if(e == dis)
            {
                printf("To get from %s to %s takes %d knight moves.\n",so,ds,distan[e]);
                break;
            }
            int ax[] = {2,2,-2,-2,1,-1,1,-1};
            int ay[] = {1,-1,1,-1,2,2,-2,-2};
            REP(i,8)
            {
                int x,y;
                x = e.first+ax[i];
                y = e.second+ay[i];
                pii ne = make_pair(x,y);
                if(!m[ne]&&(x>0 && y>0 && x<=8 && y<=8))
                {
                    m[ne] = true;
                    Q.push(ne);
                    distan[ne] = distan[e] + 1;
                }
            }
            Q.pop();
        }
        m.clear();
        distan.clear();
    }
    return 0;
}