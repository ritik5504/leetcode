class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int minhour=0;
        int penalty=count(begin(customers),end(customers),'Y');
        int minpenalty=penalty;

        for(int i=0;i<n;i++){
            if(customers[i]=='Y'){
                penalty--;
            }else{
                penalty++;
            }
            if(minpenalty>penalty){
                minpenalty=penalty;
                minhour=i+1;
            }
        }
        return minhour;
        
    }
};