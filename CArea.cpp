#include <bits/stdc++.h>
using namespace std;

class Area{
public:
	int a;
	int b;
	int id;
};

int dp[1000][1000];
bool visit[1000][1000];
int ans = 0;
int fun(Area X,Area Y,Area Z,int A,int B,int i){
	if(A <= 0 || B <= 0){
		return 0;
	}
	if(visit[A][B]){
		return dp[A][B];
	}
	if(i != X.id){
		ans = max(ans,1+fun(X,Y,Z,A+X.a,B+X.b,0));
	}
	if(i != Y.id){
		ans = max(ans,1+fun(X,Y,Z,A+Y.a,B+Y.b,1));
	}
	if(i != Z.id){
		ans = max(ans,1+fun(X,Y,Z,A+Z.a,B+Z.b,2));
	}
	dp[A][B] = ans;
	visit[A][B] = true;
	return dp[A][B];
}

int main(){
	int A,B;
	Area X,Y,Z;
	cin>>A>>B;
	cin>>X.a>>X.b;
	cin>>Y.a>>Y.b;
	cin>>Z.a>>Z.b;
	X.id = 0;
	Y.id = 1;
	Z.id = 2;
	memset(visit,false,sizeof(visit));
	memset(dp,0,sizeof(dp));
    int res = max(fun(X,Y,Z,A+X.a,B+X.b,0),max(fun(X,Y,Z,A+Y.a,B+Y.b,1),fun(X,Y,Z,A+Z.a,B+Z.b,2)));
	cout<<res;
	return 0;
}
