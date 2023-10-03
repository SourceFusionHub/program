<?php
// Array of quotes
$quotes = [
    "The only way to do great work is to love what you do. - Steve Jobs",
    "In the midst of chaos, there is also opportunity. - Sun Tzu",
    "The best way to predict the future is to create it. - Peter Drucker",
    "Success is not final, failure is not fatal: It is the courage to continue that counts. - Winston Churchill",
    "Don't watch the clock; do what it does. Keep going. - Sam Levenson"
];

// Generate a random index
$randomIndex = rand(0, count($quotes) - 1);

// Get the random quote
$randomQuote = $quotes[$randomIndex];

// Display the random quote
echo $randomQuote;
?>
