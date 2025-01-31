class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int prod=1,proin=1,profi=1,maxprod=1,indx1,ind,count=0,count2=0;
        bool flag=true,flag2=true;
        int maxi = *max_element(nums.begin(), nums.end());
         if(maxi==0){
            int p=0;
            while(p<n-1 && flag2) {
                if(nums[p]<0){
                    if(nums[p+1]<0) flag2=false;
                }
                p++;
            }
            if(flag2==true) return 0;
        }
        for(int i=0;i<n;i++){
            prod=1;proin=1;profi=1;flag=true,count=0;
            while(i<n && nums[i]!=0){
               if(nums[i]>=0) count2++;
               if(flag) {  if(nums[i]<0) flag=false;
                proin=proin*nums[i];
                indx1=i;
               }
                prod=prod*nums[i];
                if(nums[i]<0){ 
                    count++;
                    ind=i;
                }
             i++;
            }
            if(maxi<0  && count%2!=0) return max(prod/nums[0],prod/nums[n-1]);
            if(count==1) {
                 proin=proin/nums[indx1];
                 prod=prod/nums[indx1];
                 profi=prod/proin;
                 prod=max(profi,proin);
            }
            else if(count%2!=0){
                 while(ind<=i-1) {
                    profi=profi*nums[ind];
                     ind++;
                    }
                  prod=prod/max(proin,profi);
            }
            if(prod>maxprod) maxprod=prod;
        }
        return maxprod;
    }
};