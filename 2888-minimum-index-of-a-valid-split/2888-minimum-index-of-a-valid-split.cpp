class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int>mp;
        for (int i=0;i<nums.size();i++){mp[nums[i]]++;}
        int freq=-1,freqele=-1;
        for (auto &it:mp){
            if (freq<it.second){
                freq=it.second;
                freqele=it.first;
            }
        }
        int x=0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]==freqele){x++;}
            if (x*2>(i+1) && (freq-x)*2>(nums.size()-(i+1))){return i;}
        }
        return -1;
    }
};