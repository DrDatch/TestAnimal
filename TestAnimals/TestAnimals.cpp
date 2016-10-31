// KillAnimals.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

int test(char* filename, int errexp, int** inarr = 0, int* innames = 0, int inn = 0);

int _tmain(int argc, _TCHAR* argv[])
{
	test("0.txt", 0);
	test("1.txt", 0);
	test("2.txt", 0);
	test("3.txt", 0);
	test("4.txt", 4);
	test("5.txt", 5);
	test("6.txt", 6);
	test("7.txt", 7);
	test("8.txt", 8);
	test("9.txt", 9);

	return 0;
}

int test(char* filename, int errexp, int** inarr, int* innames, int inn){
	Matrix mat;
	int ret = 0;
	int err = mat.Read(filename);
	if (err == errexp){
		ret = 1;//Correct
	}
	if (err == errexp && err == 0){
		int** arr = mat.getArr();
		int* names = mat.getNames();
		int** tarr;
		int* tnames;
		int n = mat.getN();
		if (n == 3){
			tarr = new int*[n];
			for (int i = 0; i < n; i++){
				tarr[i] = new int[n];
			}
			tnames = new int[n];
			tarr[0][0] = 0; tarr[0][1] = 24; tarr[0][2] = 3;
			tarr[1][0] = 4; tarr[1][1] = 0;	 tarr[1][2] = 6;
			tarr[2][0] = 7; tarr[2][1] = 8;  tarr[2][2] = 0;
			 tnames[0] = 5;  tnames[1] = 2;   tnames[2] = 9;
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					if (tarr[i][j] != arr[i][j]){
						ret = 0;//Uncorrect
						break;
					}
				}
				if (tnames[i] != names[i]){
					ret = 0;//Uncorrect
					break;
				}
			}
		}
		else{
			if (inarr != 0 && innames != 0 && inn != 0){
				for (int i = 0; i < inn; i++){
					for (int j = 0; j < inn; j++){
						if (inarr[i][j] != arr[i][j]){
							ret = 0;//Uncorrect
							break;
						}
					}
					if (innames[i] != names[i]){
						ret = 0;//Uncorrect
						break;
					}
				}
			}
		}
	}
	if (ret == 1) cout << filename << " - All right!\n";
	if (ret != 1) cout << filename << " - Uncorrect!\n";
	return ret;//Uncorrect
}