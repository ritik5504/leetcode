class Solution {
public:
    int totalMoney(int n) {
        int weeks=n/7;
        int day=n%7;

       int total = 28 * weeks + (7 * (weeks * (weeks - 1))) / 2;

       int start=weeks+1;

       for(int i=0;i<day;i++){
        total += start+i;
       }
       return total;
        
    }
};