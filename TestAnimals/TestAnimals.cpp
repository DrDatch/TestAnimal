// KillAnimals.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

int test(std::string filename, int errexp, int** inarr = 0, int* innames = 0, int inn = 0);

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

int test(std::string filename, int errexp, int** inarr, int* innames, int inn){
	Matrix mat;
	int ret = 1;
	int err = mat.Read(filename);
	int n;
	std::string outname = "out." + filename;
	

	if (err == errexp){
		ret = 0;//Correct
	}
	if (err == errexp && err == 0){
		int** arr = mat.getArr();
		int* names = mat.getNames();
		int** tarr;
		int* tnames;
		n = mat.getN();
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
						ret = 1;//Uncorrect in
						break;
					}
				}
				if (tnames[i] != names[i]){
					ret = 1;//Uncorrect in
					break;
				}
			}
		}
		else{
			if (inarr != 0 && innames != 0 && inn != 0){
				n = inn;
				for (int i = 0; i < inn; i++){
					for (int j = 0; j < inn; j++){
						if (inarr[i][j] != arr[i][j]){
							ret = 1;//Uncorrect in
							break;
						}
					}
					if (innames[i] != names[i]){
						ret = 1;//Uncorrect in
						break;
					}
				}
			}
		}
	}
	if (err == 0 && ret == 0){
		if (mat.findWay() && mat.Write(outname)){
			int* test;
			int* way;
			
			
			way = mat.getWay();
			test = new int[n];
			for (int i = 0; i < n; i++){
				test[i] = 0;
			}
			for (int i = 0; i < n; i++){
				test[way[i]]++;
				if (test[way[i]]>1){
					ret = 2;// Uncorrect out
					break;
				}
			}
		}
		else ret = 2;// Uncorrect out
	}
	if (ret == 0) cout << filename << " - All right!\n";
	if (ret == 1) cout << filename << " - Uncorrect in!\n";
	if (ret == 2) cout << filename << " - Uncorrect out!\n";
	return ret;//Uncorrect
}