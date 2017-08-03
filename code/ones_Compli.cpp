#include <iostream>
using namespace std;

int main()
{
	int number;
	cout << "Enter the number to be reversed: ";
	cin >> number;
	int temp = number;

	// find the count of bits
	int count=1;
	while(temp>1)
	{
		temp = temp >> 1;
		count++;
	}

	// Do xor and get the string
	int xorr = 1; 
	temp=number;
	for(int i=0; i<count; i++)
	{
		temp = temp^xorr;
		xorr = xorr << 1;
	}

	cout <<"The reversal of "<< number <<" is: "<< temp<<endl;
	
	getchar();
	return 0;
}
