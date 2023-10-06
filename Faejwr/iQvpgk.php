<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Guestbook</title>
</head>
<body>
    <h1>Guestbook</h1>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $name = $_POST["name"];
        $comment = $_POST["comment"];

        if (!empty($name) && !empty($comment)) {
            // Store the comment in a text file (append mode)
            $file = fopen("comments.txt", "a");

            if ($file) {
                $timestamp = date("Y-m-d H:i:s");
                $data = "$timestamp - Name: $name, Comment: $comment\n";

                fwrite($file, $data);
                fclose($file);
                echo "<p>Comment submitted successfully!</p>";
            }
        } else {
            echo "<p>Please fill in both Name and Comment fields.</p>";
        }
    }
    ?>

    <form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
        <label for="name">Name:</label>
        <input type="text" id="name" name="name" required><br>

        <label for="comment">Comment:</label><br>
        <textarea id="comment" name="comment" rows="4" cols="50" required></textarea><br>

        <input type="submit" value="Submit">
    </form>

    <h2>Comments</h2>
    <ul>
        <?php
        // Read and display comments from the text file
        $comments = file("comments.txt");
        foreach ($comments as $comment) {
            echo "<li>" . htmlspecialchars($comment) . "</li>";
        }
        ?>
    </ul>
</body>
</html>
