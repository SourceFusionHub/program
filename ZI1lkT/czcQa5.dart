List<int> removeDuplicates(List<int> inputList) {
  // Create an empty Set to store unique elements
  Set<int> uniqueElements = {};

  // Create a new list to store the result without duplicates
  List<int> result = [];

  // Iterate through the inputList
  for (int number in inputList) {
    // If the number is not already in the Set, add it to the result list and Set
    if (!uniqueElements.contains(number)) {
      result.add(number);
      uniqueElements.add(number);
    }
  }

  return result;
}

