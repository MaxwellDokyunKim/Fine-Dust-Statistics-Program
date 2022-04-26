#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


class Datas {




public:

	CString EXData[522][10];


	Datas() {

		for (int i = 0; i < 522; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				EXData[i][j] = "";
			}

		}


	}

};