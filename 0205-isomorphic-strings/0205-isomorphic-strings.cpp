class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.length();
        if(n!=t.length()) return false;
        map<char,char>map;
        for(int i=0;i<n;i++){
            auto p=map.find(s[i]);
            if(p==map.end()){
               auto q=t.substr(0,i+1-1).find(t[i]);
               if(q!=string::npos) if(s[q]!=s[i]) return false;
                 map[s[i]]=t[i];
                 }
            else{//map me s[i] milta hai to
                    if(p->second!=t[i]) return false;
            }
        }
        return true;
    }
};