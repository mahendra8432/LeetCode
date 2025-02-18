class Solution {
public:
    string smallestNumber(string pattern) {
        
        stack<int>st;
        string ans;
        int num=1;
        for(int i=0;i<pattern.length();i++){
            
            if(pattern[i]=='D'){
                st.push(num);
                num++;
            }
            else{
                st.push(num);
                num++;
                while(!st.empty()){
                    char ch=st.top()+'0';
                    ans+=ch;
                    st.pop();
                }
            } 
        }
        st.push(num);
        while(!st.empty()){
            char ch=st.top()+'0';
            ans+=ch;
            st.pop();
        }
        return ans;
    }
};