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

template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }

char first[100],second[100],input[1000];
int firstBase[40],secondBase[40];

void convert(char *ch, int c){
    int maxBase=0,res,sz = strlen(ch),ans = 0;
    rep(i,sz){
        if(isdigit(ch[i])) res = ch[i] - 48;
        else res = ch[i] - 55;
        maxBase = max(maxBase,res);
    }
    maxBase++;
    FOR(i,maxBase,36){
        ans = 0;
        for(int j=sz-1;j>=0;j--){
            if(isdigit(ch[j])) res = ch[j] - 48;
            else res = ch[j] - 55;
            ans+=(res*power(i,sz - j  - 1));
        }
        if(c==1) firstBase[i] = ans;
        else secondBase[i] = ans;
    }
}

bool foundMatch(){
    FOR(i,2,36){
        FOR(j,2,36)
            if(firstBase[i]==secondBase[j]){
                pf("%s (base %d) = %s (base %d)\n", first, i, second, j);
                return true;
            }
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	READ("in.txt");
#endif
    while(gets(input)){
        rep(i,40) firstBase[i] = -2;
        memdp(secondBase);
        sscanf(input,"%s %s",first,second);
        convert(first,1);
        convert(second,2);
        if(!foundMatch())
            pf("%s is not equal to %s in any base 2..36\n", first, second);
    }
    return 0;
}
