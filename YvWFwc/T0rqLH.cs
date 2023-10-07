using System; 
  
public class GCD { 
      
    static int gcd(int a, int b) 
    { 
        if (a == 0) 
            return b; 
        return gcd(b % a, a); 
    } 
  
    static int findGCD(int[] arr, int n) 
    { 
        int result = arr[0]; 
        for (int i = 1; i < n; i++){ 
            result = gcd(arr[i], result); 
  
            if(result == 1) 
            { 
               return 1; 
            } 
        } 
  
        return result; 
    } 
      
    public static void Main() 
    { 
        int[] arr = { 2, 4, 6, 8, 16 }; 
        int n = arr.Length; 
        Console.Write(findGCD(arr, n)); 
    } 
} 
