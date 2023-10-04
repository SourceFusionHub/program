package main

import (
	"fmt"
	"net/http"
)

// CDN struct represents the CDN server.
type CDN struct {
	content map[string][]byte // Simulated content store
}

// NewCDN creates a new CDN instance.
func NewCDN() *CDN {
	return &CDN{
		content: make(map[string][]byte),
	}
}

// AddContent adds content to the CDN.
func (c *CDN) AddContent(path string, data []byte) {
	c.content[path] = data
}

// ServeHTTP serves content to clients.
func (c *CDN) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	path := r.URL.Path

	// Check if the content exists in the CDN.
	content, ok := c.content[path]
	if !ok {
		http.NotFound(w, r)
		return
	}

	// Serve the content.
	w.Header().Set("Content-Type", "text/html") // Set the appropriate content type.
	w.Write(content)
}

func main() {
	cdn := NewCDN()

	// Add some content to the CDN (you can replace this with your actual content).
	cdn.AddContent("/index.html", []byte("<html><body><h1>Hello, CDN!</h1></body></html>"))
	cdn.AddContent("/styles.css", []byte("body { background-color: lightgray; }"))

	// Start the CDN server.
	port := 8080
	serverAddr := fmt.Sprintf(":%d", port)
	fmt.Printf("CDN server listening on port %d...\n", port)
	http.Handle("/", cdn)
	http.ListenAndServe(serverAddr, nil)
}
