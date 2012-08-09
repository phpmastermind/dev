
  <?php 
  		
  		include_once('video_header.php');
  		
  		$videoname = "collab1_RakeshG_HowToUseTelepresence"; //all u have to change is this.
  		if($_GET["file"]!="")
  			$path = ($_GET["file"]);
			$file = basename($path);         
			$videoname = basename($path, ".php");
			//echo $file;
			
			//$videoname = urldecode($_GET["file"]);
		//echo $videoname;	
  		include_once('video_footer.php');
  
  ?>
	
