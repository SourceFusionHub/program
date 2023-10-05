int countOccurrences(String sentence, String word) {
  final wordsList = sentence.split(RegExp(r'\s+')); // Split by spaces
  int count = 0;
  
  for (String w in wordsList) {
    if (w == word) {
      count++;
    }
  }
  
  return count;
}

void main() {
  String sentence = "457ayan for ayan";
  String word = "ayan";
  int occurrences = countOccurrences(sentence, word);
  
  print("The word '$word' occurs $occurrences times in the sentence.");
}
