class Solution {
public:
    vector<int> ans;
    vector<int> used;
    bool func(int i){
        if(i==ans.size()){
            return true;
        }
        if(ans[i]!=-1)return func(i+1);
        for(int j=used.size()-1;j>0;j--){
            if(used[j]!=-1)continue;
            if(j==1){
                ans[i]=j;
                used[j]=1;
                if(func(i+1))return true;
                used[j]=-1;
                ans[i]=-1;
            }
            else if(i+j<ans.size()&&ans[i+j]==-1){
                ans[i]=j;
                ans[i+j]=j;
                used[j]=1;
                if(func(i+1))return true;
                used[j]=-1;
                ans[i]=-1;
                ans[i+j]=-1;
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        ans.resize(2*n-1,-1);
        used.resize(n+1,-1);
        bool flag =func(0);
        return ans;
    }
};