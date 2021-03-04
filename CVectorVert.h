#pragma once
#include "CVector.h"
#include "Source.h"

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
};
