class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int r=startPos[0],c=startPos[1];
        int hr=homePos[0],hc=homePos[1];
        int cost=0;

        while(r != hr){
            if(r<hr) r++;
            else r--;
            cost +=rowCosts[r];
        }
        while(c != hc){
            if(c < hc) c++;
            else c--;
            cost += colCosts[c];
        }
        return cost;
        
    }
};