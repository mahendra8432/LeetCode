class Solution {
public:
    vector<int> minOperations(string boxes) {
         vector<int>v1;
          //boxes ke andar jo jo 1 hai unke index v1 me bharo.
        for(int i=0;i<boxes.length();i++){
            if(boxes[i]=='1') v1.push_back(i);
        }
        //ab har ek index i(0 to n) ko sare v1[i] se subtract karke(absolut) add karo 
        //phir vo result v2[i] me store karo.
        int sizeofones=v1.size(),p=0;
        for(int i=0;i<boxes.length();i++){
                 p=0;
                for(int j=0;j< sizeofones;j++){
                    p +=abs(v1[j]-i);
                }
                v1.push_back(p);
        } 
        // Remove the first N elements, and shift everything else down by N indices
        v1.erase(v1.begin(), v1.begin() + sizeofones);
        return v1;
    }
};