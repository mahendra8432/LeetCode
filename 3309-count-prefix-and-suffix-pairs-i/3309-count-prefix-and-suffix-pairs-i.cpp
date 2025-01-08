#include <bits/stdc++.h>
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size(),l1,l2,count=0;
        for(int i=0;i<n;i++){
             l1=words[i].length();
            for(int j=i+1;j<n;j++){
                l2=words[j].length();
                  if(l1<=l2){
                    if((words[i]==words[j].substr(0,l1)) && (words[i]==words[j].substr(l2-l1,l1))) {
                        count++;
                    }
                   
                      
                }
            }
        }
        return count;
    }
};