class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size(),count=0;
        vector<int>v1,v2;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot) v1.push_back(nums[i]);
            else if(nums[i]==pivot) count++;
            else v2.push_back(nums[i]);
        }
        v1.insert(v1.begin() + v1.size(), count, pivot);
        v1.insert(v1.end(), v2.begin(), v2.end());
        return v1;
    }
};