#pragma once

#include <iostream>
#include <fstream>
#include <stdio.h>
#include "Source.h"
using namespace std;
void AutoTest();

class CNode;
class CVector {
protected:
	const char* filename;
	double* s; int n;
public:
	CVector() { SetZero(); }
	~CVector() { Clean(); }
	CVector(const char* FileName, const double* ss, int n=0) {
		filename = FileName;
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
	double& operator[](int i) const {
		return s[i];
	}
	const char* Filename() {
		return filename;
	}
	virtual int output(const char* FileName) = 0;
	friend class CNode;
};

class CVector0 :public CVector {
public:
	using CVector::CVector;
	using CVector::operator=;
	~CVector0() {};
	int output(const char* FileName) override {
		filename = FileName;
		ofstream output(FileName);
		for (int i = 0; i < n; i++) {
			output << s[i] << endl;
			cout << s[i] << endl;
		}
		return 0;
	}
	CVector0 operator+(const CVector0& b);
	CVector0 operator-(const CVector0& b);
};


class CVector1 :public CVector {
public:
	using CVector::CVector;
	using CVector::operator=;
	~CVector1() {};
	int output(const char* FileName) override {
		ofstream output(FileName);
		for (int i = 0; i < n; i++) {
			output << s[i] << " ";
			cout << s[i] << " ";
		}
		return 0;
	}
	CVector1 operator+(const CVector1& b);
	CVector1 operator-(const CVector1& b);
};