
<html>
<h1>Search results</h1></br>
<h4> Similer images</h4>
</hr>
<table>
<?php
ini_set("display_errors", 1);

  if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"],$_SERVER['DOCUMENT_ROOT'] .'/web/imageprocess/uploads/search')) {
  	$x=exec("./m");
  	if($x=='person')
  		{
  		
  		$dir = '/var/www/html/web/imageprocess/persons';
  		$www_root = 'http://localhost/web/imageprocess/persons';
  		}
  	 	else
  	 	{
  			$dir = '/var/www/html/web/imageprocess/cars';
  			$www_root = 'http://localhost/web/imageprocess/cars';
			}
    
    $file_display = array('jpg', 'jpeg', 'png', 'gif');

    if ( file_exists( $dir ) == false ) {
       echo 'Directory \'', $dir, '\' not found!';
    } else {
       $dir_contents = scandir( $dir );
				echo '<tr>';
        foreach ( $dir_contents as $file ) {
           $file_type = strtolower( end( explode('.', $file ) ) );
           if ( ($file !== '.') && ($file !== '..') && (in_array( $file_type, $file_display)) ) {
              echo '<td><img src="', $www_root, '/', $file, '" alt="', $file, '"  height="300" width="300"/></td>';
           }
        }
        echo '</tr>';
    }
		
    } else {
        echo "Sorry, there was an error uploading your file.";
    }
    
?>
</table>
</html>
