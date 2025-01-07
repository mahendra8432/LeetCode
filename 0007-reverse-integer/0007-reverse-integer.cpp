class Solution {
public:
    int reverse(int x) {
        long long n=(long long)x,r,sum=0;
        int a=INT_MAX;
        while(n!=0){
            r=n%10;
            n=n/10;
            sum=sum*10+r;
        }
        if(sum>INT_MAX || sum<INT_MIN) return 0;
        if(x<0) return sum;
        else return sum; 
    }
};