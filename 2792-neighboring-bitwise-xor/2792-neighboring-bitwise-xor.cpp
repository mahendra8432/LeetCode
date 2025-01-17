class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int x=0;
        for(auto p:derived) x=x^p;
        if(x==0) return true;
        else return false;
    }
};