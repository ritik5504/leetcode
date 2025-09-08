class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> result;
        int st, end;

        if(n % 2 == 0){
            st = n/2, end = n/2;
        } else {
            st = n/2, end = n/2+1;
        }

        while(st > 0 && end < n){
                
                bool flag1 = true, flag2 = true;
                int temp = st;
                while(temp > 0){
                    int rem = temp%10;
                    temp /= 10;
                    if(rem == 0){
                        flag1 = false;
                        break;
                    }
                }

                temp = end;
                while(temp > 0){
                    int rem = temp%10;
                    if(rem == 0){
                        flag2 = false;
                        break;
                    }
                    temp /= 10;
                }

                if(flag1 && flag2){
                    result.push_back(st);
                    result.push_back(end);
                    break;
                }
                st--, end++;
            }
        return result;
    }
};