class Solution {
public:
   int numberOfSubstrings(string s) {
        int i=0,j=0,n=s.length(), count=0;
        int m[3]={0,0,0};

        while(j<n)
        {
            m[s[j]-'a']++;

            while(m[0] && m[1] && m[2])
                m[s[i++]-'a']--;
            
            count+= i;
            j++;
        }

        return count;
    }
};