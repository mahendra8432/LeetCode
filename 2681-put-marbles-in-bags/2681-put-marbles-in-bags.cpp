class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        
        int n=w.size();
        
        long long mx=w[0]+w[n-1]; 
        long long mn=w[0]+w[n-1]; 
        
        vector<int> consum; 
        for(int i=1;i<n;i++)
        {
            consum.push_back(w[i]+w[i-1]);
        }
        
        sort(consum.begin(),consum.end());
        int l=consum.size();
        
        for(int i=0;i<k-1;i++)
        {
             mx+=consum[l-1-i]; 
             mn+=consum[i]; 
        }
        
        return (mx-mn);
        
    }
};