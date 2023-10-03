struct PriorityQueue<T: Comparable> {
    private var elements: [T] = []

    mutating func insert(_ element: T) {
        elements.append(element)
        elements.sort()
    }

    mutating func extractMin() -> T? {
        guard !elements.isEmpty else { return nil }
        return elements.removeFirst()
    }

    func peek() -> T? {
        return elements.first
    }

    var isEmpty: Bool {
        return elements.isEmpty
    }

    var count: Int {
        return elements.count
    }
}

// Example usage:

var priorityQueue = PriorityQueue<Int>()

priorityQueue.insert(10)
priorityQueue.insert(5)
priorityQueue.insert(8)
priorityQueue.insert(3)

print("Priority Queue:")
while !priorityQueue.isEmpty {
    if let minElement = priorityQueue.extractMin() {
        print(minElement)
    }
}
