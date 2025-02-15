vector<int> db(1001,0);
bool rec(vector<int> &val, int i, int x, int sm,int as,int n){
    if(i>=n) {
        return sm+as==x;
    }
    if(as==0) return rec(val,i+1,x,sm,(as*10)+val[i],n);
    return rec(val,i+1,x,sm,(as*10)+val[i],n) or rec(val,i+1,x,sm+as,val[i],n);
}
vector<int> conv(int x){
    vector<int> ans;
    while(x!=0){
        ans.push_back(x%10);
        x/=10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
void Fill(){
    for(int i=1;i<1001;i++){
        db[i] = db[i-1];
        vector<int> ans = conv(i*i);
        // instead of this reccursion you can use your own code, this does not matter
        if(rec(ans,0,i,0,0,ans.size())){
            db[i]+=i*i;
        }
    }
}
class Solution {
public:
    int punishmentNumber(int sz) {
        if(db[1]==0){
            Fill(); // This will run only for the first test case.
        }
        return db[sz];
    }
};