#include<iostream>
using namespace std;
#include"±êÍ·.h"
#include<string>
int x, y;
 double v[100][100];
void Partion(string s,string& x,string& n)
{
	x = "";
	n = "";
	int i = 0;
	while (i < s.size())
	{
		if (s[i] != 'x')x = x + s[i];
		else
		{
			n = s[i + 1];
			break;
		}
		i++;
	}
	if (i == 0)x = "1";
}
void read()
{
	
	x = 0;
	y = 0;
	string s;
	cin >> s;
	while (s != "#")
	{
		string temp,temp2,temp3;
		int i = 0;
		int f = 0;
		while (i < s.size())
		{
			
			temp = temp + s[i];
			if ((s[i] == '+'|| s[i] == '-'|| s[i] == '=')&&i!=0)
			{
				Partion(temp, temp2, temp3);	
				int k = atof(temp3.c_str());
				if (k > y) y = k;
				if(f==0) v[x][k-1]= atof(temp2.c_str());
				else if(f==1) v[x][k-1] = -atof(temp2.c_str());

				if (s[i] == '+')f = 0;
				else if (s[i] == '-')f = 1;
				else if (s[i] == '=')f = 0;
				temp = "";
			}
			if (s[i] == '-' && i == 0)
			{
				f = 1;
				temp = "";
			}
			i++;
		}

		if(f==0)v[x][99] = atof(temp.c_str());
		else if (f == 1)v[x][99] = -atof(temp.c_str());
		x++;
		cin >> s;
	}
	for (int i = 0; i < x; i++)
	{
		v[i][y] = v[i][99];
	}
}
int main()
{
	cout << "ÇëÊäÈë"<<endl;
	read();
	GuessMatrix g(x, y+1);
	g.getvalue(v);
	g.elimination();
	return 0;
}