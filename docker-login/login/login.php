<?php
error_reporting(0);
function str_safe($str)
{
    $in_=array("~","`","!","@","$","%","^","&","*","(","-","_","=","{","|","\\","<<",">>","/","or","and","+","select","MOD","DIV","mod","div");
    $out_=array("","","","","","","","","","","","","","","","","","","","??","??","","??","??","","??","");
    return str_replace($in_,$out_,$str);
}
if(isset($_POST["login"]))
{
$link = mysql_connect("localhost","root") or die ("cannot connect database".mysql_error());
mysql_select_db("member") or die ("cannot select the db");
$username = str_safe($_POST["user"]);
$password = str_safe($_POST["password"]);
$query = "select * from user where user='".$username ."'and password='".md5($password)."'";
echo $query."<br/>";
$result = mysql_query($query);
echo "<br/>";
$match_count = mysql_num_rows($result);
if($match_count){
while($row = mysql_fetch_assoc($result)){
echo "<strong>User: </strong>".$row["user"]."<br/>";
echo "<strong>Password: </strong>".$row["password"]."<br/>";
echo "login success!";
echo "<!--so what-->";
echo "<br/>";
}
}
else {
echo "Wrong User or password <br/>";
echo '<a href="./index.html">Back</a><br/>';
}
mysql_free_result($result);
mysql_close($link);
}
