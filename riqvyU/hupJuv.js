// Javascript program to find shortest path 
// from a given source vertex 's' to
// a given destination vertex 't'. Expected time complexity
// is O(V+E).


// This class represents a directed graph using adjacency
// list representation
class Graph
{
	constructor(V)
	{
		this.V = V;
		this.adj = new Array(2 * V);
		this.level = 0;
		for (let i = 0; i < 2 * V; i++)
			this.adj[i] = [];
	}

	// adds an edge
	addEdge(v, w, weight)
	{
		// split all edges of weight 2 into two
		// edges of weight 1 each. The intermediate
		// vertex number is maximum vertex number + 1,
		// that is V.
		if (weight == 2)
		{
			this.adj[v].push(v + this.V);
			this.adj[v + this.V].push(w);
		} else // Weight is 1
			this.adj[v].push(w); // Add w to v's list.
	}

	// print shortest path from a source vertex 's' to
	// destination vertex 'd'.
	printShortestPath(parent, s, d)
	{
		this.level = 0;

		// If we reached root of shortest path tree
		if (parent[s] == -1)
		{
			console.log("Shortest Path between " + s + " and " + d + " is " + s + " "); 
			return this.level;
		}

		this.printShortestPath(parent, parent[s], d);

		this.level++;
		if (s < this.V)
			console.log(s + " ");

		return this.level;
	}

	// finds shortest path from source vertex 's' to
	// destination vertex 'd'.

	// This function mainly does BFS and prints the
	// shortest path from src to dest. It is assumed
	// that weight of every edge is 1
	findShortestPath(src, dest)
	{
		let visited = new Array(2 * this.V);
		let parent = new Array(2 * this.V);

		// Initialize parent[] and visited[]
		for (let i = 0; i < 2 * this.V; i++)
		{
			visited[i] = false;
			parent[i] = -1;
		}

		// Create a queue for BFS
		let queue = [];

		// Mark the current node as visited and enqueue it
		visited[src] = true;
		queue.push(src);

		while (queue.length > 0)
		{

			// Dequeue a vertex from queue and print it
			let s = queue[0];

			if (s == dest)
				return this.printShortestPath(parent, s, dest);
			queue.shift();

			// Get all adjacent vertices of the dequeued vertex s
			// If a adjacent has not been visited, then mark it
			// visited and enqueue it
			this.adj[s].forEach(i => {
				if (!visited[i]){
					visited[i] = true;
					queue.push(i);
					parent[i] = s;
				}
			});
		}
		return 0;
	}
}

// Driver Code
// Create a graph given in the above diagram
let V = 4;
let g = new Graph(V);
g.addEdge(0, 1, 2);
g.addEdge(0, 2, 2);
g.addEdge(1, 2, 1);
g.addEdge(1, 3, 1);
g.addEdge(2, 0, 1);
g.addEdge(2, 3, 2);
g.addEdge(3, 3, 2);

let src = 0, dest = 3;
console.log("Shortest Distance between " + src + " and " + dest + " is " + 
					g.findShortestPath(src, dest));



