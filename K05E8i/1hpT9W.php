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

<!DOCTYPE html>
<html>
  <head>
    <title>Credit Card Validation</title>
    <style>
      body {
        font-family: Arial, sans-serif;
        background-color: #f4f4f4;
        display: flex;
        justify-content: center;
        align-items: center;
        height: 100vh;
        flex-direction: column;
      }

      h1 {
        text-align: center;
        color: #333;
      }

      form {
        width: clamp(300px, 50vw, 600px); 
        margin: 0 auto;
        background: #fff;
        padding: 20px;
        border-radius: 5px;
        box-shadow: 0 0 10px rgba(0, 0, 0, 0.2);
        transition: all 0.3s ease-in-out;
      }

      form:hover {
        box-shadow: 0 5px 20px rgba(0, 0, 0, 0.3);
      }

      label {
        display: block;
        margin-bottom: 5px;
        font-weight: bold;
      }

      input[type="text"] {
        background-color: #f4f4f4;
        width: 95%;
        padding: 10px;
        margin-bottom: 10px;
        border: 1px solid #ccc;
        border-radius: 5px;
        font-size: 1rem;
      }

      input[type="submit"] {
        background-color: #007bff;
        color: #fff;
        padding: 10px 20px;
        border: none;
        border-radius: 5px;
        cursor: pointer;
        display: block;
        margin: 0 auto;
        transition: all 0.3s ease-in-out;
        font-size: 1rem;
        letter-spacing: 1px;
        border: 2px solid #007bff;
      }

      input[type="submit"]:hover {
        background-color: #ffffff;
        color: #007bff;
        border: 2px solid #007bff;
      }

      p {
        font-weight: bold;
        text-align: center;
        margin-top: 15px;
        color: #333;
      }

      .example {
        color: rgba(0, 0, 0, 0.5)
      }
    </style>
  </head>
  <body>
    <h1>Credit Card Validation</h1>
    <form method="post" action="">
      <label for="cardNumber">Enter a credit card number:</label>
      <input type="text" name="cardNumber" id="cardNumber" required="" />
      <input type="submit" value="Validate" />
    </form>

    <?php 
        if ($validationResult !== null) { ?>
    <p
      style="color: <?php echo ($validationResult === 'Valid') ? 'green' : 'red'; 
    ?>
        "
    >
      <?php echo $validationResult; ?>
      credit card number.
    </p>
    <?php 
        } 
    ?>

    <div>
        <p class="example">Example: This is a valid credit card number: <strong>4532015112830366</strong></p>
    </div>

  </body>
</html>
