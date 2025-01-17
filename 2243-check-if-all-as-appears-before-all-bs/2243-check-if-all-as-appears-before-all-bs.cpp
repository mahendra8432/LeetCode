class Solution {
public:
    bool checkString(string s) {
        int n=s.length();
        if(n==1) return true;
        int count=0;
        for(int i=0;i<n-1;i++) {
            if(s[i+1]!=s[i])count++;
            if(count>=2) return false;
        }
        if(count==1 && s[0]=='b') return false;
        else return true;
    }
};