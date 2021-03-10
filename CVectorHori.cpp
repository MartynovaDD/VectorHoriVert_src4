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
        CVector1 res(b.filename, q, a.n);
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
        CVector1 res(b.filename, q, a.n);
        delete[] q;
        return res;
    }
}


int CVector1::output(const char* FileName){
    ofstream output(FileName, ios_base::app);
    for (int i = 0; i < n; i++) {
        output << s[i] << " ";
        cout << s[i] << " ";
    }
    output << '\n';
    output.close();
    return 0;
}