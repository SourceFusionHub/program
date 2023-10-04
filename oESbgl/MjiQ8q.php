<?php
// Postal code pattern to match (e.g., "12345" or "AB123")
$pattern = '/^\d{5}$|^[A-Z]{2}\d{3}$/';

// Postal code to validate
$postalCode = "12345"; 

// Perform the validation
if (preg_match($pattern, $postalCode)) {
    echo "Postal code '$postalCode' is valid in the specified format.";
} else {
    echo "Postal code '$postalCode' is not valid in the specified format.";
}
?>

