#include<iostream>

using namespace std;

int vowelCount(char *sptr)
{
	
	int count = 0;

	
	while ((*sptr) != '\0') {

		
		if (*sptr == 'a' || *sptr == 'e' || *sptr == 'i'
			|| *sptr == 'o' || *sptr == 'u') {

			
			count++;
		}

		
		sptr++;
	}

	return count;
}

// Driver Code
int main()
{
	
	char str[] = "Sauptik Mukherjee";

	
	cout << "Vowels in above string: " << vowelCount(str);

	return 0;
}
