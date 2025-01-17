class Solution {
public: 
// [l,r] ki range me aise numbers dundo jo prime numbers ke squares hai.
    bool isprime(int n){
            if(n<=1) return false;
            for(int i=2;i<=sqrt(n);i++){
                if(n%i==0) return false;
            }
            return true;
        }
    int nonSpecialCount(int l, int r) {
            int count=0;
        for(int i=(int)sqrt(l);i<=sqrt(r);i++){
            if(isprime(i)){
                int square=i*i;
                if(square>=l && square<=r) count++;
        }
        }
        return (r-l+1-count);
    }
 
};