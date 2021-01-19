class Solution {
public:
    
    int dp[1001][1001];
    
    int fun(string &s, int l, int r)
    {
        if(l==r) return 1;
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        dp[l][r] = (s[l] == s[r]) ? 2 + fun(s, l+1, r-1) : max(fun(s, l+1, r), fun(s, l, r-1));
        return dp[l][r];
    }
    
    int fun1(string &s)
    {
        int n = s.size();
        int v[1001][1001];
        memset(v,0,sizeof(v));
        for(int i=0;i<n;i++) v[1][i] = 1;
        for(int i=2;i<n+1;i++)
        {
            for(int j=0;j<n-i+1;j++)
            {
                v[i][j] = s[j]==s[i+j-1]?2+v[i-2][j+1]:max(v[i-1][j],v[i-1][j+1]);
            }
        }
        return v[n][0];
        //return v[n-1][0];
    }
        
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        memset(dp, -1 ,sizeof(dp));
        //return fun(s,0, n-1);
        return fun1(s);
    }
};
