#include <vector>
#include <unordered_set>

// disjoint sets data structure
class classifier
{
public:
    classifier(int n) : n(n), c(n), r(n), q(n)
    {
        for (int i = 0; i < n; i++)
        {
            c[i] =i;
            components.insert(i);
        }
        q.assign(n, 1);
    }
    
    unordered_set<int> components;
    
    void unite(int x, int y);
    int operator [](int x);
    int count(int n);
    int comps() const { return components.size(); }
    
private:
    vector<int> c;
    vector<int> r;
    vector<int> q;
    
    int n;    
};

int classifier::operator[](int x)
{
   if (c[x] != x)
     c[x] = operator[](c[x]);
   return c[x];    
}


void classifier::unite(int x, int y)
{
   int xRoot = operator[](x);
   int yRoot = operator[](y);
 
   if (xRoot == yRoot)            
       return;  

   if (r[xRoot] < r[yRoot])
   {
       c[xRoot] = yRoot;
       components.erase(xRoot);
       q[yRoot] += q[xRoot];
   }
   else
       if (r[xRoot] > r[yRoot])
       {
            c[yRoot] = xRoot;
            components.erase(yRoot);
            q[xRoot] += q[yRoot];
       }
   else
   {      
       c[yRoot] = xRoot;
       components.erase(yRoot);
       q[xRoot] += q[yRoot];
       r[xRoot]++;
   }
}

int classifier::count(int x)
{
    return q[operator[](x)];
}