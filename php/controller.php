<?php
	
	header("Content-type: text/javascript");
	include("connect.php"); 	
	
	$link=Connection();
	

	if( $_REQUEST["type"] ){
	   
	   $type = $_REQUEST['type'];
	   switch ($type) {

		    case "a":
		    	$result=mysql_query("SELECT * FROM (SELECT * FROM senzory2 ORDER BY time DESC LIMIT 5000) sub ORDER BY time", $link);
		        echo json_encode(mysqlData($result));
		        break; 

		    case "b":
		    	$result=mysql_query("SELECT * FROM minmax ORDER BY date", $link);
		        echo json_encode(mysqlData($result));
		        break;

		    case "c":
		    	$result=mysql_query("SELECT * FROM `senzory2` ORDER BY time DESC LIMIT 1", $link);
		        echo json_encode(mysql_fetch_row($result));
		        break;

		}
		mysql_free_result($result);
	}	
	
	mysql_close(); 

	
	function mysqlData($result){
		$array = [];
		while($row = mysql_fetch_row($result)){
			$array[] = $row;				
   		}
	   	return $array;
	}





?>
