<!DOCTYPE html>
<html>
	<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="styling.css">
    <title>Home</title>
    <link rel="icon" type="image/png" href="pics/favicon.png" sizes="16x16">    
  </head>
	<body> 
		<?php
			if ($_SERVER["REQUEST_METHOD"] == "POST") {
				$search = $_POST["search"];
			}

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
			$sql=$search;
			$result=mysqli_query($conn,$sql);
			$row=mysqli_fetch_array($result, MYSQLI_ASSOC)
			?>
	
			<table>
					<th>
									<tr>
											<th><?php echo implode("</th><th>", array_keys($row)); ?>
											</th>
									</tr>
					</th>
					<tbody>
									<tr>
									<td><?php echo implode("</td><td>", $row); ?>
									</td>
									</tr>
	
			<?php
			$counter = 0;
			while($row=mysqli_fetch_array($result, MYSQLI_ASSOC)){
	//        echo $counter;
	//        echo nl2br("\n");
					?>  
	
									<tr>
									<td><?php echo implode("</td><td>", $row); ?>
									</td>
									</tr>
	
					<?php
					$counter ++;
			}
	
	mysqli_free_result($result);
	mysqli_close($conn);
	?>  
							</tbody>
					</table>
	</body>
</html>