<style><?php include 'styling.css'; ?></style>

<?php
$servername = "cssql.seattleu.edu";
$username = "ll_glane";
$password = "Cpsc3300Glane!";
$dbname = "ll_glane";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

$sql = "select * from game_pair";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
  echo "<table>
					<tr>
						<th>Games</th>
						<th>Year</th>
						<th>Gimmick</th>
						<th>Played On</th>
					</tr>";
  // output data of each row
  while($row = $result->fetch_assoc()) {
    echo "<tr>
  	        <td>" . $row["games"]. "</td>
						<td>" . $row["year"]. "</td>
						<td>" . $row["gimmick"]. "</td>
						<td>" . $row["played_on"]. "</td>
					</tr>";
  }
  echo "</table>";
} else {
  echo "0 results";
}

$conn->close();
?>


