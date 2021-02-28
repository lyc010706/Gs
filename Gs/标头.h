#pragma once
class GuessMatrix
{
private:
	double** value;
	int Numline;
	int Numrow;
	int rA();
	int rAB();
	int adjust(int i);
	int firstpos(int i);
	int nextpos(int i, int j);
public:
	GuessMatrix(int x, int y)
	{
		value = new double*[x];
		for (int i = 0; i < x; ++i) {
			value[i] = new double[y];
		}
		Numline = x;
		Numrow = y;
	}
	void elimination();
	void getvalue(double va[][100]);
};