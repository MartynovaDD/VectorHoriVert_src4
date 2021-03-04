#include "CVectorHori.h"


CVector1 operator+(const CVector& a, const CVector& b)
{
    if (a.n != b.n)
    {
        cout << "Error: vectors have different dimensions." << endl;
        exit(-1);
    }
    else
    {
        double* q = new double[a.n];
        for (int i = 0; i < a.n; i++)
        {
            q[i] = a.s[i] + b[i];
        }
        CVector1 res("hori.txt", q, a.n);
        delete[] q;
        return res;
    }
}

CVector1 operator-(const CVector& a, const CVector& b)
{
    if (a.n != b.n)
    {
        cout << "Error: vectors have different dimensions." << endl;
        exit(-1);
    }
    else
    {
        double* q = new double[a.n];
        for (int i = 0; i < a.n; i++)
        {
            q[i] = a.s[i] - b[i];
        }
        CVector1 res("hori.txt", q, a.n);
        delete[] q;
        return res;
    }
}