<?php
   	include("connect.php");
   	
   	$link=Connection();

	$temp = $_POST["temp"];
   $pres = $_POST["pres"];
	$hum = $_POST["hum"];

	$query = "INSERT INTO `senzory2` (`temperature`, `humidity`,`pressure`) 
		VALUES ('".$temp."','".$hum."','".$pres."')"; 
   	
   	mysql_query($query,$link);
	mysql_close($link);

?>

