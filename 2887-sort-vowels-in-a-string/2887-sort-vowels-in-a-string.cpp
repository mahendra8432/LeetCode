class Solution {
public:
    string sortVowels(string s) {
        int n=s.length();
        string vowelset="aeiouAEIOU";
        string vowels="";
        for(char c:s){
            if(vowelset.find(c)!=string::npos) vowels+=c;
        }
        sort(vowels.begin(),vowels.end());
        int j=0;
        for(int i=0;i<n;i++){
            if(vowelset.find(s[i])!=string::npos) {
                s[i]=vowels[j];
                j++;
            }
        }
        return s;
    }
};