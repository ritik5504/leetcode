class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n=dimensions.size();
        int area=0,dio=0;
        for(int i=0;i<n;i++){
            int l=dimensions[i][0];
            int w=dimensions[i][1];
            int curr=l*l+w*w;

            if(curr>dio || (curr == dio && l*w> area)){
                dio=curr;
                area=l*w;
            }
        }
        return area;
    }
};