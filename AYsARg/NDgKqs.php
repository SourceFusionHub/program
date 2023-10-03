<?php

$users = [
    'Alice' => ['Mars' => 5, 'Moon' => 3, 'Jupiter' => 2],
    'Bob' => ['Moon' => 5, 'Venus' => 4],
    'Charlie' => ['Mars' => 4, 'Saturn' => 3],
    'Dave' => ['Saturn' => 5, 'Venus' => 3],
];
function cosineSimilarity($prefs, $person1, $person2) {
    $sum_xy = 0;
    $sum_x2 = 0;
    $sum_y2 = 0;

    foreach ($prefs[$person1] as $item => $rating) {
        if (isset($prefs[$person2][$item])) {
            $sum_xy += $rating * $prefs[$person2][$item];
            $sum_x2 += pow($rating, 2);
            $sum_y2 += pow($prefs[$person2][$item], 2);
        }
    }

    if ($sum_x2 == 0 || $sum_y2 == 0) {
        return 0;
    }

    return $sum_xy / (sqrt($sum_x2) * sqrt($sum_y2));
}


function getRecommendations($prefs, $person) {
    $total = [];
    $simSums = [];
    $ranks = [];
    $sim = 0;

    foreach ($prefs as $otherPerson => $values) {
        if ($otherPerson != $person) {
            $sim = cosineSimilarity($prefs, $person, $otherPerson);

            if ($sim > 0) {
                foreach ($prefs[$otherPerson] as $item => $rating) {
                    if (!isset($prefs[$person][$item]) || $prefs[$person][$item] == 0) {
                        if (!isset($total[$item])) {
                            $total[$item] = 0;
                        }
                        $total[$item] += $prefs[$otherPerson][$item] * $sim;

                        if (!isset($simSums[$item])) {
                            $simSums[$item] = 0;
                        }
                        $simSums[$item] += $sim;
                    }
                }
            }
        }
    }

    foreach ($total as $item => $totalValue) {
        $ranks[$item] = $totalValue / $simSums[$item];
    }

    arsort($ranks);
    return $ranks;
}


$user = 'Alice';
$recommendations = getRecommendations($users, $user);
echo "Recommended trips for $user:\n";
foreach ($recommendations as $trip => $rating) {
    echo "$trip: $rating\n";
}

?>
