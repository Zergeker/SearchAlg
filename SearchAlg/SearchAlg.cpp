
#include "stdafx.h"
#include <iostream>;

using namespace std;
int main()
{
	char FText[]="abbaaababaaabb";
	char SText[]="basab";
	cout << strlen(FText) << endl;
	system("pause");
	int N1 = strlen(FText);
	int N2 = strlen(SText);
	//KMP(FText, SText, N1, N2);
	BM(SText, FText, N1, N2);
	system("pause");

}