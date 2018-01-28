var main = function(p,q)
{
  //variables can be random or the previous numbers given based on
  //whether or not it was declared when calling main.
  var a = p || Math.floor(Math.random()*10);
  var b = q || Math.floor(Math.random()*10);
  var correctAns = a+b;
  //asks user addition question using 2 variables
  chalk.print("What is " + a + " + " + b + "?\n");
  //new line
  $("#chalk").append("<BR>");
  //entrybox returns a promise that contains the user's input, so
  //by using .then() to access the users input and checking that
  //with the correct answer to give a certain message to the user
  chalk.entrybox().then(function(userAns){
    if(userAns == correctAns)
    {
      chalk.print("Correct, go again!");
      $("#chalk").append("<BR>");
      $("#chalk").append("<BR>");
      main();
    }
    else
    {
      chalk.print("Wrong, lets try again!");
      $("#chalk").append("<BR>");
      $("#chalk").append("<BR>");
      main(a,b);
    }
  });
}

//Worked on this lab with Taylor Walenczyk
