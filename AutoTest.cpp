#include "CVector.h"


void AutoTest() {
    double* q = new double[3];
    double* v = new double[3];
    for (int i = 0; i < 3; i++) {
        q[i] = i;
    }
    for (int i = 0; i < 3; i++) {
        v[i] = 1;
    }
    const char* f = "vert.txt";
    CVector0 a("vert.txt", q, 3);
    CVector0 b("vert.txt", v, 3);
    CVector0 d;
    d = a + b;
    if (d.vector()[0] == 1 && d.vector()[1] == 2 && d.vector()[2] == 3) {
        printf("Autotest passed...\n");
    }
    else {
        printf("Autotest failed...\n");
    }
}