#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];
bool visit[1000][1000];

int fun(int Gold[][1000],int n,int m,int i,int j){
    if(j>=m-1){
        return Gold[i][j];
    }
    if(visit[i][j]){
        return dp[i][j];
    }
    int ans = Gold[i][j] + fun(Gold,n,m,i,j+1);
    if(i < n-1){
        ans = max(ans,Gold[i][j]+fun(Gold,n,m,i+1,j+1));
    }
    if(i > 0){
        ans = max(ans,Gold[i][j]+fun(Gold,n,m,i-1,j+1));
    }
    dp[i][j] = ans;
    visit[i][j] = true;
    return dp[i][j];
}

int main() {
	int n,m;
	cin>>n>>m;
	int Gold[1000][1000];
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
	        cin>>Gold[i][j];
	    }
	}
	memset(visit,false,sizeof(visit));
	memset(dp,0,sizeof(visit));
	int res = 0;
	for(int i=0;i<n;i++){
	    res = max(res,fun(Gold,m,n,i,0));
	}
	cout<<res;
	return 0;
}

