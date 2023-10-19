// USER: PRANAV JAIN
// DATE: Thursday 19, Oct 2023
// TASK: 132, Palindrome Partitioning II (hard)

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp = vector<vector<int>> (n, vector<int>(n, 0));

        for(int i = n-1; i>=0; i--){
            for(int j = i; j < n; j++){
                if(i == j){
                    dp[i][j] = 1;
                }
                else if(s[i] == s[j] && i == j-1){
                    dp[i][j] = 1;
                }
                else if(s[i] == s[j] && j-i >= 2){
                    dp[i][j] = dp[i+1][j-1];
                }
            }
        }

        vector<int> memo = vector<int>(n+1, n);
        memo[n] = 0;
        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                if(dp[i][j]){
                    memo[i] = min(memo[j+1]+1, memo[i]);
                }
            }
        }
        return memo[0]-1;
        
    }
};
