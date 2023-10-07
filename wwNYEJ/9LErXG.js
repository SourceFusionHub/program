class Node {
    constructor(id) {
        this.id = id;
        this.data = {};
    }

    get(key) {
        return this.data[key] ? this.data[key].value : undefined;
    }

    set(key, value, timestamp) {
        if (!this.data[key] || this.data[key].timestamp < timestamp) {
            this.data[key] = { value, timestamp };
        }
    }
}

class DistributedKVStore {
    constructor() {
        this.nodes = [];
    }

    addNode(node) {
        this.nodes.push(node);
    }

    set(key, value) {
        const timestamp = Date.now();
        this.nodes.forEach(node => node.set(key, value, timestamp));
    }

    get(key) {
        let latestValue;
        let latestTimestamp = -1;
        
        for (let node of this.nodes) {
            const data = node.data[key];
            if (data && data.timestamp > latestTimestamp) {
                latestTimestamp = data.timestamp;
                latestValue = data.value;
            }
        }

        return latestValue;
    }
}

const store = new DistributedKVStore();
store.addNode(new Node(1));
store.addNode(new Node(2));
store.addNode(new Node(3));
store.set("name", "HacktoberFest 2023");
console.log(store.get("name"));
