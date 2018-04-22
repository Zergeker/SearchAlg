#include "stdafx.h"
using namespace std;


void KMP(char *text, char *search, int textl, int searchl) {
	int *b = new int[searchl]; //������� ��������������� ������������ ������
	Suffix(search, b, searchl); //���������� ������� ��������� ��� �������
	int n = 0;
	bool fnd = 0;
	for (int m = 0; m <= textl; m++) {
		//�������� �� ��������� ������(���������� � �����)
		if (m == textl && !fnd)
			cout << endl << "Not found.";
		//���������� m ������� ��������� ������ � n ������� �������, ��� ���������� ���������� m+1 � n+1 ��������
		//���� ��� ��������� �������� �� ���������, "��������" ������ �� b[n-1] ��������� � ������ ������ ��������
		else if (text[m] == search[n]) {
			n++;
			//���� n ����� ����� �������, �� ������� ������, ���������� ���
			if (n == searchl && !fnd) {
				cout << endl << "Found." << text[m];
				fnd = 1;
			}
		}
		else if (n != 0) {
			n = b[n - 1];
			m--;
		}
	}
}

void Suffix(char *search, int b[], int N) {
	b[0] = 0;
	int j = 0;
	// ���������� i � j �������� � ������: ���� ��� ��������� - ����������� b[i] �� j+1 (� ����������� j �� 1)
	// � ������ ��������� ���; ���� �������� �� ��������� - ������� ��� ��������� j: ���� ��� � ������ ������, �����������
	// b[i] ���� � ������ ��������� ���, � ��������� ������ ������ j �� �������, ������ b[j-1] � ����� ��������� ��������
	for (int i = 1; i < N; i++) {
		if (search[i] == search[j])
			b[i] = ++j;
		else {
			if (j == 0)
				b[i] = 0;
			else {
				j = b[j - 1];
				i--;
			}
		}
	}
}

void BMTable(char *search, int d[], int searchl) {
	int j = 1;

	int i = searchl - 2;

	for (int i = searchl - 2;i >= 0; i--)
		if (d[search[i]] != searchl) {
			j++;
		}
		else {
			d[search[i]] = j++;
		}
}

void BM(char *search, char *text, int textl, int searchl) {
	int *d = new int[256];
	for (int i = 0; i < 256; i++)
		d[i] = searchl;
	BMTable(search, d, searchl);
	int m = searchl - 1;
	int i = m, j = m;
	bool fnd = 0;
	while (j < textl) {
		if (search[m] == text[i])
		{
			m--;
			i--;
			if (m < 0) {
				cout << "Found" << " " << j-searchl+2;
				fnd = 1;
				break;
			};
		}
		else {
			j += d[text[j]];
			m = searchl - 1;
			i = j;
		}

	}
	if (!fnd)
		cout << "Not found";
}