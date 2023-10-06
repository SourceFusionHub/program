import Foundation

class Node<Key: Hashable, Value> {
    let key: Key
    var value: Value
    var next: Node?
    
    init(key: Key, value: Value) {
        self.key = key
        self.value = value
    }
}

struct HashTable<Key: Hashable, Value> {
    private typealias Element = Node<Key, Value>
    private var buckets: [Element?]
    private let capacity: Int
    
    init(capacity: Int) {
        assert(capacity > 0)
        self.capacity = capacity
        self.buckets = [Element?](repeating: nil, count: capacity)
    }
    
    private func index(for key: Key) -> Int {
        return abs(key.hashValue % capacity)
    }
    
    func retrieve(_ key: Key) -> Value? {
        let index = self.index(for: key)
        var node = buckets[index]
        
        while node != nil {
            if node?.key == key {
                return node?.value
            }
            node = node?.next
        }
        
        return nil
    }
    
    mutating func insert(_ value: Value, for key: Key) {
        let index = self.index(for: key)
        let newNode = Element(key: key, value: value)
        
        if buckets[index] == nil {
            buckets[index] = newNode
        } else {
            var node = buckets[index]
            while node?.next != nil {
                node = node?.next
            }
            node?.next = newNode
        }
    }
}

// Usage:
var hashTable = HashTable<String, Int>(capacity: 5)
hashTable.insert(10, for: "one")
hashTable.insert(20, for: "two")
hashTable.insert(30, for: "three")

print(hashTable.retrieve("one") ?? "Not found")  // Should print 10
print(hashTable.retrieve("two") ?? "Not found")  // Should print 20
print(hashTable.retrieve("four") ?? "Not found") // Should print "Not found"
