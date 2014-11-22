#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include<iostream>

#define MAXN 1000010
using namespace std;
vector<int> parent;
//vector<int> value;
//vector<int>result;
struct edge {
    int u,v,w;
    bool operator < ( const edge& p ) const {
        return w < p.w;
    }
};
vector<edge>e;

int setFind(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = setFind(parent[x]);
}
bool isUnion(int a,int b) { //to check either 2 given nodes are on same set
    return ( setFind(a)==setFind(b) );
}
void init(int _n){ parent.resize(_n);for(size_t i=0;i<parent.size();i++) parent[i] = i; }

int mst(int num) {
    sort(e.begin(),e.end());// Sort edges of G in increasing-order;
    int count=0,s=0;
    for(int i=0; i<(int)e.size(); i++) { //for each edge e = (u,v) in order
        if(!isUnion(e[i].u,e[i].v)) { //if u and v are not in the same set
            parent[setFind(e[i].u)] = setFind(e[i].v);
            s+=e[i].w;
            count++;
            if(count==num-1) break;
        }
    }
    return s;
}

int main() {
    freopen("in.txt","r",stdin);
    int num,cse=0;
    edge get;
    while(~scanf("%d",&num)){
        if(cse) cout<<endl;
        cse = 1;
        parent.clear();
        e.clear();
        int total=0;
        for(int i=0; i<num-1; i++) {
            int u,v,w;
            cin>>u>>v>>w;
            total+=w;
        }
        int k;
        cin>>k;
        for(int i=0; i<k; i++) {
            cin>>get.u>>get.v>>get.w;
            e.push_back(get);
        }
        int m;
        cin>>m;
        for(int i=0; i<m; i++) {
            cin>>get.u>>get.v>>get.w;
            e.push_back(get);
        }
        init(num+10);
        cout<<total<<endl<<mst(num)<<endl;
    }
    return 0;

}
