class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector<int>v;
        int i=n-k;
        while(i<n){
             v.push_back(nums[i]);
             i++;
        }
        i=0;
        while(i<n-k){
            v.push_back(nums[i]);
            i++;
        }

    for(int j=0;j<n;j++) nums[j]=v[j];

    }
};