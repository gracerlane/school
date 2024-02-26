<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="styling.css">
    <title>Query 1</title>
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
      <h3>Query 1: Find which games have the Safari Ball.</h3>

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

    $sql = "select distinct g.games
            from game_pair g
            inner join list l
            on g.games = l.games 
            inner join pokeball b
            on b.ball_name = l.ball_name and b.ball_name like 'Safari Ball';";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
      echo "<table>
              <tr>
                <th>Games</th>              
              </tr>";
      // output data of each row
      while($row = $result->fetch_assoc()) {
        echo "<tr>
                <td>" . $row["games"]. "</td>
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