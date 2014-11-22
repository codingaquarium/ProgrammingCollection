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

struct node {
    int level,row,column,color,dis;
    char ch;
}a[35][35][35];
int l,r,c;
queue< node > q;
void reset(){
    rep(i,l) rep(j,r) rep(k,c)
        a[i][j][k].color = 0, a[i][j][k].ch='#',a[i][j][k].dis = INT_MAX,
        a[i][j][k].level = i, a[i][j][k].row = j, a[i][j][k].column = k;
}

void input(){
    rep(i,l) rep(j,r) rep(k,c){
        cin>>a[i][j][k].ch;
        if(a[i][j][k].ch=='S'){
            a[i][j][k].color = 1;
            a[i][j][k].dis = 0;
            q.push(a[i][j][k]);
        }
    }
}

void bfs(){
    int tl,tr,tc,dist;
    node u,v;
    while(q.size()){
        u = q.front();
        q.pop();
        if(u.ch=='E'){
            pf("Escaped in %d minute(s).\n",u.dis);
            return;
        }
        tl = u.level, tr = u.row, tc = u.column, dist = u.dis;
//        pf("%d %d %d %d\n",tl,tr,tc,dist);
        /** norht */
        if(tr-1>=0){
            v = a[tl][tr-1][tc];
            if(v.ch!='#' and v.color==0 ){
                v.dis = dist + 1;
                a[tl][tr-1][tc].color = 1;
                q.push(v);
            }
        }
        /** south */
        if(tr+1<r){
            v = a[tl][tr+1][tc];
            if(v.ch!='#' and v.color==0 ){
                v.dis = dist + 1;
                a[tl][tr+1][tc].color = 1;
                q.push(v);
            }
        }
        /** east */
        if(tc-1>=0){
            v = a[tl][tr][tc-1];
            if(v.ch!='#' and v.color==0 ){
                a[tl][tr][tc-1].color = 1;
                v.dis = dist + 1;
                q.push(v);
            }
        }
        /** west */
        if(tc+1<c){
            v = a[tl][tr][tc+1];
            if(v.ch!='#' and v.color==0 ){
                a[tl][tr][tc+1].color = 1;
                v.dis = dist + 1;
                q.push(v);
            }
        }
        /** up*/
        if(tl+1<l){
            v = a[tl+1][tr][tc];
            if(v.ch!='#' and v.color==0){
                a[tl+1][tr][tc].color = 1;
                v.dis = dist + 1;
                q.push(v);
            }
        }
        /** down */
        if(tl-1>=0){
            v = a[tl-1][tr][tc];
            if(v.ch!='#' and v.color==0){
                a[tl-1][tr][tc].color = 1;
                v.dis = dist + 1;
                q.push(v);
            }
        }
    } puts("Trapped!");
}

int main (int argc, char **argv) {
#ifndef ONLINE_JUDGE
    READ("in.txt");
    cout<<"hello world!"<<endl;
#endif
    while(SD3(l,r,c)&&l&&r&&c){
        getchar();
        reset();
        input();
        bfs();
        while(q.size()) q.pop(); //clearing queue
    }
    return 0;
}
