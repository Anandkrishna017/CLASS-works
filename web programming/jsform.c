<html>
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width">
  <title>JS Bin</title>
</head>
<body>
<center>
  <h1>Registration form</h1></center>
  <form method="POST" >
  <table>
    <tr>
      <td>Name:</td><td>
      <input type="text" placeholder="eg:-John" style="text-transform:uppercase" id="name" onkeyup="up()"></td></tr>
    
    
    
    <tr><td></td><td id="name1"></td></tr>
      
      
      
      
    <tr><td>Admission Number:</td><td>
      <input type="text" placeholder="eg:-22c023" id="addno" style="text-transform:uppercase"></td></tr>
    <tr><td>E-mail:</td><td>
      <input type="text" id="email" placeholder="eg:-xyz@gmail.com" style="text-transform:lowercase"></td></tr>
    <tr><td>Mobile Number:
      </td><td><input type="number" id="mobile" placeholder="eg:-0123456789" ></td></tr>
    <tr><td>Gender:</td><td>
      <input type="radio" id="male" name="radio">
      <label for="male">Male</label>&nbsp;
   <input type="radio" id="female" name="radio"> 
      <label for="female">Female</label></td></tr>
    <tr><td>Password:</td><td>
      <input type="password" id="pass"></td></tr>
    <tr><td>Confirm Password:
      </td><td><input type="password" id="cpass"></td></tr>
    <tr ><td colspan="2">
      <input type="checkbox" id="check">
      <b>I agree to the terms and conditions as set out by the user agreement</b></td></tr>
    <tr ><td>
      <input type="submit" value="submit" class="submit" onclick="func()">
      </td><td><input type="reset" value="reset" class="reset"><td></tr>
    </table>
      </form>
</body>
</html>











function func()
{
  var name=document.getElementById("name").value;
  var addno=document.getElementById("addno").value;
 /* var email=document.getElementById("email").value;
  var mobile=document.getElementById("mobile").value;
  var pass=document.getElementById("pass").value;
  var cpass=document.getElementById("cpass").value;
  var check=document.getElementById("check").value;
  var radio=document.getElementByName("radio").value; */
  var letter = /[0-9!@#$%^&*]/ 
  var flag=0;
  

  

 if (name=="")
 {
   //document.getElementById("name1").value="no text";
    alert("Enter First Name !!");
   flag=0;
   return false;
 }
 else if(letter.test(name))
   {
     alert("Enter valid Name !!");
   flag=0;
   }
 if (addno=="")
 {
      // document.getElementById("name1").value="invalid text";
    alert("Enter admission number Name !!");
   flag=0;
 }
 
   
    
}

