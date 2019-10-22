#include<iostream>
#include"McCluskeyAlgorithm.h"

using namespace std;



int main()
{
	int n;

	
	cout << "Enter num variable of Karnaugh map: ";
	cin >> n;

	system("cls");


	McCluskeyAlgorithm mc(n);

	cout << "------------------------------------------" << endl;

	mc.Input();
	mc.QM_Method();
	mc.Minimizer();
	cout << endl;


	system("pause");
	return 0;
}