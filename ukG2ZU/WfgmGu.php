<?php
function calculateSeriesSum($n) {
    $sum = 0.0;

    for ($i = 0; $i <= $n; $i++) {
        $sum += 1.0 / pow(2, $i);
    }

    return $sum;
}

$n = intval(readline("Enter the value of n: "));

$seriesSum = calculateSeriesSum($n);

echo "The sum of the series is: " . $seriesSum . PHP_EOL;
?>
