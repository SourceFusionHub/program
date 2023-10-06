# Coin Change Problem
class CountChangeProblem:
  def solution(self, coins, sum, n, coins_sum):
    # Checking for base case
    if (sum == 0):
        coins_sum[n][sum] = 1
        return coins_sum[n][sum]
  
    # If number of coins is 0 or sum is less than 0 then there is no way to make the sum.
    if (n == 0 or sum < 0):
        return 0
    
    # If the subproblem is previously calculated then simply return the result
    if (coins_sum[n][sum] != -1):
        return coins_sum[n][sum]
    
    # Two options for the current coin
    # include current coin
    coin_included_sum = self.solution(coins, sum - coins[n - 1], n, coins_sum)
    # exclude current coin
    coin_excluded_sum = self.solution(coins, sum, n - 1, coins_sum)

    coins_sum[n][sum] = coin_included_sum + coin_excluded_sum
  
    return coins_sum[n][sum]
  

def main():
  # Data for test case
  total = 10
  coins = [2, 4, 5, 6]
  n = len(coins)
  coins_sum = [[-1 for i in range(0, total+1)] for j in range(0, n+1)]
  # Initiating the solution
  problem = CountChangeProblem()
  answer = problem.solution(coins, total, n, coins_sum)
  print(answer)

if __name__ == '__main__':
  main()