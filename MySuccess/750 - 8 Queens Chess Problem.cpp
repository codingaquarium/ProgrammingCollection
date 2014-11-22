#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int x[10];
int c=1;
int row,col,cou=1;;
void nqueen(int ,int);
bool place(int,int);
int main() {
    freopen("in.txt","r",stdin);
    int test;
    scanf("%d",&test);
    while(test--) {
        scanf("%d %d",&row,&col);
        cou=1;
        printf("SOLN       COLUMN\n");
        printf(" #      1");
        for(int i=2; i<=8; i++)
            cout<<" "<<i;
        cout<<endl<<endl;
        if(col==1) {
            x[col]=row;
            nqueen(2,8);
        } else  nqueen(1,8);
        if(test)cout<<endl;
    }
    return 0;
}
void nqueen(int k,int n) {
    if(k==col) {
        if(place(k,row)) {
            //if(c==0)return;
            x[k]=row;
            if(k==n) {
                printf("%2d     ",cou++);//cout<<" "<<cou++<<"     ";
                for(int i=1; i<=8; i++) {
                    printf(" %d",x[i]);
                }
                cout<<endl;
                //c=0;return;
            } else nqueen(k+1,n);
        }
    } else {
        for(int i=1; i<=n; i++) {
            if(place(k,i)) {
                //if(c==0)return;
                x[k]=i;
                if(k==n) {
                    printf("%2d     ",cou++);//cout<<" "<<cou++<<"     ";
                    for(int i=1; i<=8; i++) {
                        printf(" %d",x[i]);
                    }
                    cout<<endl;
                    //c=0;return;
                } else nqueen(k+1,n);
            }
        }
    }
}
bool place(int k,int i) {
    for(int j=1; j<=k-1; j++) {
        if((x[j]==i)||(abs(x[j]-i)==abs(j-k)))
            return false;
    }
    return true;
}
