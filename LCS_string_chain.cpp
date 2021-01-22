class Solution {
public:
    
    
    static bool comp(string &a, string &b)
    {
        return a.size() < b.size();
    }
    
    // bool pred(string a, string b)
    // {   
    //     if((b.size() - a.size()) != 1) return false;
    //     int idx = -1;
    //     for(int i=0;i<a.size();i++)
    //     {
    //         if(a[i] != b[i])
    //         {
    //             idx = i;
    //             break;
    //         }
    //     }
    //     if(idx == -1) return true;
    //     else
    //     {
    //         if(a.substr(idx) == b.substr(idx+1)) return true;
    //         else return false;
    //     }
    // }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),comp);
        //int length[n];
        int ans = 0;
        unordered_map<string,int> dp;
        for(auto w : words)
        {
            for(int i=0;i<w.size();i++)
            {
                dp[w] = max(dp[w], dp[w.substr(0,i) + w.substr(i+1)] + 1);
            }
            ans = max(ans, dp[w]);
        }
        return ans;
    }
};
