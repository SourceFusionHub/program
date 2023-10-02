//function to reverse a string
public static string Reverse(string Input) 
{ 
    char[] charArray = Input.ToCharArray(); 
    string rev = String.Empty; 
    for(int i = charArray.Length - 1; i > -1; i--){ 
        rev += charArray[i]; 
    }
    return rev;
} 
