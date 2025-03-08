class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]) {
                nums[i]=2*nums[i];
                nums[i+1]=0;
                i++;
            }
        }
        int i=0,j=0;
        bool flag=true;
        for(int j=0;j<n;j++){
            if(flag && nums[j]==0){ 
                i=j; flag=false;
            }
            else if(nums[i]==0 && nums[j]!=0){
                int temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
                i++;
            }   
        }
        return nums;
    }
};