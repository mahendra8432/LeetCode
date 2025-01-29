#include <bits/stdc++.h>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),p,q;
        bool flag=true;
        for(int i=n-1;i>0 && flag;i--){
            if(nums[i]>nums[i-1]){
                p=i-1;
                int firstmax=INT_MAX;
                sort(nums.begin()+p+1,nums.end());
                while(i<n ) {
                    if(nums[i]>nums[p]){
                        swap(nums[i],nums[p]);
                        flag=false;
                        break;
                    }
                    
                    //if(nums[p]>nums[i]) break;
                    i++;
                }
               
              
                //v.begin() + l, v.begin() + r + 1
            }
        }
        if(flag==true) reverse(nums.begin(),nums.end());
    }
};