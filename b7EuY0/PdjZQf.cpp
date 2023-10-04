#include<iostream>
using namespace std;

void reverse(string str, int index, string& ans) {
    //base case
    if(index == str.length())
        return;

    //Head Rec
    reverse(str, index+1, ans);

    //Processing
    ans.push_back(str[index]);
}

int main() {
    string str;
    cout<<"Enter Your string : ";
    cin >> str;
    string ans = "";
    reverse(str, 0, ans);
    cout << ans << endl;
    return 0;
}
