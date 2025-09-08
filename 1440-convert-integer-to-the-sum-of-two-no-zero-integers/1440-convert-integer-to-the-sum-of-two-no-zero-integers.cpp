class Solution {
public:
    bool haveZero(int num){
        while(num>0){
            if(num%10==0) return true;
            num/=10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            if(haveZero(i)==false){
                if(haveZero(n-i)==false) return {i,n-i};
            }
        }
        return {0,0};
    }
};