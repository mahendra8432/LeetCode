class Solution {
public:
    vector<int> partitionLabels(string S) 
    {
        map<char, int> my_map;
        for (int i = 0; i < S.length(); i++)
            my_map[S[i]] = i;
        
        vector<int> partitions;
        
        int max_ = 0;
        int i = 0;
        int startPartition = 0;
        
        while (i < S.length())
        {
            max_ = max_ > my_map[S[i]] ? max_ : my_map[S[i]];
            
            if (max_ == i)
            {
                partitions.push_back(i + 1 - startPartition);
                startPartition = i + 1;
            }
            
            i++;
        }
        return partitions;
    }
    
};