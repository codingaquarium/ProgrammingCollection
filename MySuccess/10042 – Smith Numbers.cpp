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

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define  MX 31622

int N = MX,prime[200001],pr_sz;
bool  status[MX+100];

void prim(){
  int i, j, sqrtN;

  sqrtN = int( sqrt( N ) );
  for( i = 2; i <= sqrtN; i += 1 )
    if( status[i] == 0 )
       for( j = 2*i; j <= N; j += i )
          status[j] = 1;

  prime[0]=2;
  for( i = 3,j=1; i <= N; i += 2 )
    if( status[i] == 0 )
        prime[j++]=i;
  pr_sz = j;
}
int sumofDigits(int n){
    int sum = 0 ;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int primefactors(int n){
    int sum = 0,k=n;

    if(n<=31622)
        if( status[n]==true )
            return -1;

    int sqrtN = int( sqrt(n) );
    for( int i = 0; prime[i] <= sqrtN and i<pr_sz; i++ ) {
        if( n % prime[i] == 0 ) {
            int cnt=0;
            while(n%prime[i]==0) {
                cnt++;
                n/=prime[i];
            }
            sum+=cnt*sumofDigits(prime[i]);
            sqrtN=sqrt(n);
        }
    }
    if(n==k)
        return -1;
    if(n>1) {
        sum+=sumofDigits(n);
    }
    return sum;
}

int main () {
#ifndef ONLINE_JUDGE
    READ("in.txt");
    cout<<"hello world!"<<endl;
#endif
    int tc,num;
    SDi(tc);
    prim();
    while(tc--){
        SDi(num);
        for(int i=num+1;;i++){
            if(sumofDigits(i)==primefactors(i)){
                pf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
