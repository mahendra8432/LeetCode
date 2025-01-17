class Solution {
public:
    bool check(vector<int>& nums) {
        // int n=nums.size(),minidx=0,min=INT_MAX;
        // vector<int>v;
        // for(int i=0;i<n;i++){
        //     if(nums[i]<min){
        //         min=nums[i];
        //         minidx=i;
        //     }
        // }
        // for(int i=minidx;i<n;i++) v.push_back(nums[i]);
        // for(int i=0;i<minidx;i++) v.push_back(nums[i]);
        // for(int i=0;i<n-1;i++) if(v[i]>v[i+1]) return false;
        // return true;
        int count=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]<nums[i]) count++;
        }
        if(count>=2) return false;
        else if(count==0) return true;
        else if(nums[0]<nums[nums.size()-1]) return false;
        return true;

    }
};