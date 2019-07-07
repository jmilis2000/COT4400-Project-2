// Project2.cpp : Given 2 arrays of teeth, show minimum height and both arrays of teeth.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void PrintVectors(int n, vector<int> A)
{

	cout << "\nSize: " << n << "\nElements: ";
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

int Minimi(vector<int> S)
{
	auto minmax = std::minmax_element(S.begin(), S.end());
	//cout << "\nMaximum: " << *minmax.second;
	return *minmax.second;
}

void PrintResults(vector<int> A, vector<int> B, int min)
{
	int num = max(A.size(), B.size());
	
	cout << min << endl;
	for (int i = 0; i < num; i++)
	{
		
		if (i < A.size() && i < B.size())
			cout << A[i] << "\t" << B[i] << endl;
		else if ((i+1) > A.size())
			cout << "\t" << B[i] << endl;
		else if ((i+1) > B.size())
			cout << A[i] << "\t" << "\t" << endl;
	}
}

int main()
{
	int n;
	int m;
	int num;
	int min;
	vector<int> A;
	vector<int> B;
	vector<int> S; //sum of teeth
	
    cout << "Enter the n amount of teeth: ";
	cin >> n;
	cout << "\nEnter the m amount of teeth: ";
	cin >> m;
	cout << "\n";
	num = max(n, m);
	A.resize(n);
	B.resize(m);

	cout << "Enter n elements of teeth: ";
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	cout << "\n";
	cout << "Enter m elements of teeth: ";
	for (int i = 0; i < m; i++)
	{
		cin >> B[i];
	}
	cout << "\n";

	S.resize(num);
	for (int i = 0; i < num; i++)
	{
		//if there are more m values than n
		if ((i + 1) > n)
		{
			S[i] = B[i];
		}
		//if there are more n values than m
		else if ((i+1) > m)
		{
			S[i] = A[i];
		}
		else
		{
			S[i] = A[i] + B[i];
		}
	}
	min = Minimi(S);
	/*
	cout << "\n\nVector A: \n";
	PrintVectors(n, A);

	cout << "\n\nVector B: \n";
	PrintVectors(m, B);

	cout << "\n\nVector S: \n";
	PrintVectors(num, S);
	cout << "Optimum Teeth: " << min;
	*/
	PrintResults(A, B, min);
	
	return 0;
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
