#pragma once
#include "CVector.h"
#include "Source.h"

class CVector0 :public CVector {
public:
	using CVector::CVector;
	using CVector::operator=;
	~CVector0() {};
	int output(const char* FileName) override;
};
