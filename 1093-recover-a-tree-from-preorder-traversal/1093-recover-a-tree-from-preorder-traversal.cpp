class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack <TreeNode*> s;
        for (int i = 0; i < traversal.length();){
            int level = 0;
            while(traversal[i] == '-')
                level++, i++;
            int strt = i;
            while(isdigit(traversal[i]))
                i++;
            int val = stoi(traversal.substr(strt, i - strt + 1));
            TreeNode* result = new TreeNode(val);
            if (s.empty())    
                {s.emplace(result); continue;}
            while(s.size() > level) 
                s.pop();
            if (s.top()->left)  
                s.top()->right = result;
            else 
                s.top()->left = result;
            s.emplace(result);
        }
        while(s.size() > 1)
            s.pop();
        return s.top();
    }
};