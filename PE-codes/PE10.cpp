/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)

*/

#include <bits/stdc++.h>
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
#define ii pair<int,int>
#define pmp make_pair
#define ft first
#define sd second
#define vi vector<int>
#define vii vector<ii>
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
#define pfcas(x) pf("Case %d: ",x)

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

const int N=2000000;

int visit[N/32+50];
unsigned int data[5800000];
int prime[5800000],np=0;
i64 sum = 0L;
void Prime (){
    prime[0]=data[0]=2;
    sum = 2L;
    np=1;
    for (int i=3;i<N;i+=2)
        if (!(visit[i/32] & (1 << ((i/2)%16)))){
            prime[np]=i;
            sum+=(i64)i;
            data[np]=data[np-1]*i;
            np++;
            for (int j=3*i;j<N;j+=2*i)
                visit[j/32] |= (1 << ((j/2)%16));
        }
        cout<<sum<<endl;
}


int main (int argc, char **argv) {
    Prime();
    return 0;
}

