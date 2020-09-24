#include <bits/stdc++.h>
using namespace std;

int dp[1000];
bool vis[1000];
int ans = 0;
int fun(int arr[],int n){
	if(n <= 0){
		return 0;
	}
	if(vis[n]){
		return dp[n];
	}
	for(int i=0;i<n;i++){
		if(n-i >= 0){
			ans = max(ans,arr[i] + fun(arr,n-i-1));
		}
	}
	dp[n] = ans;
	vis[n] = true;
	return ans;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	memset(dp,0,sizeof(dp));
	memset(vis,false,sizeof(vis));
	cout<<fun(arr,n);
	return 0;
}
