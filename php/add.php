<?php
   
   define("LIMIT", "2878");
   include("connect.php");
   $link=Connection();

   if(isset($_POST["temp"]) && isset($_POST["pres"]) && isset($_POST["hum"])){

   	$temp = $_POST["temp"];
      $pres = $_POST["pres"];
   	$hum = $_POST["hum"]; 	
      mysql_query("INSERT INTO `senzory2` (`temperature`, `humidity`,`pressure`) VALUES ('".$temp."','".$hum."','".$pres."')", $link);
   }

   $row = mysql_fetch_array(mysql_query("SELECT COUNT(*) FROM minmax WHERE  DATE(date) = DATE(DATE_SUB(NOW(), INTERVAL 1 DAY))", $link));
   var_dump($row[0]);

   if($row[0] == "0"){
      mysql_query(
         "INSERT INTO minmax (date, tmin, tmax, pressure) VALUES(
            (SELECT DATE(DATE_SUB(NOW(), INTERVAL 1 DAY))),
            (SELECT MIN(temperature) FROM senzory2 WHERE DATE(time) = DATE(DATE_SUB(NOW(), INTERVAL 1 DAY))),
            (SELECT MAX(temperature) FROM senzory2 WHERE DATE(time) = DATE(DATE_SUB(NOW(), INTERVAL 1 DAY))),
            (SELECT AVG(pressure) FROM senzory2 WHERE DATE(time) = DATE(DATE_SUB(NOW(), INTERVAL 1 DAY)))
         )", $link
      );
   }

   mysql_close($link);

?>

