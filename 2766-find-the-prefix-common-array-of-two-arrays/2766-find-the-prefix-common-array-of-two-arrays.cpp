class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size(),count=0;
        vector<int>C(n,0),D;
        for(int i=0;i<n;i++){
            C[A[i]-1]=C[A[i]-1]+1;
            C[B[i]-1]=C[B[i]-1]+1;
            if(C[A[i]-1]==2 ) count++;
            if(C[B[i]-1]==2 && A[i]!=B[i]) count++;
            D.push_back(count);
        }
        return D;
    }
};