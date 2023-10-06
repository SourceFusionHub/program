<?php
function validateURL($url) {
    if (filter_var($url, FILTER_VALIDATE_URL) === false) {
        return false;
    }

    $ch = curl_init($url);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($ch, CURLOPT_TIMEOUT, 5);
    curl_exec($ch);
    $httpCode = curl_getinfo($ch, CURLINFO_HTTP_CODE);
    curl_close($ch);

    return ($httpCode >= 200 && $httpCode < 300);
}


// ----- Example Use of the Program Above -----

$url = "https://www.example.com";
if (validateURL($url)) {
    echo "URL is valid and reachable.";
} else {
    echo "URL is not valid or not reachable.";
}
?>
