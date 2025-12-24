class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n= apple.size();
        int m=capacity.size();

        int count=0;
        int ans=0;

        sort(capacity.begin(),capacity.end());

        for(int x:apple){
            ans+=x;
        }

        for(int i=m-1;i>=0;i--){
            ans-=capacity[i];
            count++;

            if(ans<=0) break;
        }
        return count;
        
    }
};