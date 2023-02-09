#include<iostream>
#include<string>
using namespace std;

int main(){
    string str1 = "abcda", str2 = "bdabac";
    int lcs[str1.length()][str2.length()];

    for(int i=0; i<=str1.length(); i++){
        for(int j=0; j<=str2.length(); j++){
            if(i==0 || j==0){
                lcs[i][j] = 0;
            }else if(str1[i-1] == str2[j-1]){
                lcs[i][j] = lcs[i-1][j-1] + 1;
            }else{
                lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
            }
        }
    }
    cout<<"\nLongest common subsequence: "<<lcs[str1.length()][str2.length()]<<endl;
}