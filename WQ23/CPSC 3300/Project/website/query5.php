<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="styling.css">
    <title>Query 5</title>
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
      <a href="https://css1.seattleu.edu/~glane/website/pokedex.html" class="btn">Pokedexes</a>
      <a href="https://css1.seattleu.edu/~glane/website/record.html" class="btn">Records</a>  
      <a href="https://css1.seattleu.edu/~glane/website/gamepairs.html" class="btn">Poke Balls</a>  
      <a href="https://css1.seattleu.edu/~glane/website/gamepairs.html" class="btn">List</a>
      <a href="https://css1.seattleu.edu/~glane/website/gamepairs.html" class="btn">Sandwiches</a>
    </div>
    <div class="search-container">
      <form action="search.php" method="post">
        <input type="text" placeholder="Enter SQL Query Here..." name="search">
        <input value="Clear" type="reset">
        <input value="Submit" type="submit">
      </form>
    </div>
  </div>
  
  <div class="pagecontent">
    <h3>Query 5: List the Pokémon (national_number and name) in the games and how many regions they’re in.</h3>

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

  $sql = "select p.national_number, p.name, count(r.region_name) as regions
          from pokedex d
          left outer join record r
          on d.region_name = r.region_name
          left outer join pokemon p
          on p.national_number = r.national_number
          group by p.national_number
          order by p.national_number;";
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
  </div>
  
</body>
</html>