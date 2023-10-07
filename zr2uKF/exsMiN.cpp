#include <bits/stdc++.h>
using namespace std;

string DecimalToBinary(int num)
{
	string str;
	while(num){
	if(num & 1)
		str+='1';
	else
		str+='0';
	num>>=1;
	} 
	return str;
}

void reverse(string str)
{
for(int i=str.size()-1 ; i>=0 ; i--)
cout<< str[i]; 
}

int main() {
	int num = 59;
	cout<< "Binary of num 59 is: ";
	reverse( DecimalToBinary(num) );
	return 0;
}
