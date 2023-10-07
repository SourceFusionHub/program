<?php

function validateCreditCard($cardNumber) {
    $cardNumber = preg_replace('/\D/', '', $cardNumber);

    if (!ctype_digit($cardNumber) || empty($cardNumber)) {
        return "Invalid";
    }

    $reversedCardNumber = strrev($cardNumber);
    $sum = 0;
    $double = false;

    for ($i = 0; $i < strlen($reversedCardNumber); $i++) {
        $digit = intval($reversedCardNumber[$i]);

        if ($double) {
            $digit *= 2;

            if ($digit > 9) {
                $digit -= 9;
            }
        }

        $sum += $digit;
        $double = !$double;
    }
    return ($sum % 10 == 0) ? "Valid" : "Invalid";
}

$validationResult = null;

if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST["cardNumber"])) {
    $cardNumber = $_POST["cardNumber"];
    $validationResult = validateCreditCard($cardNumber);
}
?>
