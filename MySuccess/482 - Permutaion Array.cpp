#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("in.txt","r",stdin);
    int tc;
    cin>>tc;getchar();
    while(tc--){
        getchar();
        vector< int > idx;
        char line[100000];
        int cnt=0;
        {
            gets( line );
            stringstream ss( line );
            int num;
            while( ss >> num ) ++cnt,idx.push_back( num );
        }
        vector< string > v(cnt);
        gets(line);
        int i=0;
        {
            stringstream ss( line );
            string num;
            while( ss >> num ) v[ idx[i++] -1 ] = num ;
        }
        for(size_t i=0;i<v.size();i++){
//            if(i>0) cout<<" ";
            cout<<v[i]<<endl;
        }
        if(tc)
            puts("");
    }
    return 0;
}
