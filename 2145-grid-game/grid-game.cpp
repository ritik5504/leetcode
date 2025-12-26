class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstrow=accumulate(begin(grid[0]),end(grid[0]),0LL);
        long long secondrow=0;

        long long robo2=LONG_LONG_MAX;
        for(int robo1=0;robo1<grid[0].size();robo1++){
            firstrow -= grid[0][robo1];

            long long bestrobo2=max(firstrow,secondrow);

            robo2=min(robo2,bestrobo2);
            secondrow += grid[1][robo1];
        }
        return robo2;
        
    }
};