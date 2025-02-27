class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        int i=0, flag=1;
        string ans="";
        while(i<n && s[i]==' ') i++;
        if(s[i]=='-') {flag =-1;i++;}
        else if(s[i]=='+')i++;
        for( i=i;i<n;i++){
            if(toascii(s[i])>=47 && toascii(s[i])<=58) ans+=s[i];
            else if(ans=="") return 0;
            else break;
            if(flag==1 && stoll(ans)>=(long long)INT_MAX) return INT_MAX;
            else if(flag==-1 && (flag)*stoll(ans)<=(long long)INT_MIN) return INT_MIN;
        }
        if(ans=="") return 0;
        else {
              if(flag==1) return min(stoll(ans),(long long)INT_MAX);
              else return max((flag)*stoll(ans),(long long)INT_MIN);
            }
    }
};