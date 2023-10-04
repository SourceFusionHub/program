import Foundation

// Simulated database node
class DatabaseNode {
    var data: [String: String] = [:]

    // Simulate data replication to another node
    func replicateTo(node: DatabaseNode) {
        node.data = self.data
    }
}

// Simulated distributed database with sharding and replication
class DistributedDatabase {
    var nodes: [DatabaseNode] = []

    init(nodeCount: Int) {
        for _ in 0..<nodeCount {
            nodes.append(DatabaseNode())
        }
    }

    // Shard data to a specific node
    func shardData(key: String, value: String) {
        let nodeIndex = abs(key.hashValue) % nodes.count
        let node = nodes[nodeIndex]
        node.data[key] = value

        // Simulate data replication to other nodes
        for otherNode in nodes where otherNode !== node {
            node.replicateTo(node: otherNode)
        }
    }

    // Retrieve data for a key
    func getData(key: String) -> String? {
        let nodeIndex = abs(key.hashValue) % nodes.count
        let node = nodes[nodeIndex]
        return node.data[key]
    }
}

// Example usage
let database = DistributedDatabase(nodeCount: 3)

database.shardData(key: "name", value: "John")
database.shardData(key: "age", value: "30")

print(database.getData(key: "name")) // Output: John
print(database.getData(key: "age"))  // Output: 30
