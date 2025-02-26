class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int min=INT_MAX,minidx;
        for(int i=0;i<n;i++){
           if(strs[i].length()<min){
            min=strs[i].length();
            minidx=i;
           } 
        }
        string p=strs[minidx];
        for(int i=0;i<n;i++){
            while(strs[i].find(p)==string::npos){
                p.pop_back();
            }
        }
        return p;
    }
};