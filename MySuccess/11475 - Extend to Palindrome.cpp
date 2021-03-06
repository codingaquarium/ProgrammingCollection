/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)

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

int cal[1000000];

void compute_prefix_function(string pattern) {
    int k,i,m = pattern.size();
    i = 1,k=0;
    cal[0] = 0;
    while( i<m ){
        if(pattern[i]==pattern[k])
            cal[++i] = ++k;
        else if(k==0)
            cal[++i] = 0;
        else k = cal[k];
    }
}

int KMP(string str,string pattern) {
    compute_prefix_function(pattern);
    int n = str.size();
    int m = pattern.size();
    int i = 0, j = 0;
    while(i<n) {
        while(j<m)
            if(str[i]==pattern[j]) ++i,++j;
            else break;
        if(i==n) return j;
        if(j==0) i++;
        else j = cal[j];
    } return 0;
}

int main() {
#ifndef ONLINE_JUDGE
	READ("in.txt");
#endif
    string str, pattern,ans;
    while(cin>>str) {
        memca(cal);
        pattern = str;
        reverse(all(pattern));
        ans = str.substr(0,str.size() - KMP(str,pattern));
        cout<<str + string(ans.rbegin(),ans.rend()) <<endl;
    }
    return 0;
}
