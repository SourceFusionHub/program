use std::collections::{BinaryHeap, HashMap};
use std::cmp::Ordering;

#[derive(Debug, PartialEq, Eq, Hash, Clone, Copy)]
struct Vertex {
    id: usize,
}

#[derive(Debug, PartialEq, Eq, Clone, Copy)]
struct Edge {
    target: Vertex,
    cost: usize,
}

impl PartialOrd for Edge {
    fn partial_cmp(&self, other: &Edge) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl Ord for Edge {
    fn cmp(&self, other: &Edge) -> Ordering {
        other.cost.cmp(&self.cost)
    }
}

struct Graph {
    vertices: Vec<Vertex>,
    edges: HashMap<Vertex, Vec<Edge>>,
}

impl Graph {
    fn new() -> Self {
        Graph {
            vertices: Vec::new(),
            edges: HashMap::new(),
        }
    }

    fn add_vertex(&mut self, vertex: Vertex) {
        self.vertices.push(vertex);
        self.edges.insert(vertex, Vec::new());
    }

    fn add_edge(&mut self, source: Vertex, target: Vertex, cost: usize) {
        self.edges.get_mut(&source).unwrap().push(Edge { target, cost });
    }

    fn a_star(&self, start: Vertex, goal: Vertex) -> Option<Vec<Vertex>> {
        let mut open_set: BinaryHeap<Edge> = BinaryHeap::new();
        let mut came_from: HashMap<Vertex, Vertex> = HashMap::new();
        let mut g_score: HashMap<Vertex, usize> = self.vertices.iter().map(|&v| (v, usize::max_value())).collect();
        let mut f_score: HashMap<Vertex, usize> = self.vertices.iter().map(|&v| (v, usize::max_value())).collect();

        g_score.insert(start, 0);
        f_score.insert(start, Self::heuristic(start, goal));
        open_set.push(Edge { target: start, cost: f_score[&start] });

        while let Some(current_edge) = open_set.pop() {
            let current_vertex = current_edge.target;

            if current_vertex == goal {
                return Some(Self::reconstruct_path(came_from, current_vertex));
            }

            for edge in &self.edges[&current_vertex] {
                let neighbor = edge.target;
                let tentative_g_score = g_score[&current_vertex] + edge.cost;

                if tentative_g_score < g_score[&neighbor] {
                    came_from.insert(neighbor, current_vertex);
                    g_score.insert(neighbor, tentative_g_score);
                    f_score.insert(neighbor, tentative_g_score + Self::heuristic(neighbor, goal));
                    open_set.push(Edge { target: neighbor, cost: f_score[&neighbor] });
                }
            }
        }

        None
    }

    fn heuristic(vertex: Vertex, goal: Vertex) -> usize {
        // Replace this with an appropriate heuristic function for your problem.
        // For example, you can use the Euclidean distance for a grid-based graph.
        0
    }

    fn reconstruct_path(came_from: HashMap<Vertex, Vertex>, mut current: Vertex) -> Vec<Vertex> {
        let mut path = vec![current];
        while let Some(&prev) = came_from.get(&current) {
            path.push(prev);
            current = prev;
        }
        path.reverse();
        path
    }
}

fn main() {
    let mut graph = Graph::new();

    let a = Vertex { id: 0 };
    let b = Vertex { id: 1 };
    let c = Vertex { id: 2 };
    let d = Vertex { id: 3 };

    graph.add_vertex(a);
    graph.add_vertex(b);
    graph.add_vertex(c);
    graph.add_vertex(d);

    graph.add_edge(a, b, 1);
    graph.add_edge(b, c, 2);
    graph.add_edge(c, d, 1);
    graph.add_edge(a, c, 4);
    graph.add_edge(b, d, 3);

    let start = a;
    let goal = d;

    if let Some(shortest_path) = graph.a_star(start, goal) {
        println!("Shortest Path from {:?} to {:?}: {:?}", start, goal, shortest_path);
    } else {
        println!("No path found from {:?} to {:?}", start, goal);
    }
}
