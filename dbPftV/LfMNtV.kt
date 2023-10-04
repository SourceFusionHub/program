data class TreeNode<T>(
    val value: T,
    var left: TreeNode<T>? = null,
    var right: TreeNode<T>? = null
)

fun <T> findLCA(root: TreeNode<T>?, node1: T, node2: T): TreeNode<T>? {
    if (root == null) return null

    if (root.value == node1 || root.value == node2) return root

    val leftLCA = findLCA(root.left, node1, node2)
    val rightLCA = findLCA(root.right, node1, node2)

    if (leftLCA != null && rightLCA != null) return root

    return leftLCA ?: rightLCA
}
