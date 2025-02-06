class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        unordered_map<int,int>map;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                map[nums[i]*nums[j]]++;
            }
        }
        for(auto m:map){
            int p=m.second;
            count=count + ((p*(p-1))/2)*8;
        }
        return count;
    }
};