class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(auto ch:s){
            if(st.size()==0) st.push(ch);
            else{
                int n=(int)ch-(int)st.top();
                if(n==1 || n==2) st.pop();
                else st.push(ch);
            }
        }
        if(st.size()==0) return true;
        else return false;
    }
};