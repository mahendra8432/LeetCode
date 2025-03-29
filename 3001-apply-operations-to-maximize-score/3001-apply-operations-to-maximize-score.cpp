#define ll long long
class Solution {
public:
long long mod=1000000007;
long long binpow(long long a, long long b) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
    int primeScore[100005];
    void seive(int lim,vector<int>&primeScore){
        for(int i=2;i<=lim;i++){
            if(primeScore[i]!=0) continue;
            for(int j=i;j<=lim;j+=i){
                primeScore[j]++;
            }
        }
    }
    int maximumScore(vector<int>& nums, int k) {
        int lim=*max_element(nums.begin(),nums.end());
        vector<int> primeScore(lim+1,0);
        seive(lim,primeScore);
        vector<ll> temp;
        ll n=nums.size();
        for(auto it:nums){
            temp.push_back(primeScore[it]);
        }
        vector<ll> l(n),r(n);
        stack<ll> st;
    //calculating max possible length to the left side of that element 
        for(ll i=n-1;i>=0;i--){
            if(st.empty()){
                r[i]=n-i-1;
            }
            else{
                while(!st.empty()&&temp[st.top()]<=temp[i]) st.pop();
                if(st.empty()) r[i]=n-i-1;
                else r[i]=st.top()-i-1;
            }
            st.push(i);
        }
        //calculating max possible length to the left side of that element 
        while(!st.empty()) st.pop();
        for(ll i=0;i<n;i++){
            if(st.empty()){
                l[i]=i;
            }
            else{
                while(!st.empty()&&temp[st.top()]<temp[i]) st.pop();
                if(st.empty()) l[i]=i;
                else l[i]=i-st.top()-1;
            }
            st.push(i);
        }

        //calculating the number of subarrays containing ith element such that value of x will be the ith element 
        for(ll i=0;i<n;i++) l[i]=(r[i]+1)*(l[i]+1);
        vector<pair<ll,ll>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],l[i]});
        }

//sorting in non increasing order w.r.t value of nums and calculate the ans
        sort(v.rbegin(),v.rend());
        long long ans=1;
        for(ll i=0;i<n;i++){
            if(k<=0) break;
            long long mul=1;
            mul=min((ll)k,v[i].second);
            k=max(0LL,(ll)k-mul);
            ans=(ans*binpow(v[i].first,mul))%mod;
        }
        return ans;
    }
};