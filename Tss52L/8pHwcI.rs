use std::collections::HashMap;

#[derive(Debug)]
struct MenuItem {
    name: String,
    price: f64,
}

#[derive(Debug)]
struct OrderItem {
    menu_item: MenuItem,
    quantity: u32,
}

#[derive(Debug)]
struct Bill {
    order_items: Vec<OrderItem>,
    total_price: f64,
}

struct Restaurant {
    menu: HashMap<String, MenuItem>,
    orders: Vec<Order>,
}

impl Restaurant {
    fn new() -> Self {
        Self {
            menu: HashMap::new(),
            orders: Vec::new(),
        }
    }

    fn add_menu_item(&mut self, menu_item: MenuItem) {
        self.menu.insert(menu_item.name.clone(), menu_item);
    }

    fn place_order(&mut self, order_items: Vec<OrderItem>) {
        let order = Order { order_items };
        self.orders.push(order);
    }

    fn generate_bill(&self, order_id: usize) -> Bill {
        let order = &self.orders[order_id];
        let total_price = order.order_items.iter().map(|item| item.menu_item.price * item.quantity).sum();

        Bill {
            order_items: order.order_items.clone(),
            total_price,
        }
    }
}

#[derive(Debug)]
struct Order {
    order_items: Vec<OrderItem>,
}

fn main() {
    let mut restaurant = Restaurant::new();

    // Add menu items
    restaurant.add_menu_item(MenuItem { name: "Vadapav".to_string(), price: 20.0 });
    restaurant.add_menu_item(MenuItem { name: "Sandwich".to_string(), price: 30.0 });
    restaurant.add_menu_item(MenuItem { name: "Burger".to_string(), price: 40.0 });
    restaurant.add_menu_item(MenuItem { name: "Pizza".to_string(), price: 50.0 });

    // Place an order
    let order_items = vec![
        OrderItem { menu_item: restaurant.menu["Vadapav"].clone(), quantity: 1 },
        OrderItem { menu_item: restaurant.menu["Sandwich"].clone(), quantity: 2 },
    ];
    restaurant.place_order(order_items);

    // Generate the bill
    let bill = restaurant.generate_bill(0);

    println!("{:?}", bill);
}
