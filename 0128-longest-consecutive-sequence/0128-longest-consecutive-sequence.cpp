class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return n;
        int count=1,maxi=1,c;
        priority_queue <int, vector<int>, greater<int> > pq; 
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        while(pq.size()!=0){
           // if(pq.size()==n)
                     c=pq.top();
                    pq.pop();
            if(c==pq.top()) continue;
            else if(c+1==pq.top()) {
                count++;
            }
            else{
                if(count>maxi) maxi=count;
                count=1;
            }
           
        }

        return max(maxi,count);
    }
};