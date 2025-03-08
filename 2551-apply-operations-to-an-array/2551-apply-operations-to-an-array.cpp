class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size(),i=0;
        vector<int>ans;
        for( i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]=2*nums[i];
                nums[i+1]=0;
                if(nums[i]!=0) ans.push_back(nums[i]);
                i++;
            }
            if(nums[i]!=0)ans.push_back(nums[i]);
        }
        if(i!=n) if(nums[i]!=0)ans.push_back(nums[i]);
        // arr.insert(arr.end(), n, x);
        ans.insert(ans.end(), n-ans.size(), 0);
        return ans;

    }
};