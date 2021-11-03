//nをk個以下自然数の和で表す
template<typename T>
vector<vector<T>> partition_function(int n){
    vector<vector<T>> dp(n+1,vector<T>(n+1,0));
    dp[0][0]=1;
    for(int i=0;i<=n;++i)for(int j=1;j<=n;++j){
        if(i-j>=0)dp[i][j]=dp[i][j-1]+dp[i-j][j];
        else dp[i][j]=dp[i][j-1];
    }
    return dp;
}
