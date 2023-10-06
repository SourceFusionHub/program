import java.util.LinkedHashMap;
import java.util.Map;

public class DistributedCache<K, V> {
    private final int maxSize;
    private final Map<K, V> cache;

    public DistributedCache(int maxSize) {
        this.maxSize = maxSize;
        this.cache = new LinkedHashMap<>(maxSize, 0.75f, true);
    }

    public synchronized void put(K key, V value) {
        if (cache.size() >= maxSize) {
            evict();
        }
        cache.put(key, value);
    }

    public synchronized V get(K key) {
        return cache.get(key);
    }

    private void evict() {
        if (cache.size() >= maxSize) {
            K oldestKey = cache.keySet().iterator().next();
            cache.remove(oldestKey);
        }
    }

    public synchronized void clear() {
        cache.clear();
    }

    public synchronized int size() {
        return cache.size();
    }

    public static void main(String[] args) {
        DistributedCache<String, Integer> cache = new DistributedCache<>(3);

        cache.put("A", 1);
        cache.put("B", 2);
        cache.put("C", 3);

        System.out.println(cache.get("A")); // 1 (A is now the most recently used)
        System.out.println(cache.get("B")); // 2 (B is now the most recently used)

        cache.put("D", 4); // Evicts the least recently used item "C"

        System.out.println(cache.get("C")); // null (C was evicted)
    }
}
