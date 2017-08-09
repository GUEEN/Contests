// vector<vector<double>> A    system n*n-matrix
// vector<double> b            right-hand side

for (int i = 0; i < n; i++)
{
    double M = A[i][i];
    int j0 = i;
    for (int j = i + 1; j < n; j++)
    {
        if (abs(A[j][i]) > abs(M))
        {
            j0 = j;
            M = A[j][i];                
        }
    }
    if (M == 0.0)
        continue;
        
    if (j0 > i)
    {   
        swap(A[i], A[j0]);
        swap(b[i], b[j0]);
    }
    for (int j = 0; j < n; j++)
        A[i][j] /= M;
    b[i] /= M;
        
    // now apply our favourite Gauss
    for (int i0 = 0; i0 < n; i0++)
    {
        if (i0 == i)
            continue;
        double lambda = A[i0][i];
        for (int j = 0; j < n; j++)
            A[i0][j] -= lambda * A[i][j];
        b[i0] -= lambda * b[i];
    }        
}
// if the system was defined then b[i] now contain solutions
