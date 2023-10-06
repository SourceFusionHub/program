String findLongestCommonSubstring(String str1, String str2) {
  var longestCommonSuffix = List.generate(str1.length+1, 
                           (_) => List.generate(str2.length+1, (_) => 0, growable: false),
                           growable: false);
  
  int row=-1, col=-1, lcsLength=0;
  
  // Find length of longest common substring
  for (int i=1; i<=str1.length; i++) {
    for (int j=1; j<=str2.length; j++) {
      if (str1[i-1] == str2[j-1]) {
        longestCommonSuffix[i][j] = longestCommonSuffix[i-1][j-1] + 1;
        if (lcsLength < longestCommonSuffix[i][j]) {
          lcsLength = longestCommonSuffix[i][j];
          row = i;
          col = j;
        }
      }
    }
  }
  
  if(lcsLength == 0)
    return "";
  
  
  // Find longest common substring
  var longestCommonSubstringList = List.filled(lcsLength, "");
  while(longestCommonSuffix[row][col] != 0) {
    longestCommonSubstringList[--lcsLength] += str1[row-1];
    row--;
    col--;
  }
  
  String longestCommonSubstring = longestCommonSubstringList.join("");
  
  return longestCommonSubstring;
}


void main() {
  String s1 = "coding is fun";
  String s2 = "we need to enjoy coding";
  
  String lcs = findLongestCommonSubstring(s1, s2);
  if(lcs == "")
    print("No common substring!");
  else
    print("Longest Common Substring => " + lcs);
}
