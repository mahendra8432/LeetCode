class Solution {
public:
//Method 2:- String
    vector<int> plusOne(vector<int>& digits) {
        string str = "";
        for(int d : digits) str += to_string(d);
        int n = str.size();
        for(int i = n - 1; i >= 0; i--) {
            if(str[i] < '9') {
                str[i]++;
                break;
            } else str[i] = '0';
        }
        if(str[0] == '0') str = "1" + str;
        vector<int> result;
        for(char c : str) result.push_back(c - '0');
        return result;
    }
};
