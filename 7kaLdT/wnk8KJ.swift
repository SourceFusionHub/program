import Foundation
class Node<Key: Hashable, Value> {
    let key: Key
    var value: Value
    var children: [Node]
    init(key: Key, value: Value, children: [Node] = []) {
        self.key = key
        self.value = value
        self.children = children
    }
}
class ConcurrentHashTable<Key: Hashable, Value> {
    private var root: Node<Key, Value>?
    func get(key: Key) -> Value? {
        guard let root = root else {
            return nil
        }
        var node = root
        while let child = node.children.first(where: { $0.key == key }) {
            node = child
        }
        return node.value
    }
    func put(key: Key, value: Value) {
        guard let root = root else {
            self.root = Node(key: key, value: value)
            return
        }
        var node = root
        while let child = node.children.first(where: { $0.key == key }) {
            node = child
        }
        node.value = value
    }
    func remove(key: Key) {
        guard let root = root else {
            return
        }
        var node = root
        while let child = node.children.first(where: { $0.key == key }) {
            node = child
        }
        node.children.removeAll(where: { $0.key == key })
    }
}
