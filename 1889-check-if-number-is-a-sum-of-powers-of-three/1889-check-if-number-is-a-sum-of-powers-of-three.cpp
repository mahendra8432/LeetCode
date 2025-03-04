class Solution {
public:
    bool checkPowersOfThree(int n) {
        int N= n;
        while(N!=0){
            if(N%3==2)return false;
            N/=3;
        }
        return true;
    }
};