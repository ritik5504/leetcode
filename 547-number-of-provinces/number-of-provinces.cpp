class Solution {
public:
    void dfs(int i,vector<vector<int>>& isConnected,vector<bool>&visit,int n){
        visit[i]=true;

        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1 && !visit[j]){
                dfs(j,isConnected,visit,n);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>visit(n,false);
        int result=0;

        for(int i=0;i<n;i++){
            if(!visit[i]){
                result++;
                dfs(i,isConnected,visit,n);
            }
        }
        return result;
        
    }
};