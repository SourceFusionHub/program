<?php

function generateRandomUsername() {
    $adjectives = ['Quick', 'Lazy', 'Shiny', 'Fluffy', 'Bright', 'Dark', 'Tall', 'Short', 'Happy', 'Sad'];
    $nouns = ['Cat', 'Dog', 'Bird', 'Fish', 'Lion', 'Tiger', 'Bear', 'Shark', 'Eagle', 'Elephant'];
    
    $randomAdjective = $adjectives[array_rand($adjectives)];
    $randomNoun = $nouns[array_rand($nouns)];
    $randomNumber = rand(100, 999);
    
    return $randomAdjective . $randomNoun . $randomNumber;
}

// Usage:
$username = generateRandomUsername();
echo $username;

?>
