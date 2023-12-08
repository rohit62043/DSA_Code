// Using House Robber 01
class Solution {
  int spaceOptSol(vector<int>& nums,int n){
    int prev2=0;
    int prev1=nums[n];
    int curr=0;

    for(int i=nums.size()-2;i>=0;i--){
       
    int include = prev2 + nums[i];
    int exclude = prev1 + 0;

    curr =  max(include, exclude); 
    prev2=prev1;
    prev1=curr;
   }
  return prev1;
}
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp1;
        vector<int> temp2;
        if(n==1){
            return nums[0];
        }
        for(int i=0;i<n;i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=n-1){
                temp2.push_back(nums[i]);
            }
        }
        return max(spaceOptSol(temp1,temp1.size()-1),spaceOptSol(temp2,temp2.size()-1));
    }
};