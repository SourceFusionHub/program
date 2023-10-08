<?php
// PHP code to implement a basic URL Filtering System
 
// Declaring variable named url and initializing it to URL to be checked
$url = "https://github.com/SourceFusionHub/program";
 
// Using filter function to validate URL
if (filter_var($url, FILTER_VALIDATE_URL)) {
    echo "$url is a Valid URL";
} else {
    echo "$url is an Invalid URL";
}

?>