class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>map;
        int count=0;
        for(auto st:s){
            map[st]++;
        }
        for(auto x:map){
            int f=x.second;
            if(f%2==0) count+=2;
            else count++;
        }
        return count;
    }
};