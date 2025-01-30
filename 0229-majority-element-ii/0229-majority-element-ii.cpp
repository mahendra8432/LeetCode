class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 1, maxcount = 1, secondmax = 1, index, index2;
        if(n==1) return nums;
        else if(n==2 && nums[0]!=nums[1]) return nums;
        else if(n==2) return {nums[0]};
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1])  count++;
            else{
                if (count > maxcount) {
                    secondmax = maxcount;
                    maxcount = count;
                    index = i-1;
                } else if (count > secondmax) {
                    secondmax = count;
                    index2 = i-1;
                }
                 count=1;
            } 
            
        }
       int  i=n;
              if (count > maxcount) {
                    secondmax = maxcount;
                    index2=index;
                    maxcount = count;
                    index = i-1;
                } else if (count > secondmax) {
                    secondmax = count;
                    index2 = i-1;
                }
                 count=1;
        if (maxcount > n / 3 && secondmax > n / 3)  return {nums[index], nums[index2]};
        else if (maxcount > n / 3) return {nums[index]};
        else return {};
    }
};