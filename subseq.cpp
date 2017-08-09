// length of longest susbsequence 

int commonChild(const vector<int>& s, const vector<int>& t)
{
    // Complete this function
    int n = s.size();
    int m = t.size();
    
    vector<vector<int>> length(m, vector<int>(n));
    
    if (s[0] == t[0])
        length[0][0] = 1;
    
    for (int i = 1; i < n; i++)
    {
        length[0][i] = length[0][i-1];
        if (s[i] == t[0])
            length[0][i] = 1;
    }
    
    for (int j = 1; j < m; j++)
    {
        length[j][0] = length[j-1][0];
        if (t[j] == s[0])
            length[j][0] = 1;       
        
        for (int i = 1; i < n; i++)
        {
            length[j][i] = length[j-1][i-1];
            if (s[i] == t[j])
                length[j][i]++;
            else
                length[j][i] = max(length[j-1][i], length[j][i-1]);
        }
    }
    
    return length[m-1][n-1];
}