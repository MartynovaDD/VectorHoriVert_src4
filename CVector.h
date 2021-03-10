#pragma once

#include <iostream>
#include <fstream>
#include <stdio.h>
#include "Source.h"
using namespace std;
void AutoTest();

class CNode;
class CVector1;
class CVector {
protected:
	string filename;
	double* s; int n;
public:
	CVector() { SetZero(); }
	virtual ~CVector() { Clean(); }
	CVector(string FileName, const double* ss, int n=0) {
		filename = FileName; //s.c_str()
		this->n = n; 
		s = new double[n];
		for (int i = 0; i < n; i++) { s[i] = ss[i]; }
	};
	CVector(const CVector& b) { CopyOnly(b); }
	
	void Clean() { delete[] s; SetZero(); }
	void SetZero() { s = NULL; n = 0; }
	void CopyOnly(const CVector& b) { n = b.n; s = new double[n]; for (int i = 0; i < n; i++) s[i]=b[i]; }
	operator const double* ()const { return s; }
	void print(){
		for (int i = 0; i < n; i++) 
			cout << s[i] << " ";
	}
	int length()const { return n; }
	double* vector()const { return s; }
	CVector& operator=(const CVector& b) {
		if (this != &b) {
			Clean();
			CopyOnly(b);
			return *this;
		}
	}
	CNode operator[](int i) {
		if (i < 0) {
			throw - 1;
		}
		return CNode(this, i);
	}
	/*double& operator[](int i) const{
		return s[i];
	}*/
	string Filename() {
		return filename;
	}
	virtual int output(const char* FileName) = 0;
	friend class CNode;
	friend CVector1 operator+(const CVector& first, const CVector& second);
	friend CVector1 operator-(const CVector& first, const CVector& second);
};



