#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int SubsetSum(int n,int* arr,int k){
    if(n == 0){
        return 1;
    }
    if(n < 0 || k == 0){
        return 0;
    }
    if(dp[n][k] != -1){
        return dp[n][k];
    }
    int c = SubsetSum(n-arr[0],arr+1,k-1);
    int d = SubsetSum(n,arr+1,k-1);
    dp[n][k] = c+d;
    return dp[n][k];
}

int main() {
    memset(dp,-1,sizeof(dp));
    int k,n;
    cin>>k>>n;
    int arr[k];
    for(int i=0;i<k;i++){
        cin>>arr[i];
    }
    cout<<SubsetSum(n,arr,k);
	return 0;
}
