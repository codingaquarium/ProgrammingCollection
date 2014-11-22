#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
    int a,b,c,sz,ans,cnt=0;
    char ch[100],temp,sign;
    while(gets(ch)){
        sz = (int)strlen(ch);
        if(ch[sz-1]=='?') continue;
        sscanf(ch,"%d %c %d  %c %d",&a,&sign,&b,&temp,&c);
        if(sign=='+') ans = a+b;
        else ans = a-b;
        if(c==ans) cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
