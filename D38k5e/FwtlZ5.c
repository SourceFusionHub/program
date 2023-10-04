#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int max = 100;

bool isalphaNum(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
        return true;
    }
    else{
        return false;
    }
}

int reverse(char alphaNumArr[] , char reverseArr[] ){
    
    int len = strlen(alphaNumArr);
    int endIndex = len - 1;
    
    for(int i = 0 ; i < len ; i++){
        reverseArr[endIndex - i] =  alphaNumArr[i];
    }
    return 0;
}

bool isPalindrome(char arr[] , char alphaNumArr[]){
    //index for pushing element in 2nd array
    int index = 0;
    //adding alphanum values to 2nd array
    for(int i = 0 ; i < strlen(arr) ; i++){
        if(isalphaNum(arr[i])){
            alphaNumArr[index] = arr[i];
            index++;
        }
    }
    int len = strlen(alphaNumArr);
    char reverseArr[len];
    //reverse 2nd array
    reverse(alphaNumArr , reverseArr);
    
    bool flag = true;
    //check if palindrome
    for(int i = 0 ; i < len ; i++){
        if(alphaNumArr[i] == reverseArr[i]){
            flag = true;
        }
        else{
            flag = false;
            break;
        }
    }
    return flag;
}




int main() {
    char arr[max];
    char alphaNumArr[max];
    
    printf("Enter the string you want to check for palindrome : ");
    scanf("%s" , arr);
    
    bool ans = isPalindrome(arr , alphaNumArr);
    
    if(ans){
        printf("Palindrome");
    }
    else{
        printf("Not palindrome");
    }
    
    
    return 0;
}
