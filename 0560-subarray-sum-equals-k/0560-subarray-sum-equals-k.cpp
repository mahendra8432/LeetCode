class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        vector<int>v(n+1,0);
        for(int i=0;i<n;i++){
            v[i+1]=v[i]+nums[i];
        }
        for(int i=0;i<=n;i++){
            for(int j=n;j>i;j--){
                if((v[j]-v[i])==k) count++;
            }
        }
        return count;
    }
};