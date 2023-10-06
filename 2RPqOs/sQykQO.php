function generateFibonacci($n) {
    $fibSeries = array();
    if ($n <= 0) {
        return $fibSeries;
    } elseif ($n == 1) {
        return array(0);
    } elseif ($n == 2) {
        return array(0, 1);
    } else {
        $fibSeries = array(0, 1);
        for ($i = 2; $i < $n; $i++) {
            $nextTerm = $fibSeries[$i - 1] + $fibSeries[$i - 2];
            array_push($fibSeries, $nextTerm);
        }
        return $fibSeries;
    }
}

function calculateSum($fibSeries) {
    return array_sum($fibSeries);
}

$number = (int)readline("Enter the number of terms in the Fibonacci series: ");

if ($number < 0) {
    echo "Please enter a non-negative integer.";
} else {
    $fibSeries = generateFibonacci($number);
    echo "Fibonacci Series: " . implode(', ', $fibSeries) . "\n";
    $sumOfFibonacci = calculateSum($fibSeries);
    echo "Sum of Fibonacci Series: " . $sumOfFibonacci . "\n";
}
?>
