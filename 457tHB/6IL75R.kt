class HashSet<E> : Set<E> {

    private val hashTable = HashMap<Int, E>()

    override fun add(element: E): Boolean {
        val hashCode = element.hashCode()
        val existingElement = hashTable[hashCode]
        if (existingElement != null) {
            return false
        }
        hashTable[hashCode] = element
        return true
    }

    override fun contains(element: E): Boolean {
        val hashCode = element.hashCode()
        return hashTable[hashCode] == element
    }

    override fun remove(element: E): Boolean {
        val hashCode = element.hashCode()
        val existingElement = hashTable[hashCode]
        if (existingElement != null) {
            hashTable.remove(hashCode)
            return true
        }
        return false
    }

    override fun isEmpty(): Boolean {
        return hashTable.isEmpty()
    }

    override fun size(): Int {
        return hashTable.size
    }

    override fun iterator(): Iterator<E> {
        return hashTable.values.iterator()
    }
}
