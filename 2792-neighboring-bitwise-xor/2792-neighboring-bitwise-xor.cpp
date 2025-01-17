class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int q=0;
        for(auto p:derived) q=q^p;
        if(q==0) return true;
        else return false;
    }
};