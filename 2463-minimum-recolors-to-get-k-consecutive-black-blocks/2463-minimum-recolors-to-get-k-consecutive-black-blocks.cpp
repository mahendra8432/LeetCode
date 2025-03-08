class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.length();
        int i=0,j=0,count=0;
        for(j=0;j<k;j++){
            if(blocks[j]=='W') count++;
        }
        int mini=count;
        for(j=k;j<n;j++){
            if(blocks[i]=='W') count--;
            if(blocks[j]=='W') count++;
            if(count<mini) mini=count;
            i++;
        }
        return mini;
    }
};