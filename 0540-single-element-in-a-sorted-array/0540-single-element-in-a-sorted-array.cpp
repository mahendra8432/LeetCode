class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1,mid;
        while(high>low){
            mid=low+(high-low)/2;
            if(mid%2==1) mid--;
            if(nums[mid]!=nums[mid+1]) high=mid;
            else low=mid+2;
        }
        // ab low and high single elment ko target kar rahe hai;
        return nums[low];
    }
};

/*ince every element in the sorted array appears exactly twice except for the single element, we know that if we take any element at an even index (0-indexed), the next element should be the same. Similarly, if we take any element at an odd index, the previous element should be the same. Therefore, we can use binary search to compare the middle element with its adjacent elements to determine which side of the array the single element is on.

If the middle element is at an even index, then the single element must be on the right side of the array, since all the elements on the left side should come in pairs. Similarly, if the middle element is at an odd index, then the single element must be on the left side of the array.

We can continue this process by dividing the search range in half each time, until we find the single element.*/


