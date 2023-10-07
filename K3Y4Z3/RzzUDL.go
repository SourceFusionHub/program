package main

import (
	"fmt"
	"sync"
)

type Inventory struct {
	mu        sync.Mutex
	products  map[int]Product
}

type Product struct {
	ID       int
	Name     string
	Quantity int
}

func NewInventory() *Inventory {
	return &Inventory{
		products: make(map[int]Product),
	}
}

func (inv *Inventory) AddProduct(id int, name string, quantity int) {
	inv.mu.Lock()
	defer inv.mu.Unlock()

	if _, exists := inv.products[id]; exists {
		inv.products[id].Quantity += quantity
	} else {
		inv.products[id] = Product{
			ID:       id,
			Name:     name,
			Quantity: quantity,
		}
	}
}

func (inv *Inventory) RemoveProduct(id int, quantity int) bool {
	inv.mu.Lock()
	defer inv.mu.Unlock()

	product, exists := inv.products[id]
	if !exists {
		fmt.Println("Product not found in inventory.")
		return false
	}

	if product.Quantity >= quantity {
		inv.products[id].Quantity -= quantity
		return true
	}

	fmt.Println("Insufficient quantity in inventory.")
	return false
}

func (inv *Inventory) CheckInventory(id int) int {
	inv.mu.Lock()
	defer inv.mu.Unlock()

	product, exists := inv.products[id]
	if !exists {
		return 0
	}
	return product.Quantity
}

func (inv *Inventory) DisplayInventory() {
	inv.mu.Lock()
	defer inv.mu.Unlock()

	fmt.Println("Current Inventory:")
	for _, product := range inv.products {
		fmt.Printf("Product ID: %d, Product Name: %s, Quantity: %d\n", product.ID, product.Name, product.Quantity)
	}
}

func main() {
	// Create an inventory
	inventory := NewInventory()

	// Add products to the inventory
	inventory.AddProduct(1, "Product A", 100)
	inventory.AddProduct(2, "Product B", 50)

	// Display the initial inventory
	inventory.DisplayInventory()

	// Simulate real-time updates
	inventory.RemoveProduct(1, 30)
	inventory.RemoveProduct(2, 60)

	// Display the updated inventory
	inventory.DisplayInventory()
}
