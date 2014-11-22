// copied
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cstdlib>
using namespace std;

int main() {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int testCase;
    scanf("%d",&testCase);
    for(int p=1; p<=testCase; p++) {
        if(p!=1)printf("\n");
        int m,n;
        char grid[500][500];
        scanf("%d %d ",&m,&n);
        for(int i=0; i<m; i++) {
            char temp[500];
            gets(temp);
            for(int j=0; j<strlen(temp); j++)temp[j] = tolower(temp[j]);
            strcpy(grid[i],temp);
        }
        int query;
        scanf("%d ",&query);

        for(int i=0; i<query; i++) {
            char findMe[500];
            gets(findMe);
            for(int j=0; j<strlen(findMe); j++)findMe[j] = tolower(findMe[j]);

            for(int i=0; i<m; i++) {
                int found = 0;
                for(int j=0; j<n; j++) {

                    if(grid[i][j]==findMe[0]) { //first word matches...
                        //Left search might works...
                        if(j>=strlen(findMe)-1) {
                            //all 3 left possible
                            int left = 1,leftUp = 1,leftDown = 1;
                            for(int m1=0; m1<strlen(findMe); m1++) {
                                if(left==1||leftUp==1||leftDown==1) {
                                    //straight left
                                    if(findMe[m1] != grid[i][j-m1]&&left==1) {
                                        left = 0;
                                    }
                                    //left up
                                    if((findMe[m1]!=grid[i-m1][j-m1]||!(i>=strlen(findMe)-1))&&leftUp==1) {
                                        leftUp = 0;
                                    }
                                    //left down
                                    if((findMe[m1]!=grid[i+m1][j-m1]||!((m-i)>=strlen(findMe)) ) && leftDown==1) {
                                        leftDown=0;
                                    }
                                } else break;
                            }
                            if(left==1||leftUp==1||leftDown==1) {
                                found = 1;
                                printf("%d %d\n",i+1,j+1);
                            }
                        }//end of left search
                        if(found==1) break;
                        //Right search might works..
                        if((n-j)>=strlen(findMe)) {
                            int right=1,rightUp=1,rightDown=1;
                            for(int m1=0; m1<strlen(findMe); m1++) {
                                if(right==1||rightUp==1||rightDown==1) {
                                    //straight right
                                    if(findMe[m1]!=grid[i][j+m1]&&right==1) {
                                        right = 0;
                                    }
                                    //right up
                                    if((findMe[m1]!=grid[i-m1][j+m1]||!(i>=strlen(findMe)-1))&&rightUp==1) {
                                        rightUp = 0;
                                    }
                                    //right down
                                    if((findMe[m1]!=grid[i+m1][j+m1]||!((m-i)>=strlen(findMe)) ) && rightDown==1) {
                                        rightDown=0;
                                        //printf("%d >= %d\n",m,strlen(findMe));
                                    }
                                } else break;
                            }
                            if(right==1||rightUp==1||rightDown==1) {
                                found = 1;
                                printf("%d %d\n",i+1,j+1);
                            }
                        }//end of right search
                        if(found==1)break;
                        //Up search might works...
                        if(i>=strlen(findMe)-1) {
                            int up = 1;
                            for(int m1=0; m1<strlen(findMe); m1++) {
                                if(findMe[m1] != grid[i-m1][j]) {
                                    up = 0;
                                    break;
                                }
                            }
                            if(up==1) {
                                found = 1;
                                printf("%d %d\n",i+1,j+1);
                            }
                        }//end of up search
                        if(found==1)break;
                        //down search might works...
                        if((m-i)>=strlen(findMe)) {
                            int down = 1;
                            for(int m1=0; m1<strlen(findMe); m1++) {
                                if(findMe[m1] != grid[i+m1][j]) {
                                    down = 0;
                                    break;
                                }
                            }
                            if(down==1) {
                                found = 1;
                                printf("%d %d\n",i+1,j+1);
                            }
                        }//end of down search
                        if(found==1)break;
                    }
                }
                if(found==1)break;
            }
        }
    }
    return 0;
}
