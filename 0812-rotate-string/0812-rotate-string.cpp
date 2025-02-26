class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        if(n!=goal.length()) return false;
        for(int i=0;i<n;i++){
            if(goal.find(s.substr(i,n-i+1))!=string::npos){
                string p=s.substr(i,n-i+1);
                 p+=s.substr(0,i-1+1);
                 if(p==goal) return true;
                 else return false;
            }
        }

        return false;
    }
};