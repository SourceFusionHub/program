<!DOCTYPE html>
<html>
<head>
    <title>Personalized Greeting</title>
</head>
<body>
    <h1>Personalized Greeting</h1>

    <?php
    // Generate a random name for demonstration purposes
    $names = ["Alice", "Bob", "Charlie", "David", "Eva", "Frank"];
    $randomName = $names[array_rand($names)];

    // Display the generated name
    echo "<p>Generated Name: $randomName</p>";

    // Calculate personalized greeting
    $greeting = "Hello, $randomName! Welcome to our website!";
    ?>

    <p><?php echo $greeting; ?></p>
</body>
</html>
