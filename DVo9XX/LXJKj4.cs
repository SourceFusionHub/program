using System;

public class RandomPermutation {
  public static void Main() {
    int[] array = {
      1,
      2,
      3,
      4,
      5
    }; // Input array
    int[] permutation = GenerateRandomPermutation(array);

    Console.WriteLine("Random Permutation:");
    foreach(int element in permutation) {
      Console.Write(element + " ");
    }
  }

  // Function to generate a random permutation of an array
  public static int[] GenerateRandomPermutation(int[] array) {
    Random rand = new Random();
    int[] permutation = (int[]) array.Clone();

    for (int i = 0; i < permutation.Length - 1; i++) {
      int j = rand.Next(i, permutation.Length);
      int temp = permutation[i];
      permutation[i] = permutation[j];
      permutation[j] = temp;
    }

    return permutation;
  }
}
