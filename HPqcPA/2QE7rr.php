php
<?php
if(isset($_POST['submit'])){
    foreach($_POST['item'] as $selectedItem){
        echo "Selected item: " . $selectedItem . "<br>";
    }
}
?>
