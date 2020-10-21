#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define fori(a) for(auto i : a )
#define all(a) begin(a), end(a)
#define set(a,b) memset(a,b,sizeof(a))
#define pi 3.14159
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PF push_front //deque
#define mp make_pair
#define pq priority_queue
const ll mod=1e9+7;
#define f first
#define s second
#define pii pair< int, int >
//#define tc int t; cin >> t; while(t--)
using namespace std;
#define debug(v) for(auto i:v) cout<<i<<" ";

void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

/*ll MOD(ll x){
    return ((x%mod + mod)%mod);
}

ll add(ll a,ll b){
    return MOD(MOD(a)+MOD(b));
}

ll mul(ll a, ll b){
    return MOD(MOD(a)*MOD(b));
}

bool prime(ll n){
	if( n< 2) return false;
	for(ll i=2;i*i<=n;i++){
		if(n%i == 0){
			return false;
		}
	}
	return true;
}

vector<ll> factors(ll n){
	vector<ll> fa;
	for(ll i=2;i*i<=n;i++){
		while(n%i == 0){
			fa.pb(i);
			n /= i;
		}
	}
	if(n > 1){
		fa.pb(n);
	}
	return fa;
}


vector<ll> Sieve(ll n){
	vector<ll> s;
	bool prime[n+1];
	memset(prime,true,sizeof(prime));
	for(ll p=2;p*p<=n;p++){
		if(prime[p]){
			for(ll i=2*p;i<=n;i+=p){
				prime[i] = false;
			}
		}
	}
	for(ll i=2;i<=n;i++){
		if(!prime[i]){
			s.pb(i);
			cout<<i<<" ";
		}
	}
	return s;
}

ll phi(ll n){
	ll result = n;
	for(ll p=2;p*p<=n;p++){
		if(n%p == 0){
			while(n%p == 0){
				n /= p;
			}
			result -= result/p;
		}
	}
	if(n >1){
		result -= result/n;
	}
	return result;
}

ll modexpo(ll x,ll n,ll mod){
	if(n == 0) return 1;
	else if(n%2 == 0){
		return modexpo((x*x)%mod,n/2,mod);
	}
	else return (x*modexpo((x*x)%mod,(n-1)/2,mod))%mod;
}

ll binary_search(ll arr[],ll l, ll r,ll x){
	if(r >= l){
		ll mid = l + (r-l)/2;
		if(x == arr[mid]){
			return x;
		}
		if(x < arr[mid]){
			return binary_search(arr,l,mid-1,x);
		}
		return binary_search(arr,mid+1,r,x);
	}
	return -1;
}*/

int editDistance(string s, string t)
{
	int n = s.size();
	int r = t.size();
	int dp[n+1][r+1];
	for(int i=0;i<=n;i++){
		dp[i][0] = i;
	}
	for(int i=1;i<=r;i++){
		dp[0][i] = i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=r;j++){
			if(s[i-1] == t[j-1]){
				dp[i][j] = min((dp[i-1][j] +1), min((dp[i][j-1] +1),dp[i-1][j-1]));
			}
			else{
				dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1],dp[i-1][j-1]));
			}
		}
	}
	return dp[n][r];
}

int main(){
  string s;
	string t;
	cin>>s>>t;
	cout<<editDistance(s,t);
	return 0;
}
