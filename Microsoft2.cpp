class Solution {
public:
    void generateSubsets(int index,int k,int n,vector<vector<int>>& ans,vector<int>& curr){
        if(n==0 && k==0){
            ans.push_back(curr);
            return;
        }
        if(n<0 || k==0 || index==10)return;
        for(int i=index;i<=9;i++){
            curr.push_back(i);
            generateSubsets(i+1,k-1,n-i,ans,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        generateSubsets(1,k,n,ans,curr);
        return ans;
    }
};
