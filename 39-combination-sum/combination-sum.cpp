class Solution {
private:
    void dfs(vector<int>& candidates,int target, vector<int>output,int index,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(output);
            return;
        }
        if(target<0||index==candidates.size()){
            return;
        }
         dfs(candidates,target,output,index+1,ans);

        output.push_back(candidates[index]);
        dfs(candidates,target-candidates[index],output,index,ans);
        output.pop_back();

        
        

        

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>>ans;
        vector<int>output;
        int index=0;
        dfs(candidates,target,output,index,ans);
        return ans;
    }
};