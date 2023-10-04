<?php
function fetchRSS($url) {
    $curl = curl_init();
    curl_setopt_array($curl, array(
        CURLOPT_URL => $url,
        CURLOPT_RETURNTRANSFER => true,
        CURLOPT_TIMEOUT => 10,
        CURLOPT_SSL_VERIFYPEER => false, // You might want to change this in a production environment
    ));

    $response = curl_exec($curl);
    curl_close($curl);
    return $response;
}

function parseRSS($xml) {
    $rss = simplexml_load_string($xml);
    $items = [];

    foreach ($rss->channel->item as $item) {
        $feedItem = new stdClass();
        $feedItem->title = (string)$item->title;
        $feedItem->link = (string)$item->link;
        $feedItem->description = (string)$item->description;
        $feedItem->pubDate = (string)$item->pubDate;
        $items[] = $feedItem;
    }

    return $items;
}

function displayRSS($feedItems) {
    foreach ($feedItems as $item) {
        echo "<h2><a href='{$item->link}'>{$item->title}</a></h2>";
        echo "<p>{$item->description}</p>";
        echo "<p><strong>Published on:</strong> {$item->pubDate}</p>";
        echo "<hr>";
    }
}

// Example usage
$rssUrl = "https://example.com/rss-feed.xml";
$rssXml = fetchRSS($rssUrl);

if ($rssXml) {
    $feedItems = parseRSS($rssXml);
    displayRSS($feedItems);
} else {
    echo "Failed to fetch RSS feed.";
}
?>
