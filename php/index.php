<?php

	include("connect.php"); 	
	
	$link=Connection();

	$result=mysql_query("SELECT * FROM `senzory2` ORDER BY `time` DESC LIMIT 20",$link);
	$result2=mysql_query("SELECT * FROM `senzory2` ORDER BY `time` DESC LIMIT 1",$link);
?>

<html>
   <head>
      <title>meteo</title>
      <meta charset="UTF-8">
   </head>
<body>
   <h1>Meteorologická stanice</h1>
   <h2>
   		<?php
   			$row = mysql_fetch_array($result);

   			echo "Teplota: ",$row["temperature"]/100," °C <br> Tlak: ",$row["pressure"]/10," HPa <br> Vlhkost: ",$row["humidity"]/10," %";




   		?>
   </h2>

   <table border="1" cellspacing="1" cellpadding="1">
		<tr>
			<td>&nbsp;Datum a čas &nbsp;</td>
			<td>&nbsp;Teplota / °C &nbsp;</td>
			<td>&nbsp;Tlak / HPa &nbsp;</td>
			<td>&nbsp;Vlhkost / % &nbsp;</td>
		</tr>

      <?php 
		  if($result!==FALSE){
		     while($row = mysql_fetch_array($result)) {
		        printf("<tr><td> &nbsp;%s </td><td> &nbsp;%s&nbsp; </td><td> &nbsp;%s&nbsp; </td><td> &nbsp;%s&nbsp; </td></tr>", 
		           $row["time"], $row["temperature"]/100, $row["pressure"]/10, $row["humidity"]/10);
		     }
		     mysql_free_result($result);
		     mysql_close();
		  }
      ?>

   </table>
</body>
</html>
