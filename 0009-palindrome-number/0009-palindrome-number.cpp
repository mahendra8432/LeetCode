class Solution {
public:
    bool isPalindrome(int x) {
        bool flag=true;
        if(x<0) return false;
        string s=to_string(x);
        for(int i=0;i<s.length();i++){
            if(s[i]!=s[s.length()-i-1]) flag=false;
        }
        if(flag==false) return false;
        else  return true;
        
    }
};