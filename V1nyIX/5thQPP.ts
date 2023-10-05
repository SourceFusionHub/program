function knapsack(weights: number[], values: number[], capacity: number): number {
  const n = weights.length;
  const dp: number[][] = [];

  // Initialize the dp array with zeros
  for (let i = 0; i <= n; i++) {
    dp[i] = new Array(capacity + 1).fill(0);
  }

  // Fill the dp array using dynamic programming
  for (let i = 1; i <= n; i++) {
    for (let w = 1; w <= capacity; w++) {
      if (weights[i - 1] <= w) {
        dp[i][w] = Math.max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
      } else {
        dp[i][w] = dp[i - 1][w];
      }
    }
  }

  // The result is stored in dp[n][capacity]
  return dp[n][capacity];
}