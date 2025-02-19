class Solution {
public:
    int f(int n)
    {
        if(n == 0)
            return 0;
        if(n == 1)
            return 3;
        return 3 * pow(2, n - 1);
    }
    string getHappyString(int n, int k) {
        int c = f(n);
        if(c < k)
            return "";
        string s;
        int ca = pow(2, n - 1);
        int cb = 2*ca, cc = 3*ca;
        while(n--)
        {
            // cout << k << " ";
            if(k <= ca)
            {
                s.push_back('a');
            }
            else if(k <= cb)
            {
                if(s.empty())
                    k -= ca;
                else
                {
                    if(s.back() == 'a')
                    {}
                    else
                        k -= ca;
                }
                s.push_back('b');
            }
            else if(k <= cc)
            {
                if(s.empty())
                    k -= cb;
                else
                {
                    if(s.back() == 'b')
                        k -= ca;
                    else
                        k -= cb;
                }
                s.push_back('c');
            }
            if(s.back() == 'a')
            {
                ca = 0;
                cb = pow(2, n - 1);
                cc = 2*cb;
            }
            else if(s.back() == 'c')
            {
                ca = pow(2, n - 1);
                cb = 2*ca;
                cc = 0; 
            }
            else if(s.back() == 'b')
            {
                ca = pow(2, n - 1);
                cc = 2*ca;
                cb = 0; 
            }
        }
        return s;
    }
};