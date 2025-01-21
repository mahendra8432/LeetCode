class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long n=grid[0].size();
        long long sum0=0;//row0  sum
        for(long long i=0;i<n;i++){
            sum0+=grid[0][i];
        }
        long long sum3=0;
        for(long long i=0;i<n;i++){
            sum0-=grid[0][i];
            if(i>0)sum3+=grid[1][i-1];
            if(sum0==sum3) return sum0;
             if(sum0<sum3){
                return min(sum0+grid[0][i],sum3);
             }
        }
        return -1;
    }
};