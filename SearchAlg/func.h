#pragma once


void KMP(char *text, char *search, int textl, int searchl);//������� ������ ���
void Suffix(char *search, int b[], int N);//������� ���������� ������� ���������
void BM(char *search, char *text, int textl, int searchl);
void BMTable(char *search, int d[], int searchl);