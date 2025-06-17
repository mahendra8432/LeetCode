class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.length();
        if(t.length()!=n) return false;
        unordered_map<char,int>map1,map2;
        for(int i=0;i<n;i++){
            map1[s[i]]++;
            map2[t[i]]++;
        }
        for(auto p:map1){
            int t=0;
            if(map2.find(p.first)!=map2.end()) t=map2[p.first];
            else return false;
            if(p.second!=t) return false;
        }
        return true;
    }
};