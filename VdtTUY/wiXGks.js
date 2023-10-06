function myFunc(graph) {
    const numCities = graph.length;
    const numCombinations = 1 << numCities;
    const dp = new Array(numCombinations).fill(null).map(() => new Array(numCities).fill(Number.MAX_SAFE_INTEGER));
  

    dp[1][0] = 0;
  
    for (let mask = 1; mask < numCombinations; mask += 2) {
      for (let u = 1; u < numCities; u++) {
        if ((mask & (1 << u)) !== 0) {
          for (let v = 0; v < numCities; v++) {
            if (u !== v && (mask & (1 << v)) !== 0) {
              dp[mask][u] = Math.min(dp[mask][u], dp[mask ^ (1 << u)][v] + graph[v][u]);
            }
          }
        }
      }
    }
  

    const mask = numCombinations - 1;
    let u = 0;
    let minCost = Number.MAX_SAFE_INTEGER;
    for (let v = 1; v < numCities; v++) {
      if (dp[mask][v] + graph[v][u] < minCost) {
        minCost = dp[mask][v] + graph[v][u];
        u = v;
      }
    }
  

    const path = [u];
    maskWithoutU = mask ^ (1 << u);
  
    while (maskWithoutU !== 0) {
      for (let v = 0; v < numCities; v++) {
        if ((maskWithoutU & (1 << v)) !== 0 && dp[maskWithoutU][u] + graph[u][v] === dp[mask][u]) {
          path.push(v);
          maskWithoutU ^= (1 << v);
          u = v;
          break;
        }
      }
    }
 
    path.push(path[0]);
  
    return { path, cost: minCost };
  }
  

  const graph = [
    [0, 29, 20, 21],
    [29, 0, 15, 17],
    [20, 15, 0, 28],
    [21, 17, 28, 0]
  ];
  
  const result = myFunc(graph);
  console.log('Optimal Path:', result.path); 
  console.log('Optimal Cost:', result.cost); 
  
