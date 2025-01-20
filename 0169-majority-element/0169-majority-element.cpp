class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // moore's voting algoritham
        int n=nums.size();
        int count=0,ele=0;
        for(auto p:nums){
            if(count==0) ele=p;
            if(p==ele) count++;
            else count--;   
        }
        return ele;
    }
};