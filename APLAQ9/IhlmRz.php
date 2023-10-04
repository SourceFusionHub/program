<!DOCTYPE html>
<html>
<head>
    <title>Personalized Greeting</title>
</head>
<body>
    <h1>Personalized Greeting</h1>

    <?php
    // Check if the form is submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Get user input from the form
        $name = $_POST["name"];
        
        // Display personalized greeting
        echo "<p>Hello, $name! Welcome to our website!</p>";
    }
    ?>

    <form method="post" action="<?php echo $_SERVER["PHP_SELF"]; ?>">
        <label for="name">Enter your name:</label>
        <input type="text" id="name" name="name" required>
        <button type="submit">Submit</button>
    </form>
</body>
</html>
