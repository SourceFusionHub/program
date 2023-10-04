package main

import (
	"fmt"
	"log"
	"net/http"
	"github.com/tidwall/gjson"
	"github.com/go-resty/resty/v2"
)

const apiKey = "YOUR_OPENWEATHERMAP_API_KEY"

func getWeather(city string) (string, error) {
	client := resty.New()

	resp, err := client.R().
		SetQueryParams(map[string]string{
			"q":     city,
			"appid": apiKey,
		}).
		Get("https://api.openweathermap.org/data/2.5/weather")

	if err != nil {
		return "", err
	}

	if resp.StatusCode() != http.StatusOK {
		return "", fmt.Errorf("Failed to fetch weather data: %s", resp.Status())
	}

	temperature := gjson.Get(resp.Body(), "main.temp").Float()
	description := gjson.Get(resp.Body(), "weather.0.description").String()

	return fmt.Sprintf("Temperature: %.2f°C\nDescription: %s", temperature-273.15, description), nil
}

func main() {
	var city string
	fmt.Print("Enter city name: ")
	fmt.Scanln(&city)

	weatherData, err := getWeather(city)
	if err != nil {
		log.Fatalf("Error: %v", err)
	}

	fmt.Println("\nWeather Conditions:")
	fmt.Println(weatherData)
}
