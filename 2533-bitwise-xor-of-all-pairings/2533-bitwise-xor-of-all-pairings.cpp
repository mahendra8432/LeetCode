class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()%2==0 && nums2.size()%2==0) return 0;
        else if(nums1.size()%2!=0 && nums2.size()%2==0){
            int q=0;
             for(int i=0;i<nums2.size();i++){
                q=q^nums2[i];
             }
             return q;
        }
        else if(nums1.size()%2==0 && nums2.size()%2!=0){
                int p=0;
             for(int i=0;i<nums1.size();i++){
                p=p^nums1[i];
             }
             return p;
        }
        else{   // (nums1.size()%2!=0 && nums2.size()%2!=0)
              int l=0,m=0;
             for(int i=0;i<nums1.size();i++){
                l=l^nums1[i];
             }
             for(int i=0;i<nums2.size();i++){
                m=m^nums2[i];
             }
             return l^m;

        }
        return 0;
    }
};