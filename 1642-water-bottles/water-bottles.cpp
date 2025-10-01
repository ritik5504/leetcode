class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int ans=numBottles;
        int emp=numBottles;

        while(emp >= numExchange){
            int newbot=emp / numExchange;
            ans += newbot;
            emp=emp%numExchange+newbot;
        }
        return ans;
    }
};