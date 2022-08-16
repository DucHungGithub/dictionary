#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	ifstream fin("sample3.txt");
	int j = 1;
	string a;
	while (!fin.eof())
	{
		bool check = false;
		getline(fin, a,'\n');
		for (int i = 0; i < a.length(); i++)
		{
			if (int(a[i]) < 0 || int(a[i]) > 127)
			{
				cout << a << endl;
				cout << j << " " << a[i] << endl;
				check = true;
			}
		}
		j++;
	}
	fin.close();
	return 0;

}