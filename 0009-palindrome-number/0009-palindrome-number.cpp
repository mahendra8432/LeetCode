class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        // string s=to_string(x);
        // for(int i=0;i<s.length();i++){
        //     if(s[i]!=s[s.length()-i-1]) return false;
        // }
        // return true;
        long long  r,n=(long long)x,sum=0;
        while(n!=0){
            r=n%10;
            n=n/10;
            sum=sum*10+r;
        }
        if(sum==(long long)x) return true;
        else return false;
    }
};