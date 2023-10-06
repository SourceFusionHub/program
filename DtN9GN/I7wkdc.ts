// TypeScript program to solve Traveling Salesman Problem
// using Branch and Bound.

const N: number = 4;
 
// final_path[] stores the final solution ie, the
// path of the salesman.
let final_path: number[] = Array(N + 1).fill(-1);
  
// visited[] keeps track of the already visited nodes
// in a particular path
let visited: boolean[] = Array(N).fill(false);
 
// Stores the final minimum weight of shortest tour.
let final_res: number = Number.MAX_SAFE_INTEGER;
 
// Function to copy temporary solution to
// the final solution
function copyToFinal(curr_path: number[]): void {
  for (let i = 0; i < N; i++) {
    final_path[i] = curr_path[i];
  }
  final_path[N] = curr_path[0];
}
 
// Function to find the minimum edge cost
// having an end at the vertex i
function firstMin(adj: number[][], i: number): number {
  let min: number = Number.MAX_SAFE_INTEGER;
  for (let k = 0; k < N; k++) {
    if (adj[i][k] < min && i !== k) {
      min = adj[i][k];
    }
  }
  return min;
}
 
// function to find the second minimum edge cost
// having an end at the vertex i
function secondMin(adj: number[][], i: number): number {
  let first: number = Number.MAX_SAFE_INTEGER;
  let second: number = Number.MAX_SAFE_INTEGER;
  for (let j = 0; j < N; j++) {
    if (i == j) {
      continue;
    }
    if (adj[i][j] <= first) {
      second = first;
      first = adj[i][j];
    } else if (adj[i][j] <= second && adj[i][j] !== first) {
      second = adj[i][j];
    }
  }
  return second;
}
 
// function that takes as arguments:
// curr_bound -> lower bound of the root node
// curr_weight-> stores the weight of the path so far
// level-> current level while moving in the search
//         space tree
// curr_path[] -> where the solution is being stored which
//             would later be copied to final_path[]
function TSPRec(
  adj: number[][],
  curr_bound: number,
  curr_weight: number,
  level: number,
  curr_path: number[]
): void {
  // base case is when we have reached level N which
  // means we have covered all the nodes once
  if (level == N) {
    // check if there is an edge from last vertex in
    // path back to the first vertex
    if (adj[curr_path[level - 1]][curr_path[0]] !== 0) {
      // curr_res has the total weight of the
      // solution we got
      let curr_res: number =
        curr_weight + adj[curr_path[level - 1]][curr_path[0]];
      // Update final result and final path if
      // current result is better.
      if (curr_res < final_res) {
        copyToFinal(curr_path);
        final_res = curr_res;
      }
    }
    return;
  }
  // for any other level iterate for all vertices to
  // build the search space tree recursively
  for (let i = 0; i < N; i++) {
    // Consider next vertex if it is not same (diagonal
    // entry in adjacency matrix and not visited
    // already)
    if (adj[curr_path[level - 1]][i] !== 0 && !visited[i]) {
      let temp = curr_bound;
      curr_weight += adj[curr_path[level - 1]][i];
      // different computation of curr_bound for
      // level 2 from the other levels
      if (level == 1) {
        curr_bound -=
          (firstMin(adj, curr_path[level - 1]) +
            firstMin(adj, i)) /
          2;
      } else {
        curr_bound -=
          (secondMin(adj, curr_path[level - 1]) +
            firstMin(adj, i)) /
          2;
      }
      // curr_bound + curr_weight is the actual lower bound
      // for the node that we have arrived on
      // If current lower bound < final_res, we need to explore
      // the node further
      if (curr_bound + curr_weight < final_res) {
        curr_path[level] = i;
        visited[i] = true;
        // call TSPRec for the next level
        TSPRec(adj, curr_bound, curr_weight, level + 1, curr_path);
      }
      // Else we have to prune the node by resetting
      // all changes to curr_weight and curr_bound
      curr_weight -= adj[curr_path[level - 1]][i];
      curr_bound = temp;
      // Also reset the visited array
      visited.fill(false);
      for (var j = 0; j <= level - 1; j++)
        visited[curr_path[j]] = true;
    }
  }
}
 
// This function sets up final_path[]
function TSP(adj: number[][]): void {
  let curr_path: number[] = Array(N + 1).fill(-1);
  // Calculate initial lower bound for the root node
  // using the formula 1/2 * (sum of first min +
  // second min) for all edges.
  // Also initialize the curr_path and visited array
  let curr_bound: number = 0;
  visited.fill(false);
  // compute initial bound
  for (let i = 0; i < N; i++) {
    curr_bound += firstMin(adj, i) + secondMin(adj, i);
  }
  // Rounding off the lower bound to an integer
  curr_bound = curr_bound == 1 ? curr_bound / 2 + 1 : curr_bound / 2;
  // We start at vertex 1 so the first vertex
  // in curr_path[] is 0
  visited[0] = true;
  curr_path[0] = 0;
  // Call to TSPRec for curr_weight equal to
  // 0 and level 1
  TSPRec(adj, curr_bound, 0, 1, curr_path);
}
 
// Adjacency matrix for the given graph
let adj: number[][] = [
  [0, 10, 15, 20],
  [10, 0, 35, 25],
  [15, 35, 0, 30],
  [20, 25, 30, 0]
];
 
TSP(adj);
 
console.log(`Minimum cost:${final_res}`);
console.log(`Path Taken:${final_path.join(" ")}`);
