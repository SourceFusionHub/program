// program that checks if a string is a valid URL
package main

import (
	"fmt"
	"regexp"
)

func isValidURL(url string) bool {
	pattern := regexp.MustCompile(`^(https?://)?([a-z\d-]+\.)*[a-z\d-]+(\.[a-z]+)+(/[\w\d-./?%&=]*)?$`)
	return pattern.MatchString(url)
}

func main() {
	url1 := "https://go.dev/"
	fmt.Println(isValidURL(url1)) // Output: true

	url2 := "http://go.dev/"
	fmt.Println(isValidURL(url2)) // Output: false
}
