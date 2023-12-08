#include <bits/stdc++.h> 

int recSoln(int n,vector<int> & h,vector<int>& dp){
    if(n==0) return 0;

    if(dp[n]!=-1){
        return dp[n];
    }
    int first = recSoln(n-1,h,dp)+abs(h[n]-h[n-1]);
    int second = INT_MAX;
    if(n-2>=0)
    second=recSoln(n-2,h,dp)+abs(h[n]-h[n-2]);

    dp[n]=min(first,second);

    return dp[n];
}

int bottomUpSoln(int n,vector<int>&h,vector<int>&dp){
    dp[0]=0;

    for(int i=1;i<=n;i++){
        int first = dp[i-1]+abs(h[i]-h[i-1]);
        int second=INT_MAX;
        if(i-2>=0){
            second=dp[i-2]+abs(h[i]-h[i-2]);
        }
    
        dp[i]=min(first,second);
    }

    return dp[n];
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n,-1);
    //return recSoln(n-1,heights,dp);

    return bottomUpSoln(n-1, heights,dp);
}