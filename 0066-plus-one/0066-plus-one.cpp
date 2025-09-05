class Solution {
public:
// Method 1:-
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int i=n-1;
        while(i>=0 && digits[i]==9){
            digits[i]=0;
            i--;
        }
        if(i!=-1) digits[i]++;
        else{ 
            digits.assign(digits.size(),0);
            digits.insert(digits.begin(),1);
            }
        return digits;
    }
};