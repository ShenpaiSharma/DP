#include <bits/stdc++.h>
using namespace std;

bool fun(int* arr,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%2 != 0) return false;
    bool dp[sum/2 + 1][n+1];
    for(int i=0;i<=n;i++){
        dp[0][i] = true;
    }
    for(int i=1;i<=sum/2;i++){
        dp[i][0] = false;
    }
    for(int i=1;i<=sum/2;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = dp[i-1][j];
            if(i >= arr[j-1]){
                dp[i][j] = dp[i][j] || dp[i-arr[j-1]][j-1];
            }
        }
    }
    return dp[sum/2][n];
}

int main() {
	int n;
	cin>>n;
	int* arr = new int[n];
	memset(arr,0,sizeof(arr));
	for(int i=0;i<n;i++){
	    int x;
	    cin>>x;
	    arr[i] = x;
	}
	if(fun(arr,n)) cout<<"Possible";
	else cout<<"No";
	return 0;
}
