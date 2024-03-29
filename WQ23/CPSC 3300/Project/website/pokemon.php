<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="styling.css">
    <title>Pokemon</title>
    <link rel="icon" type="image/png" href="pics/favicon.png" sizes="16x16">    
  </head>
<body>
  <a href="https://css1.seattleu.edu/~glane/website/homepage.html">
    <img id = "logo" src = "pics/newlogo.png" />
  </a>
  <div class="header">
    <div class="menuitem">
      <a href="https://css1.seattleu.edu/~glane/website/homepage.html" class="btn">Home</a>
      <a href="https://css1.seattleu.edu/~glane/website/gamepairs.php" class="btn">Game Pairs</a>
      <a href="https://css1.seattleu.edu/~glane/website/pokedex.php" class="btn">Pokedexes</a>
      <a href="https://css1.seattleu.edu/~glane/website/record.php" class="btn">Records</a>  
      <a href="https://css1.seattleu.edu/~glane/website/pokemon.php" id="active">Pokemon</a>
      <a href="https://css1.seattleu.edu/~glane/website/list.php" class="btn">List</a>
      <a href="https://css1.seattleu.edu/~glane/website/pokeball.php" class="btn">Poke Balls</a>  
      <a href="https://css1.seattleu.edu/~glane/website/sandwich.php" class="btn">Sandwiches</a>
    </div>
    <div class="search-container">
      <form action="search.php" method="post">
        <input type="text" placeholder="Enter SQL Query Here..." name="search">
        <input value="Clear" type="reset">
        <input value="Submit" type="submit">
      </form>
    </div>
  </div>
  
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

  $sql = "select * from pokemon";
  $result = $conn->query($sql);

  if ($result->num_rows > 0) {
    echo "<table>
            <tr>
              <th>National Number</th>
              <th>Name</th>
              <th>Primary Type</th>
              <th>Secondary Type</th>
            </tr>";
    // output data of each row
    while($row = $result->fetch_assoc()) {
      echo "<tr>
              <td>" . $row["national_number"]. "</td>
              <td>" . $row["name"]. "</td>
              <td>" . $row["type1"]. "</td>
              <td>" . $row["type2"]. "</td>
            </tr>";
    }
    echo "</table>";
  } else {
    echo "0 results";
  }

  $conn->close();
  ?>
</body>
</html>