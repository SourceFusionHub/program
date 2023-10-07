#include <iostream>
using namespace std;
 
int main()
{
        //Initializing variable.
	char str[30];
	int i,length=0;
	//Accepting input.
	cout<<"Enter the string:";
	gets(str);
	//Initializing for loop.
	for(i=0;str[i]!='\0';++i)
	{
	length++;//Counting the length.
	}
	
	cout<<"Length of the string is:"<<length<<endl;
 
	return 0;
}
