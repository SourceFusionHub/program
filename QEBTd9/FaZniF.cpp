/**
 * @file FaZniF.cpp
 * @author Devdeep
 * @brief
 * @version 0.1
 * @date 2023-10-03
 *
 * @copyright Copyright (c) 2023
 *
 */

// Problem statement
/**Source : Leetcode for problem statement
 *  Minimum Window Substring
Given two strings s and t of lengths m and n respectively, return the minimum window
substring of s such that every character in t (including duplicates) is included in the window.
If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.
*/

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    map<char, int> mp;
    for (auto i : t)
        mp[i]++;
    int x = mp.size();
    int i = 0;
    int l = -1, r = 1e5 + 5;
    for (int j = 0; j < s.size(); ++j)
    {
        mp[s[j]]--;
        if (mp[s[j]] == 0)
            x--;
        while (x == 0)
        {
            if (r - l + 1 > (j - i + 1))
            {
                r = j;
                l = i;
            }
            mp[s[i]]++;
            if (mp[s[i]] == 1)
                x++;
            i++;
        }
    }
    if (l == -1 && r == 1e5 + 5)
        return "";
    return s.substr(l, r - l + 1);
}

int main()
{
    string haystack, needle;
    cin >> haystack >> needle;
    cout << minWindow(haystack, needle) << "\n";
    return 0;
}
