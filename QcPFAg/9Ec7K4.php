<?php
$filePath = "files/your-file-name.ext"; // Replace with the actual file path

if (file_exists($filePath)) {
    header("Content-Disposition: attachment; filename=" . basename($filePath));
    header("Content-Type: application/octet-stream");
    header("Content-Length: " . filesize($filePath));

    readfile($filePath);
} else {
    http_response_code(404);
    echo "File not found";
}
?>
