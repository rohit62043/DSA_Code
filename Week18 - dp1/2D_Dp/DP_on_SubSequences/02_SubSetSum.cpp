 bool recSol(vector<int> arr,int sum,int index){
        if(sum==0){
            return true;
        }
         if(index==0){
            return arr[0]==sum;
        }
        
        //include
        
        bool include=false;
        if(sum-arr[index]>=0){
          include=recSol(arr,sum-arr[index],index-1);
        }
        bool exclude=recSol(arr,sum,index-1);
        
        return include || exclude;
    }
    bool topDownSol(vector<int> arr,int sum,int index,vector<vector<int>>& dp){
        if(sum==0){
            return true;
        }
         if(index==0){
            return arr[0]==sum;
        }
        
        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }
        //include
        
       bool include=false;
        if(sum-arr[index]>=0){
          include=topDownSol(arr,sum-arr[index],index-1,dp);
        }
        bool exclude=topDownSol(arr,sum,index-1,dp);
        
        dp[index][sum]=(include || exclude);
        
        return dp[index][sum];
    }
   bool bottomUpSol(vector<int> arr,int sum){
       int n=arr.size();
       vector<vector<int>> dp(n,vector<int>(sum+1,0));
       for(int i=0;i<n;i++){
           dp[i][0]=1;
       }
       if(arr[0]<=sum)
       dp[0][arr[0]]=1;
       
       for(int index=1;index<n;index++){
           for(int s=1;s<=sum;s++){
                bool include=0;
        if(s-arr[index]>=0){
          include=dp[index-1][s-arr[index]];
        }
        bool exclude=dp[index-1][s];
        
        dp[index][s]=(include || exclude);
           }
       }
       
       return dp[n-1][sum];
   }
   
   bool spaceOptm(vector<int> arr,int sum){
       int n=arr.size();
      vector<int> prev(sum+1,0);
      vector<int> curr(sum+1,0);
       prev[0]=curr[0]=1;
       if(arr[0]<=sum)
       prev[arr[0]]=1;
       
       for(int index=1;index<n;index++){
           for(int s=1;s<=sum;s++){
                bool include=0;
        if(s-arr[index]>=0){
          include=prev[s-arr[index]];
        }
        bool exclude=prev[s];
        
        curr[s]=(include || exclude);
           }
           prev=curr;
       }
       
       return prev[sum];
   }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
            int n=arr.size();
      // return recSol(arr,sum,n-1);
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
       // return topDownSol(arr,sum,n-1,dp);
      //return bottomUpSol(arr,sum);
      return spaceOptm(arr,sum);
    }