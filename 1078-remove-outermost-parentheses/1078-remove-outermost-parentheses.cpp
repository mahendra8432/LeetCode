class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        string ans="";
        int p=0,count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') count--;
            else count++;
            if(count==0) {
                string temp=s.substr(p,i-p+1);
                if(temp.length()>2) ans+=temp.substr(1,temp.length()-2);
                p=i+1;
            }
        }
        return ans;
        
    }
};