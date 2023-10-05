class TreeNode {
    var val: Int
    var left: TreeNode?
    var right: TreeNode?
    
    init(_ val: Int) {
        self.val = val
        self.left = nil
        self.right = nil
    }
}

func findLCA(_ root: TreeNode?, _ p: TreeNode, _ q: TreeNode) -> TreeNode? {
    if root == nil {
        return nil
    }
    
    if root === p || root === q {
        return root
    }
    
    let leftLCA = findLCA(root?.left, p, q)
    let rightLCA = findLCA(root?.right, p, q)
    
    if leftLCA != nil && rightLCA != nil {
        return root
    }
    
    if leftLCA != nil {
        return leftLCA
    }
    
    return rightLCA
}

// Helper function to create a binary tree
func createBinaryTree() -> TreeNode {
    let root = TreeNode(3)
    root.left = TreeNode(5)
    root.right = TreeNode(1)
    root.left?.left = TreeNode(6)
    root.left?.right = TreeNode(2)
    root.right?.left = TreeNode(0)
    root.right?.right = TreeNode(8)
    root.left?.right?.left = TreeNode(7)
    root.left?.right?.right = TreeNode(4)
    
    return root
}

let root = createBinaryTree()
let node1 = root.left!.left! // Node with value 6
let node2 = root.left!.right!.right! // Node with value 4

if let lca = findLCA(root, node1, node2) {
    print("Lowest Common Ancestor: \(lca.val)") // Expected output: 5
} else {
    print("LCA not found")
}
