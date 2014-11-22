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
#define MAX 100000
/******************************************************************/
void reverse(char *from, char *to ) {
    int len=strlen(from);
    int l;
    for(l=0; l<len; l++)
        to[l]=from[len-l-1];
    to[len]='\0';
}
/******************************************************************/
void call_mult(char *first,char *sec,char *result) {
    char F[MAX],S[MAX],temp[MAX];
    int f_len,s_len,f,s,r,t_len,hold,res;
    f_len=strlen(first);
    s_len=strlen(sec);
    reverse(first,F);
    reverse(sec,S);
    t_len=f_len+s_len;
    r=-1;
    for(f=0; f<=t_len; f++)
        temp[f]='0';
    temp[f]='\0';
    for(s=0; s<s_len; s++) {
        hold=0;
        for(f=0; f<f_len; f++) {
            res=(F[f]-'0')*(S[s]-'0') + hold+(temp[f+s]-'0');
            temp[f+s]=res%10+'0';
            hold=res/10;
            if(f+s>r) r=f+s;
        }
        while(hold!=0) {
            res=hold+temp[f+s]-'0';
            hold=res/10;
            temp[f+s]=res%10+'0';
            if(r<f+s) r=f+s;
            f++;
        }
    }
    for(; r>0 && temp[r]=='0'; r--);
    temp[r+1]='\0';
    reverse(temp,result);
}
/***************************************************************/

#define  MX 100000
int primelen,N = MX,prime[20001];
bool  status[MX+100];

void prim()
{
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
    primelen = j;
}

int main()
{
#ifndef ONLINE_JUDGE
	READ("in.txt");
#endif
    int tc,n,num,cas=0,cnt,arr[MX],len;
    SDi(tc);
    prim();
    while(tc--){
        pf("Case %d: ",++cas);
        SDi(n);
        memca(arr);
        rep(i,n){
            SDi(num);
            rep(j,primelen){
                if(num<prime[j]) break;
                if(num%prime[j]==0){
                    cnt=0;
                    while(num%prime[j]==0)
                        ++cnt,num/=prime[j];
                    arr[ prime[j] ] = max(arr[ prime[j] ],cnt);
                }
            }
        }
        char ans[MAX],fir[MAX],sec[MAX],res[MAX];
        strcpy(ans,"1");
        rep(i,primelen){
            strcpy(fir,ans);
            rep(j,arr[ prime[i] ]){
                sprintf(sec,"%d",prime[i]);
                call_mult(fir,sec,res);
                strcpy(fir,res);
            }
            if(strcmp(fir,ans)!=0) strcpy(ans,res);
        }
        len = strlen(ans);
        rep(i,len) pf("%c",ans[i]);
        puts("");
    }
    return 0;
}
