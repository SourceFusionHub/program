// C++ program to count the number of occurrence
// of a word in the given string
#include <bits/stdc++.h>
using namespace std;

int countOccurrences(string str, string word)
{
	// Split the string into words
	stringstream ss(str);
	string token;
	vector<string> wordslist;

	while (ss >> token) {
		wordslist.push_back(token);
	}

	// Count the number of occurrences of the given word
	int count = 0;
	for (int i = 0; i < wordslist.size(); i++) {
		if (wordslist[i] == word) {
			count++;
		}
	}

	return count;
}

// Driver code
int main()
{
	string str = "457ayan "
				"for ayan";
	string word = "protal ayan";
	cout << countOccurrences(str, word);
	return 0;
}
