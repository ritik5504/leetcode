class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.length();
        char ch=' ';
        for(int i=0;i<=n-3;i++){
            if(num[i]==num[i+1] && num[i+1]==num[i+2]){
                if(num[i]>ch){
                    ch=num[i];
                }
            }
        }
        if(ch==' '){
            return "";
        }
        return string(3,ch);

    }
};