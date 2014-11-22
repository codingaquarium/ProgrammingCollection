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
#define MAX 20010

char fname[1000][100],lname[1000][100],dialer[1000][10],trans[1000][100];
char button[] = {"22233344455566677778889999"};

int main (int argc, char **argv) {
    char input[1024];
    int i=0,j,fen,len;
    while(gets(input)){
        if(isdigit(input[0])) break;
        sscanf(input,"%s %s %s",fname[i],lname[i],dialer[i]);

        fen = strlen(fname[i]);
        len = strlen(lname[i]);
        rep(m,fen) fname[i][m] = tolower(fname[i][m]);
        rep(m,len) lname[i][m] = tolower(lname[i][m]);

        trans[i][0] = button[ fname[i][0] - 'a'];
        for(j=0;lname[i][j];j++)
            trans[i][j+1] = button[ lname[i][j] - 'a'];
        trans[i][j+1] = NULL;
        i++;
    }
    do{
        bool flag = false;
        rep(m,i){
            if(strcmp(dialer[m],input)==0){
                puts(input);
                flag = true;
            }
        }
        if(flag) continue;
        len = strlen(input);
        rep(m,i){
            for(j=0;input[j];j++){
                if(input[j]!=trans[m][j]) break;
            }
            if(j==len){
                if(flag) putchar(' ');
                flag = true;
                printf("%s",dialer[m]);
            }
        }
        if(flag) puts("");
        else puts("0");
    }while(gets(input));
    return 0;
}

