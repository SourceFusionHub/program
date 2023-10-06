<?php
// Specify the path to your text file
$filePath = 'path/to/your/textfile.txt';

if (file_exists($filePath)) {
    $fileContent = file_get_contents($filePath);

    echo nl2br($fileContent); // nl2br() is used to preserve line breaks in HTML

} else {
    echo 'The file does not exist.';
}
?>