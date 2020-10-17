#include <bits/stdc++.h>
using namespace std;

int n,m;
int dp[10000][10000];

int fun(int s[],int n,int m){
    int table[m+1][n];
    for(int i=0;i<n;i++){
        table[0][i] = 1;
    }
    int x,y;
    for(int i=1;i<=m;i++){
        for(int j=0;j<n;j++){
            if(i-s[j] >= 0){
                x = table[i-s[j]][j];
            }
            else x =0;
            if(j>0){
                y = table[i][j-1];
            }
            else y=0;
            table[i][j] = x+y;
        }
    }
    return table[m][-1];
}

int main() {
	
	cin>>n>>m;
	int s[n];
	for(int i=0;i<n;i++){
	    cin>>s[i];
	}
	memset(dp,-1,sizeof(dp));
	cout<<count(s,n,m)<<endl;
	cout<<fun(s,n,m);
	return 0;
}
