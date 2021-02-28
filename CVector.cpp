#include "CVector.h"
#include "Source.h"



CVector0 CVector0::operator+(const CVector0& b)
{
    if (n != b.n)
    {
        cout << "Error: vectors have different dimensions." << endl;
        exit(-1);
    }
    else
    {
        double* q = new double[n];
        for (int i = 0; i < n; i++)
        {
            q[i] = s[i] + b[i];
        }
        CVector0 res("vert.txt", q,n);
        delete[] q;
        return res;
    }
}

CVector0 CVector0::operator-(const CVector0& b)
{
    if (n != b.n)
    {
        cout << "Error: vectors have different dimensions." << endl;
        exit(-1);
    }
    else
    {
        double* q = new double[n];
        for (int i = 0; i < n; i++)
        {
            q[i] = s[i] - b[i];
        }
        CVector0 res("vert.txt", q, n);
        delete[] q;
        return res;
    }
}


CVector1 CVector1::operator+(const CVector1& b)
{
    if (n != b.n)
    {
        cout << "Error: vectors have different dimensions." << endl;
        exit(-1);
    }
    else
    {
        double* q = new double[n];
        for (int i = 0; i < n; i++)
        {
            q[i] = s[i] + b[i];
        }
        CVector1 res("hori.txt", q, n);
        delete[] q;
        return res;
    }
}

CVector1 CVector1::operator-(const CVector1& b)
{
    if (n != b.n)
    {
        cout << "Error: vectors have different dimensions." << endl;
        exit(-1);
    }
    else
    {
        double* q = new double[n];
        for (int i = 0; i < n; i++)
        {
            q[i] = s[i] - b[i];
        }
        CVector1 res("hori.txt", q, n);
        delete[] q;
        return res;
    }
}