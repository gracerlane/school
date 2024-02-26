<!-- <?php
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

$sql = "SELECT * FROM game_pair";
$result = mysqli_query($conn, $sql);

if (mysqli_num_rows($result) > 0) {
    // output data of each row
    while($row = mysqli_fetch_assoc($result)) {
        echo "id: " . $row["games"]. " - Name: " . $row["year"]. " " . $row["gimmick"]. " " . $row["played_on"]. "<br>";
    }
} else {
    echo "0 results";
}

mysqli_close($conn);
?> -->