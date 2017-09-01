main = function()
{
  chalk.println("Hello, EECS368!");
  square(5);
}

function square(length)
{
  //variables that be used so if I need to later change what gets printed
  //in the square I can just easily change the variables.
  var star = "*";
  var space = " ";

//First part of nested for-loop that will go through each row
//of the square
  for (var i = 0; i < length; i++)
  {
    //This will check to see if the row is the first or the last
    if (i == 0 || i == (length - 1))
    {
      //if it's the first or the last row then it will print all
      //stars for that row. For-loop will make sure that the number
      //of stars that gets printed is the number that given as the length
      for (var j = 0; j < length; j++)
      {
        chalk.print(star);
      }
      //new line to move on to the next row
      chalk.newline();
    }
    else
    {
      //if the row isn't the first or last then no stars need to be printed
      //inside the square. This for-loop will go through each position in
      //the row.
      for (var k = 0; k < length; k++)
      {
        //if the position is the first or last (if it is the side of the square)
        //then a star will get printed.
        if (k == 0 || k == (length - 1))
        {
          chalk.print(star);
        }
        //if the position is not the first or last then that means it is on the
        //the inside of the square in which case we want to print a space.
        else
        {
          chalk.print(space);
        }
      }
      //new line to move on to the next row
      chalk.newline();
    }
  }
}
