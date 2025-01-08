class Solution {
public:
    int maxScore(string s) {
        int n=s.length(),count0=0,count1=0;
        vector<int>v(n,0);
        for(int i=0;i<n-1;i++){
            if(s[i]=='0'){
                count0++;
                v[i]+=count0;
            }
            else v[i]=count0;
          
        }
        for(int i=n-1;i>0;i--){
            if(s[i]=='1'){
                count1++;
                v[i-1]+=count1;
            }
            else v[i-1]+=count1;
        }
        auto p = minmax_element(v.begin(), v.end());
        return *p.second;
    }
};