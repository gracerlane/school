<?php
  echo "Welcome " . $_POST["name"] . "<br>";
  echo "Your email address is: " . $_POST["email"] . "<br>";

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

  $sql = "Select name AS TableName, object_id AS ObjectID
          From sys.tables
          From sys.tables
          –– where name = '<TABLENAME>'
          –– Uncomment above line and add <Table Name> to fetch details for particular table";
  $result = $conn->query($sql);

  if ($result->num_rows > 0) {
    echo "<table>
            <tr>
              <th>National Number</th>
              <th>Name</th>
              <th>Number of Regions</th>
            </tr>";
    // output data of each row
    while($row = $result->fetch_assoc()) {
      echo "<tr>
              <td>" . $row["national_number"]. "</td>
              <td>" . $row["name"]. "</td>
              <td>" . $row["regions"]. "</td>
            </tr>";
    }
    echo "</table>";
  } else {
    echo "0 results";
  }

  $conn->close();
?>