class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>v1;
          vector<int>v2;
        for(int i=0;i<boxes.length();i++){
            if(boxes[i]=='1') v1.push_back(i);
        }
        int sizeofones=v1.size(),p=0;
        for(int i=0;i<boxes.length();i++){
                 p=0;
                for(int j=0;j< sizeofones;j++){
                    p +=abs(v1[j]-i);
                }
                v2.push_back(p);
        } 
        return v2;
    }
};