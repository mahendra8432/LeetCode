class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        int count=0,p,q;
        if(s1.length()!=s2.length()) return false;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                count++;
                if(count==1) p=i;
                else if(count==2) q=i;
                else return false;
            }
        }
        if(count==2) if(s1[p]==s2[q] && s1[q]==s2[p]) return true;
        return false;
    }
};