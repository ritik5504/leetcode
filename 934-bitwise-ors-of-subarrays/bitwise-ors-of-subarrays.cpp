class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>result;
        unordered_set<int> pre;
        

        for(int n:arr){
            unordered_set<int> curr;
            curr.insert(n);

            for(int i:pre){
                curr.insert(i|n);
            }
            for(int i:curr){
                result.insert(i);
            }
            pre=curr;
        }
        return result.size();
        
        
    }
    
};