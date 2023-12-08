
int recSoln(int n,int k,vector<int>& h,vector<int>& dp){
  if (n == 0) {
    return 0;
  }
  if(dp[n]!=-1){
    return dp[n];
  }
  int ans=INT_MAX;
  for(int i=1;i<=k;i++){
      int jump=INT_MAX;
      if(n-i>=0){
        jump=recSoln(n-i, k, h,dp)+abs(h[n]-h[n-i]);
      }
      ans=min(ans,jump);
  }

  dp[n]=ans;
  return dp[n];
}

int bottomUpSoln(int n, int k, vector<int> &h, vector<int> &dp) {
    dp[0]=0;

    for(int i=1;i<=n;i++){
        int ans=INT_MAX;
        for(int j=1;j<=k;j++){
           int jump=INT_MAX;
           if(i-j>=0){
            jump=dp[i-j]+abs(h[i]-h[i-j]);
           }
            ans=min(ans,jump);
        }
        dp[i]=ans;
    }

    return dp[n];
}
int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
    vector<int> dp(n,-1);
   // return recSoln(n-1, k, height,dp);
   return bottomUpSoln(n-1, k,height, dp);
}