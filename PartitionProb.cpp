#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,b,a) for(ll i=b;i>=a;i--)
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
const ll N = 1e5 +1;
#define f first
#define s second
#define pii pair< ll, ll >
#define so(v) sort(v.begin(), v.end())
//#define tc int t; cin >> t; while(t--)
using namespace std;
#define deb1a(v)                  \
    cout << #v << "--->" << endl; \
    for (auto it : v)             \
        cout << it << " ";        \
    cout << endl;
#define deb2a(v)                  \
    cout << #v << "--->" << endl; \
    for (auto it : v)             \
    {                             \
        for (auto it1 : it)       \
        {                         \
            cout << it1 << " ";   \
        }                         \
        cout << endl;             \
    }
#define deb3a(v)                               \
    cout << #v << "-->" << endl;               \
    for (auto it : v)                          \
    {                                          \
        cout << it.fi << " " << it.se << endl; \
    }

void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void IO(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
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

//////////////////////////////////////////////////////////

int fun(int n,int arr[]){
	int sum = 0;
	rep(i,0,n){
		sum += arr[i];
	}
	if(sum%2 != 0) return 0;
	int table[sum/2 + 1][n+1];
	rep(i,0,n+1){
		table[0][i] = 1;
	}
	rep(i,1,sum/2 + 1){
		table[i][0] = 0;
	}
	rep(i,1,sum/2 + 1){
		rep(j,1,n+1){
			table[i][j] = table[i][j-1];
			if(i >= arr[j-1]){
				table[i][j] = table[i][j] || table[i - arr[j-1]][j-1];
			}
		}
	}
	return table[sum/2][n];
}

int fun1(int n,int arr[]){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    if(sum%2 != 0) return 0;
    int dp[2][sum/2+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum/2;j++){
            if(j==0){
                dp[i%2][j] = 1;
            }
            else if(i==0){
                dp[i%2][j] = 0;
            }
            else if(j >= arr[i-1]){
                dp[i%2][j] = dp[(i+1)%2][j - arr[i-1]] || dp[(i+1)%2][j];
            }
            else dp[i%2][j] = dp[(i+1)%2][j];
        }
    }
    return dp[n%2][sum/2];
}

int main(){
	//IO();
	int n;
	cin>>n;
	int arr[n];
	rep(i,0,n) cin>>arr[i];
	cout<<fun(n,arr);
	return 0;
}
