class Solution {
public:
    // Method 3:-Space Optimization
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        vector<int>temp1(n,1),temp2(n,-1);
        int prevleft=1,curri;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(i==0) {
                    curri=prevleft;
                    prevleft=curri;
                    temp2[j]=curri;
                }
                else if(j==0) {
                    curri=temp1[j];
                    prevleft=curri;
                    temp2[j]=curri;
                }
                else{
                    curri=prevleft + temp1[j];
                    prevleft=curri;
                    temp2[j]=curri;
                }
            }
            temp1=temp2;
        }
        return prevleft;
    }
};
// value of each box is addition of value of box which is at left and at up.
// 2 array lenge temp1  upar wale row ki sari vaues stoe karega. temp2 current row ki sari values store karega jo agale row me kaam ayengi.