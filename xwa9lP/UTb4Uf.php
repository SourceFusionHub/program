<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Weather Forecast</title>
</head>
<body>
    <h1>Weather Forecast</h1>
    <form method="POST">
        <label for="city">Enter City:</label>
        <input type="text" id="city" name="city" required>
        <button type="submit">Get Forecast</button>
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] === "POST") {
        $city = $_POST["city"];
        $apiKey = "YOUR_API_KEY"; // Replace with your actual API key

        $apiUrl = "http://api.openweathermap.org/data/2.5/weather?q=$city&appid=$apiKey";

        $response = file_get_contents($apiUrl);
        $data = json_decode($response);

        if ($data) {
            $weather = $data->weather[0]->description;
            $tempKelvin = $data->main->temp;
            $tempCelsius = $tempKelvin - 273.15;
            $tempFahrenheit = ($tempCelsius * 9 / 5) + 32;

            echo "<h2>Weather in $city:</h2>";
            echo "<p><strong>Condition:</strong> $weather</p>";
            echo "<p><strong>Temperature:</strong> $tempCelsius°C ($tempFahrenheit°F)</p>";
        } else {
            echo "<p>Unable to fetch weather data for $city.</p>";
        }
    }
    ?>
</body>
</html>
