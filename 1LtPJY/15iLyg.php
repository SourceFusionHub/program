<?php

function sumOfArithmeticSeries($firstTerm, $commonDifference, $numberOfTerms) {
  $sum = ($firstTerm + ($firstTerm + ($numberOfTerms - 1) * $commonDifference)) / 2 * $numberOfTerms;
  return $sum;
}

$firstTerm = 1;
$commonDifference = 2;
$numberOfTerms = 10;

$sum = sumOfArithmeticSeries($firstTerm, $commonDifference, $numberOfTerms);

echo "The sum of the arithmetic series is: $sum";

?>
