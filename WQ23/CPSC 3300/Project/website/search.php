<!DOCTYPE html>
<html>
	<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="styling.css">
    <title>Search</title>
    <link rel="icon" type="image/png" href="pics/favicon.png" sizes="16x16">    
  </head>
	<body> 
    <a href="https://css1.seattleu.edu/~glane/website/homepage.html">
    <img id = "logo" src = "pics/newlogo.png"/>
  </a>
  <div class="header">
    <div class="menuitem">
      <a href="https://css1.seattleu.edu/~glane/website/homepage.html" class="btn">Home</a>
      <a href="https://css1.seattleu.edu/~glane/website/gamepairs.php" class="btn">Game Pairs</a>
      <a href="https://css1.seattleu.edu/~glane/website/pokedex.php" class="btn">Pokedexes</a>
      <a href="https://css1.seattleu.edu/~glane/website/record.php" class="btn">Records</a>
      <a href="https://css1.seattleu.edu/~glane/website/pokemon.php" class="btn">Pokemon</a>
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
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
      $sql = $_POST["search"];
    }
    
    echo "<h4> Your query was: $sql </h4>";
    
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
    
    if (strpos($sql, "s") === 0 || strpos($sql, "S") === 0) {
      $result=mysqli_query($conn,$sql);
      $row=mysqli_fetch_array($result, MYSQLI_ASSOC);
      if (mysqli_num_rows($result) > 0) { ?> 
        <table>
          <tr>
            <th> <?php echo implode("</th><th>", array_keys($row)); ?> </th>
          </tr>
          <tbody>
            <tr>
              <td> <?php echo implode("</td><td>", $row); ?> </td>
            </tr>
      <?php while($row=mysqli_fetch_array($result, MYSQLI_ASSOC)){ ?>
              <tr>
                <td> <?php echo implode("</td><td>", $row); ?> </td>
              </tr>
      <?php } ?>
          </tbody>
        </table>
<?php } else {
        echo "0 Results";
      }
    } else {
      if (mysqli_query($conn, $sql)) {
        echo "<h4> Query executed successfully! </h4>";
      } else {
        echo "Error: " . $sql . "<br>" . mysqli_error($conn);
      }
    }
    
    mysqli_free_result($result);                      
    mysqli_close($conn); 
    
    ?>
    
	</body>
</html>