class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        vector<vector<int>>ans;
        int i=0,j=0;
        while(i!=n && j!=m){
            if(nums1[i][0]<=nums2[j][0]){
                if(ans.size()>=1 && ans[ans.size()-1][0]==nums1[i][0]) ans[ans.size()-1][1]+=nums1[i][1];
                else ans.push_back(nums1[i]);
                i++;
            }
            else {
                if(  ans.size()>=1 && ans[ans.size()-1][0]==nums2[j][0]) ans[ans.size()-1][1]+=nums2[j][1];
                else ans.push_back(nums2[j]);
                j++;
            }
        }
        if(i==n){
            if(nums2[j][0]==ans[ans.size()-1][0]) {
                ans[ans.size()-1][1]+=nums2[j][1];
                j++;
            }
            ans.insert(ans.end(), nums2.begin()+j, nums2.end());
        }
        else if(j==m){
                if(nums1[i][0]==ans[ans.size()-1][0]) {
                ans[ans.size()-1][1]+=nums1[i][1];
                i++;
               }
            ans.insert(ans.end(), nums1.begin()+i, nums1.end());
        }
        return ans;
      
    }
};