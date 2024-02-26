<?php
$servername = "cssql.seattleu.edu";
$username = "ll_glane";
$password = "Cpsc3300Glane!";
$dbname = "ll_glane";
// Create connection
$conn = mysqli_connect($servername, $username, $password, $dbname);
// Check connection
if (!$conn) {
die("Connection failed: " . mysqli_connect_error());
}
$sql = "CREATE TABLE AvailableCourses (
courseCode VARCHAR(5) PRIMARY KEY,
courseName VARCHAR(30) NOT NULL,
level               VARCHAR(2)      NOT NULL,
credits    INT)";
if (mysqli_query($conn, $sql)) {
echo "Table created successfully";
} else {
echo "Error creating table: " . $sql . "<br>" . mysqli_error($conn);
}
mysqli_close($conn);
?> 