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

int main(){
#ifndef ONLINE_JUDGE
	READ("in.txt");
#endif
    char *ch = new char[1000];
    string str="";
    int  len;
    while(gets(ch) && strcmp(ch,"#")){
        len = strlen(ch);
        rep(i,len){
            if(isalpha(ch[i]) or ch[i]=='-' or ch[i]==32) str+=ch[i];
        } str+='\n';
    }
    rep(i,str.length()){
        if(str.at(i)=='-' and str.at(i+1)=='\n'){
            str.erase(i,1);
            str.erase(i,1);
//            cout<<"Erase: "<<str<<endl;
            for(int j=i;j>=0;j--)
                if(str[j]==32 or str[j]=='\n' or j==0){
                    str.insert(j+1,"\n");
                    break;
                }
//            cout<<"before ins: "<<str<<endl;
            for(size_t j=i;j<str.length();j++)
                if(str[j]==32){
                    str.insert(j,"\n");
                    break;
                }
//            cout<<"after ins: " <<str<<endl;
        }
    }
    cout<<str;
    return 0;
}
