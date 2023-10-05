class Node {
    let value: Int
    var left: Node?
    var right: Node?

    init(value: Int) {
        self.value = value
        self.left = nil
        self.right = nil
    }
}

func preorderTraversal(_ root: Node?) {
    if let currentNode = root {
        print(currentNode.value)  // Visit the current node
        preorderTraversal(currentNode.left)  // Traverse left subtree
        preorderTraversal(currentNode.right) // Traverse right subtree
    }
}

// Example usage:
let root = Node(value: 1)
root.left = Node(value: 2)
root.right = Node(value: 3)
root.left?.left = Node(value: 4)
root.left?.right = Node(value: 5)

print("Preorder traversal result:")
preorderTraversal(root)