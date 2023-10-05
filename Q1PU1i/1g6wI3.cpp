#include<bits/stdc++.h>

using namespace std;

// Function to find the common prefix of two strings
string commonPrefix(string str1, string str2) {
    string result = "";
    int len1 = str1.length();
    int len2 = str2.length();
    int i = 0, j = 0;

    while (i < len1 && j < len2) {
        if (str1[i] != str2[j]) {
            break;
        }
        result += str1[i];
        i++;
        j++;
    }

    return result;
}

// Function to find the longest common prefix using binary search
string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
        return "";
    }

    int minLen = INT_MAX;
    for (const string& str : strs) {
        minLen = min(minLen, static_cast<int>(str.length()));
    }

    int low = 1;
    int high = minLen;
    string result = "";

    while (low <= high) {
        int mid = (low + high) / 2;
        string prefix = strs[0].substr(0, mid);

        bool valid = true;
        for (int i = 1; i < strs.size(); i++) {
            if (prefix != strs[i].substr(0, mid)) {
                valid = false;
                break;
            }
        }

        if (valid) {
            result = prefix;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    vector<string> strs = {"flower", "flour", "flight"};
    string common = longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << common << endl;
    return 0;
}
