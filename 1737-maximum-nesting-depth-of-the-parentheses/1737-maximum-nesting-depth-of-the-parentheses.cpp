class Solution {
public:
    int maxDepth(string s) {
        int count=0,max=INT_MIN;
        for(char p:s){
            if(p=='(') count++;
            else if(p==')') count--;
            if(count>max) max=count;
        }
        return max;
    }
};