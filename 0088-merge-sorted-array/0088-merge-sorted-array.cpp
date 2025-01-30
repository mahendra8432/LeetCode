class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        while(j<n && i<nums1.size()-n){
            if(nums2[j]<nums1[i]) { 
                nums1.insert(nums1.begin() + i, nums2[j]);
                j++;
                }
            else i++;
        }
         int p=n;
        while(n--) nums1.pop_back();
        if(j!=p){       
             while(j<p){
            nums1.push_back(nums2[j]);j++;
             }
        }
    }
};