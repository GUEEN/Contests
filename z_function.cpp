vector<int> z_function(const string& s)
{
    int n = s.length();
    vector<int> z(n);
    
    int l = 0;
    int r = 0; 
        
    for (int i = 1; i < n; i++)
    {
        // s[l]...s[r] is the most rightmost substring that is also a preffix of s
        if (i <= r) // trivial search
            z[i] = min(z[i - l], r - i + 1);
        while (i+z[i] < n && s[i+z[i]] == s[z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)        
        {
            l = i;
            r = i + z[i] - 1;
        }
    }    
    return z;
}