#pragma once
#include "CVector.h"
#include "Source.h"

class CVector1 :public CVector {
public:
	CVector1() {}
	using CVector::CVector;
	using CVector::operator=;
	~CVector1() {};
	CVector1(const CVector& other) :
		CVector(other) 
	{
	}
	int output(const char* FileName) override;
	//CVector1 operator+(const CVector1& b);
	friend CVector1 operator+(const CVector& first, const CVector& second);
	friend CVector1 operator-(const CVector& first, const CVector& second);
};