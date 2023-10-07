import math

def min_squares_sum(n):
  
    dp = [float('inf')] * (n + 1)
    
  
    dp[0] = 0
    
   
    for i in range(1, n + 1):
        j = 1
        while j * j <= i:
            dp[i] = min(dp[i], dp[i - j * j] + 1)
            j += 1
    
    return dp[n]


number = int(input("Enter a number: "))
result = min_squares_sum(number)

print(f"The minimum number of squares to sum up to {number} is {result}.")
