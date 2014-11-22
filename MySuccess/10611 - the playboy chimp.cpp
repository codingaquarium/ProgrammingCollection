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
    vector< U > v;
    vector<U>::iterator low,up;
    bool a[50011];
    int n;
    memset(a,false,sizeof(a));
    scanf("%d",&n);
    v.pb(0);
    REP(i,n)
    {
        int aa;
        scanf("%d",&aa);
        v.pb(aa);
        a[aa] = true;
    }
    U inf = 1<<31;//cout<<inf<<"\n";
    v.pb(inf);
    sort(v.bg(),v.end());
    int cas;
    scanf("%d",&cas);
    U hi,lo;
    while(cas--)
    {
        int num;
        scanf("%d",&num);
        low = lower_bound (v.bg(), v.end(),num);
        up = upper_bound (v.bg(), v.end(),num);

        /*if(a[num])
        {*/
            lo = low - v.begin()-1;
            hi = up - v.begin();
        /*}
        else
        {
            lo = low - v.begin()-1;
            hi = up - v.begin();
        }*/
        if(v[lo]==0) printf("X %d\n",v[hi]);
        else if(v[hi] == inf) printf("%d X\n",v[lo]);
        else printf("%d %d\n",v[lo],v[hi]);
    }
    v.clear();
    return 0;
}

/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main () {
  int myints[] = {1,4,5,7};
  vector<int> v(myints,myints+4);           // 10 20 30 30 20 10 10 20
  vector<int>::iterator low,up;
                                            //1 4 5 7
  sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  low=lower_bound (v.begin(), v.end(), 6); //          ^
  up= upper_bound (v.begin(), v.end(), 6); //                   ^

  cout << "lower_bound at position " << int(low- v.begin()) << endl;
  cout << "upper_bound at position " << int(up - v.begin()) << endl;

  return 0;
}*/

