class Solution {
public:
    string clearDigits(string s) {
        int n=s.length(),count=0;
        for(int i=n-1;i>=0;i--){
            if(toascii(s[i])<97) {
                 count++;
                 s.erase(i, 1);
            }
            else if(count>0){
                    s.erase(i, 1);
                    count--;   
                }
        }
        return s;
    }
};