class Solution {
public:
//     //const int N = 1e5;
//     int dp[50004];
    
//     int fun(vector<int> prices, int i, int fee, bool flag){
//         if(i < 0) return 0;
//         if(dp[i] != INT_MIN) return dp[i];
//         if(!flag){
//             dp[i] = max(fun(prices,i-1, fee, true) - prices[i], fun(prices, i-1, fee, false, P));
        
//         }
//         if(flag){
//             dp[i][P] = max(prices[i] - fee + fun(prices, i-1, fee, false, P + prices[i] - fee), fun(prices, i-1, fee, true, P));
//         }
//         return dp[i][P];
//     }
    int dp[50004];
    
    int fun(vector<int> prices, int i, int fee, bool flag){
        if(i < 0) return 0;
        //if(dp[i] != INT_MIN) return dp[i];
        int x = 0,y=0;
        if(!flag){
            x = max(fun(prices, i-1, fee, true) - prices[i] - fee, fun(prices, i-1, fee, false) );
        }
        if(flag){
            y = max(prices[i] + fun(prices, i-1, fee, false), fun(prices, i-1, fee, true));
        }
        return max(x,y);
        //return dp[i];
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int d[n];
        memset(d, 0 , sizeof(d));
        int profit = d[0] - prices[0] - fee;
        for(int i=1;i<n;i++){
            d[i] = max(d[i-1], profit + prices[i]);
            profit = max(profit, d[i-1] - prices[i] - fee);
        }
        return d[n-1];
        // memset(dp, INT_MIN, sizeof(dp));
        // reverse(prices.begin(),prices.end());
        // int ans = fun(prices, n-1, fee, false);
        // return ans;
    }
};
