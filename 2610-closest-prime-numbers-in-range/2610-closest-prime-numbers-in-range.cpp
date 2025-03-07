class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if(left==1)left++;
        vector<bool> v(right+1,true);
        for(int i = 2; i <= sqrt(right); i++){
            if(v[i]){
                for(int j = i*i; j <= right; j += i){
                    v[j] = false;
                }
            }
        }
        int i = left;
        int j;
        int a = -1, b = -1, k = INT_MAX;
        while(i<= right){
            if(v[i])break;
            i++;
        }
        j = i+1;
        while(j<=right){
            if(v[j]){
                if(j-i<k){
                    k = j-i;
                    a = i,b = j;
                }
                    i = j;
            }
            j++;
        }
        return {a,b};
    }
};