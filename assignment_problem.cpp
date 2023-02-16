#include<iostream>
#include<math.h>
using namespace std;

int setBitsCount(int n){
    int count = 0;
    while(n>0){
        if(n%2==1){
            count++;
        }
        n /= 2;
    }
    return count;
}


int main(){
    int n = 5;
    int size = pow(2,n);
    int dp[size];
    int cost[5][5] = {{10,5,13,15,16},
                      {3,9,18,13,6},
                      {10,7,2,2,2},
                      {7,11,9,7,12},
                      {7,9,10,4,12}};
    for(int i=0; i<size; i++){
        dp[i] = 9999999;
    }
    dp[0] = 0;
    
    int x = 0;
    for(int mask = 0; mask<size; mask++){
        x = setBitsCount(mask);
        for(int j=0; j<n; j++){
            if(!(mask&(1<<j))){
                dp[mask|1<<j] = min(dp[mask|1<<j], dp[mask]+cost[x][j]);
            }
        }
    }
    cout<<"Minimum cost: "<<dp[size-1]<<endl;
}


