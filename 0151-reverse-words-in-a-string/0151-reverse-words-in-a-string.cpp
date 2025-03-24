class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string temp="",ans="";
        for(int i=n-1;i>=0;i--){
            while(i>=0 && s[i]==' ') i--;
            while(i>=0 && s[i]!=' ') {temp+=s[i]; i--;}
            reverse(temp.begin(),temp.end());
            if(temp.length()!=0) ans+= " " + temp;
            temp="";
        }
        return ans.substr(1,ans.length()-1);
    }
};