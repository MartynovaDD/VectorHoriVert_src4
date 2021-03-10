#include "CVector.h"
#include "Source.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>  
#include "CVectorHori.h"
#include "CVectorVert.h"
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
				file >> l;
				double* z = new double[l];
				for (int j = 0; j < l; j++) {
					file >> z[j];
				}
				if (g == 0) {
					arr[i] = new CVector0(s, z, l);
				}
				
				if (g == 1) {
					arr[i] = new CVector1(s, z, l);
				}
				delete[] z;
			}
			for (int i = 0; i < n; ++i) {
				cout << arr[i]->Filename() << endl;
				arr[i]->output((arr[i]->Filename()).c_str());
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





