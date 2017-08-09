typedef long long int64;

const int64 M = 1000000007;

int64 inv(int64 m)
{
    m = m % M;
    
    int64 p = M;
    int64 q = m;
    
    int64 a = 1;
    int64 b = 0;
    
    int64 c = 0;
    int64 d = 1;    
    
    while (q > 0) // p > q
    {
        int64 r = p % q;
        int64 s = p / q;
        
        p = q;
        q = r;
        
        int64 x = a - s * c;
        int64 y = b - s * d;
        
        a = c;
        b = d;
        
        c = x;
        d = y; 
    }
    while (b < 0)
        b += M;    
    
    return b;
}

int64 power(int64 a, int64 n)
{
    int64 r = 1;
    while (n)
    {
        if (n & 1)
        {
            n--;
            r *= a;
            r %= M;
        }
        else
        {
            n >>= 1;
            a *= a;
            a %= M;            
        }
    }    
    return r;    
}
