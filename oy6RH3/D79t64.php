<?php

$items = []; 


function addItem($item) {
    global $items;
    $items[] = $item;
}


function getItems() {
    global $items;
    return $items;
}


function updateItem($index, $newItem) {
    global $items;
    if (isset($items[$index])) {
        $items[$index] = $newItem;
        return true;
    }
    return false;
}


function deleteItem($index) {
    global $items;
    if (isset($items[$index])) {
        array_splice($items, $index, 1);
        return true;
    }
    return false;
}


?>


