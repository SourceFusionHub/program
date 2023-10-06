bool isSymmetric(List<dynamic> list) {
  int start = 0;
  int end = list.length - 1;

  while (start < end) {
    if (list[start] != list[end]) {
      return false; // Not symmetric
    }
    start++;
    end--;
  }

  return true; // Symmetric
}

void main() {
  List<dynamic> myList = [1, 2, 3, 3, 2, 1]; // Example symmetric list
  // List<dynamic> myList = [1, 2, 3, 4, 5]; // Example non-symmetric list

  if (isSymmetric(myList)) {
    print("The list is symmetric.");
  } else {
    print("The list is not symmetric.");
  }
}
