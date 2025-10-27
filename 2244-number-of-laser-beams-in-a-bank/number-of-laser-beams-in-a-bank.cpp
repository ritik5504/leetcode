class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev=0;
        int total=0;


        for(string row: bank){
            int curr=0;

            for(char c:row){
                if(c=='1') curr++;
            }
            if(curr>0){
                total += prev*curr;
                prev=curr;
            }
        }
        return total;
    }
};