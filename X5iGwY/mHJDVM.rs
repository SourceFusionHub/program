use std::collections::HashMap;
use std::thread;
use std::sync::{Arc, Mutex};
use std::time::Duration;

// Define a structure for a DHT node.
struct DHTNode {
    id: u64,
    data: HashMap<String, String>, // Key-value data storage
}

impl DHTNode {
    fn new(id: u64) -> Self {
        DHTNode {
            id,
            data: HashMap::new(),
        }
    }
}

fn main() {
    // Create a network of DHT nodes.
    let network = Arc::new(Mutex::new(Vec::<DHTNode>::new()));

    // Create and start multiple nodes in the network.
    for i in 0..5 {
        let network_clone = network.clone();
        thread::spawn(move || {
            let mut node = DHTNode::new(i);
            // Join the network
            {
                let mut network = network_clone.lock().unwrap();
                network.push(node.clone());
            }
            println!("Node {} joined the network.", node.id);

            // Simulate file sharing
            thread::sleep(Duration::from_secs(2));
            node.data.insert(format!("file{}", i), format!("content{}", i));
            println!("Node {} stored a file.", node.id);

            // Simulate leaving the network
            thread::sleep(Duration::from_secs(2));
            {
                let mut network = network_clone.lock().unwrap();
                if let Some(index) = network.iter().position(|n| n.id == node.id) {
                    network.remove(index);
                }
            }
            println!("Node {} left the network.", node.id);
        });
    }

    // Wait for all threads to finish before exiting.
    thread::sleep(Duration::from_secs(10));
}
