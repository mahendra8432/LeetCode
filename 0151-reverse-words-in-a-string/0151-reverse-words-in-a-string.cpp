class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string ans="",temp="";
        for(int i=n-1;i>=0;i--){
            while(i>=0 && s[i]!=' '){
                 temp+=s[i];
                 i--;
            }
            if(temp.length()>=1){
                if(ans.length()!=0) ans+=" ";
                reverse(temp.begin(),temp.end());
                ans+=temp;
                }
            temp="";
        }
        return ans;
    }
};