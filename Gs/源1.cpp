#include<iostream>
#include"标头.h"
using namespace std;
void GuessMatrix::elimination()
{
	/*for (int i = 0; i < Numline; i++)
	{
		if (value[i][i] == 0)
		{
			for (int j = 0; j<Numline; j++)
			{

			}
		}
	}*/
	int minpos = 0;
	double d;
	for (int i = 0; i < Numline-1; i++)
	{	
		for (int j = i+1; j < Numline; j++)
		{
			d = value[j][minpos] / value[i][minpos];
			for (int k = minpos; k < Numrow; k++)
			{
				value[j][k] = value[j][k] - d*value[i][k];
			}
			
		}
		minpos = adjust(i + 1);
	}
	/*for (int i = 0; i < Numline; i++)
	{
		for (int j = 0; j < Numrow; j++)
			cout << value[i][j] << " ";
		cout << endl;
	}*/
	if (rA() != rAB()) cout << "方程无解";
	else if (rA() == Numrow-1)
	{
		
		for (int i = rA() - 1; i > 0; i--)
		{
			int maxpos = firstpos(i);
			for (int j = i - 1; j >= 0; j--)
			{
				d = value[j][maxpos] / value[i][maxpos];
				for (int k = 0; k < Numrow; k++)
				{
					value[j][k] = value[j][k] - d*value[i][k];
				}
			}
		}
	
		for (int i = 0; i < rA(); i++)
		{
			minpos = firstpos(i);
			d = value[i][minpos];
			for (int k = minpos; k < Numrow; k++)
			{
				value[i][k] = value[i][k] / d;
				
			}
			cout << "x" << i + 1 << "=" << (value[i][Numrow - 1]) << endl;
		}

	}
	else if (rA() < Numrow - 1)
	{
		for (int i = rA() - 1; i > 0; i--)
		{
			int maxpos = firstpos(i);
			for (int j = i - 1; j >= 0; j--)
			{
				d = value[j][maxpos] / value[i][maxpos];
				for (int k = 0; k < Numrow; k++)
				{
					value[j][k] = value[j][k] - d * value[i][k];
				}
			}
		}
		for (int i = 0; i < rA(); i++)
		{
			minpos = firstpos(i);
			cout << "x" << minpos + 1 << "=";
			d = value[i][minpos];
			for (int k = minpos; k < Numrow; k++)
			{
				value[i][k] = value[i][k] / d;
				if (k != minpos && k != Numrow - 1 && value[i][k] != 0)
				{
					if(value[i][k]>0)cout << -value[i][k] << "x" << k + 1;
					else cout << "+" << value[i][k] << endl;
				}
			}
			if (value[i][Numrow - 1] > 0)cout << "+" << value[i][Numrow - 1]<<endl;
			else cout << value[i][Numrow - 1]<<endl;
		}
		cout << "有无数解" << endl;

	}

	
}
int GuessMatrix::rA()
{
	int n = 0;
	int f = 0;
	for (int i = 0; i < Numline; i++)
	{
		f = 0;
		for (int j = 0; j < Numrow - 1; j++)
		{
			if (value[i][j] != 0)f = 1;
		}
		if (f == 0)break;
		n++;
	}
	return n;
}

int GuessMatrix::rAB()
{
	int n = 0;
	int f = 0;
	for (int i = 0; i < Numline; i++)
	{
		f = 0;
		for (int j = 0; j < Numrow; j++)
		{
			if (value[i][j] != 0)f = 1;
		}
		if (f == 0)break;
		n++;
	}
	return n;
}

int GuessMatrix::adjust(int i)
{
	int minpos;
	int l=i;
	minpos = firstpos(i);
	for (int j = i; j < Numline; j++)
	{
		if (firstpos(j) < minpos)
		{
			minpos = firstpos(j);
			l = j;
		}
	}
	if (l != i)
	{
		double temp;
		for (int k = 0; k < Numrow; k++)
		{
			temp = value[i][k];
			value[i][k] = value[l][k];
			value[l][k] = temp;
		}
	}
	return firstpos(l);
}

int GuessMatrix::firstpos(int i)
{
	int j;
	for (j = 0; j < Numrow; j++)
	{
		if (value[i][j] != 0)return j;
	}
}

void GuessMatrix::getvalue(double va[][100])
{
	
	for (int i = 0; i <Numline; i++)
	{
		for (int j = 0; j < Numrow; j++)
		value[i][j]=va[i][j];
	}
}

int GuessMatrix::nextpos(int i,int j)
{
	int k;
	for (k = j+1; k < Numrow-1; k++)
	{
		if (value[i][k] != 0)return k;
	}
	return -1;
}