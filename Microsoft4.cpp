class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int curr=0,maxi,n=nums.size(),sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            curr+=i*nums[i];
        }
        for(int i=n-1;i>=0;i--){
            curr=curr+(sum-nums[i])-(n-1)*nums[i];
            maxi=max(maxi,curr);
        }
        return maxi;
    }
};

