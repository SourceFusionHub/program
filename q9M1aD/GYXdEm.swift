class TreeNode {
    var value: Int
    var left: TreeNode?
    var right: TreeNode?
    
    init(_ value: Int) {
        self.value = value
    }
}

class BinaryTree {
    var root: TreeNode?

    // Helper function to find the height of a binary tree
    private func height(_ node: TreeNode?) -> Int {
        if node == nil {
            return 0
        }
        return 1 + max(height(node?.left), height(node?.right))
    }

    // Helper function to find the diameter of a binary tree
    private func diameterHelper(_ node: TreeNode?) -> Int {
        if node == nil {
            return 0
        }

        // Calculate the height of the left and right subtrees
        let leftHeight = height(node?.left)
        let rightHeight = height(node?.right)

        // Recursively find the diameter of left and right subtrees
        let leftDiameter = diameterHelper(node?.left)
        let rightDiameter = diameterHelper(node?.right)

        // Return the maximum of three values: left subtree diameter, right subtree diameter,
        // and the longest path that passes through the root
        return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter))
    }

    // Public function to find the diameter of the binary tree
    func diameter() -> Int {
        return diameterHelper(root)
    }
}

// Example usage:
let tree = BinaryTree()
tree.root = TreeNode(1)
tree.root?.left = TreeNode(2)
tree.root?.right = TreeNode(3)
tree.root?.left?.left = TreeNode(4)
tree.root?.left?.right = TreeNode(5)

let treeDiameter = tree.diameter()
print("Diameter of the binary tree is: \(treeDiameter)") // Output: Diameter of the binary tree is: 4
