#include "CVector.h"
#include "Source.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>  
using namespace std;


int main(void)
{
	try {
		AutoTest();
		ifstream input("data.txt");
		if (!input)
		{
			cout << "Error! Cannot open file..." << endl;
			return -1;
		}
		else {
			int l;
			int g;
			int n = 0;
			string s;
			char* str = new char[1024];
			while (!input.eof())
			{
				input.getline(str, 1024, '\n');
				n++;
			}
			input.close();
			ifstream file("data.txt");
			CVector** arr = new CVector * [n];
			for (int i = 0; i < n; ++i) {
				file >> g;
				file.seekg(1, ios::cur);
				getline(file, s, ' ');
				const char* p = s.c_str();
				file >> l;
				double* z = new double[l];
				for (int i = 0; i < l; i++) {
					file >> z[i];
				}
				if (g == 0) {
					arr[i] = new CVector0(p, z, l);
				}
				if (g == 1) {
					arr[i] = new CVector1(p, z, l);
				}
				delete[] z;
			}
			for (int i = 0; i < n; ++i) {
				arr[i]->output(arr[i]->Filename());
			}
			file.close();
			delete[] str;
			for (int i = 0; i < n; ++i) {
				delete arr[i];
			}
			delete[] arr;
			
			return 0;
		}
	}
	catch (int err) { printf("error=%d\n", err); }
}





