class Solution {
public:
    long long smallestNumber(long long num) {
       string str=to_string(num);
       long long n=num;
      if(num>0) {
        sort(str.begin(),str.end());
        int i=0;
        while( i<str.length() && str[i]=='0') i++;
        if(i<str.length()) swap(str[0],str[i]);
        num=stoll(str);
      }
      else{ 
        sort(str.begin(),str.end(),greater<char>());
        num=stoll(str);
        }
       if(n>0) return num;
       return -1*num;
    }
};