#pragma once

class Matrix
{
private:
	int** arr;
	int* names;
	int n;
	Animal* animals;
	int annum;
	int* way = 0;
public:
	Matrix();
	int Read(std::string file);
	int Write(std::string file);
	int findWay();
	int** getArr();
	int* getNames();
	int getN();
	int* getWay();
	~Matrix();
};

