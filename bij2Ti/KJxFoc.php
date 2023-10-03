<?php
$date1 = "2023-10-10";
$date2 = "2023-10-03";

// Convert date strings to DateTime objects
$datetime1 = new DateTime($date1);
$datetime2 = new DateTime($date2);

// Calculate the difference between the two dates
$interval = $datetime1->diff($datetime2);

// Display the difference 
echo "Difference: " . $interval->format('%y years, %m months, %d days');
?>
