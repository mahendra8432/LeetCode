class Solution {
public:
                bool isSubString( const std::string& s1, const std::string& s2) {
            // Base case: if s1 is empty, it is a substring of s2
            if (s1.empty()) {
                return true;
            }
            // Base case: if s2 is empty or shorter than s1, s1 cannot be a substring of s2
            if (s2.empty() || s2.size() < s1.size()) {
                return false;
            }
            // Check if the current start of s2 matches s1
            if (s2.substr(0, s1.size()) == s1) {
                return true;
            }
            // Continue checking the rest of s2
            return isSubString(s1, s2.substr(1));
        }


        vector<string> stringMatching(vector<string>& words) {
            vector<string>v;
            int p=words.size();
            sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.length() < b.length();
            });
            

         for(int i=0;i<p;i++){
             
              for(int j=p-1;j>i;j--){
                   
                    if(isSubString(words[i],words[j])){
                         v.push_back(words[i]);
                         break;
                         }
              }
         }
         return v;
    }
};