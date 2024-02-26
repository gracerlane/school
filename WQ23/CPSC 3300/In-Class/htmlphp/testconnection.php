<?php
$servername = "cssql.seattleu.edu";
$username = "ll_glane";
$password = "Cpsc3300Glane!";
// Create connection
$conn = mysqli_connect($servername, $username, $password);
// Check connection
if (!$conn) {
die("Connection failed: " . mysqli_connect_error());
}
echo "Connected successfully";
mysqli_close($conn);
?> 