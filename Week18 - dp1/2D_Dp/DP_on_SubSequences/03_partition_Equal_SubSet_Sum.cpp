class Solution {
    bool solveRecursion(vector<int>& nums,int index,int target){
        //base case
        int n=nums.size();
        if(index>=nums.size()){
            return 0;
        }
        if(target<0){
            return 0;

        }
        if(target==0){
            return 1;
        }

        bool include=solveRecursion(nums,index+1,target-nums[index]);
        bool exclude=solveRecursion(nums,index+1,target);

        return include || exclude;
    }
    bool solveMemo(vector<int>& nums,int index,int target,vector<vector<int>>& dp){
        //base case
        int n=nums.size();
        if(index>=nums.size()){
            return 0;
        }
        if(target<0){
            return 0;

        }
        if(target==0){
            return 1;
        }

        if(dp[index][target]!=-1){
            return dp[index][target];
        }

        bool include=solveMemo(nums,index+1,target-nums[index],dp);
        bool exclude=solveMemo(nums,index+1,target,dp);

        dp[index][target] = include || exclude;
        return dp[index][target];
    }
    bool solveTabular(vector<int>& nums,int target){
         int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));

        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }

        for(int index=n-1;index>=0;index--){
            for(int t=1;t<=target;t++){
                bool include=0;
                if(t-nums[index]>=0){
                    include=dp[index+1][t-nums[index]]; 
                }
                bool exclude=dp[index+1][t];

                dp[index][t] = include || exclude;
            }
        }

        return dp[0][target];
    }
    bool solveSO1(vector<int>& nums,int target){
         int n=nums.size();
       vector<int> next(target+1,0);
       vector<int> curr(target+1,0);

        next[0]=1;
        curr[0]=1;

        for(int index=n-1;index>=0;index--){
            for(int t=1;t<=target;t++){
                bool include=0;
                if(t-nums[index]>=0){
                    include= next[t-nums[index]]; 
                }
                bool exclude= next[t];

                curr[t] = include || exclude;

                // aage badhane wala code yaha likh dunga galti se
            }
            //yaha jalti karunga
              next=curr;
        }

        return next[target];
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        if(sum&1){
            return false;
        }

        int target=sum/2;

        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        //return solveRecursion(nums,0,target);
        //return solveMemo(nums,0,target,dp);
        //return solveTabular(nums,target);
        return solveSO1(nums,target);
        
    }
};