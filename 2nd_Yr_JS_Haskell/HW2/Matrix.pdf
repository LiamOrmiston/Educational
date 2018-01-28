function mm(a,b)
{
  if (checkArray(a) == false)
  {
    throw new Error("The first variable is not an array!");
  }
  else if (checkArray(b) == false)
  {
    throw new Error("The second variable is not an array!");
  }
  else if (checkLength(a) == false)
  {
    throw new Error("The first array has inconsistant lengths");
  }
  else if (checkLength(b) == false)
  {
    throw new Error("The second array has inconsistant lengths");
  }
  //will create a new array and give it the new multiplied values and then print
  //once multiplying is complete.
  else
  {
    var result = new Array(a.length);

    for (var i = 0; i < result.length; i++)
    {
      result[i] = new Array(b[i].length);
      for (var j = 0; j < a.length; j++) {
        result[i][j] = 0;
        for (var k = 0; k < b.length; k++)
        {
          result[i][j] += a[i][k] * b[k][j];
        }
      }
    }
    console.log(JSON.stringify(result));
  // http://stackoverflow.com/questions/30561056/console-log-a-multi-dimensional-array
  }
  // https://www.youtube.com/watch?v=x7zua7fhyIw
}

//checks to see if the variable given is an array. If the variable is an array
//the function will return true.
function checkArray(array)
{
  if(array.constructor != Array)
  {
    return false;
  }
  else
  {
    return true;
  }
}
//http://stackoverflow.com/questions/767486/how-do-you-check-if-a-variable-is-an-array-in-javascript

//checks to see if the lengths of the matrix are consistant. If lengths are consistant
//the function will return true.
function checkLength(array)
{
  var l = array[0].length;
  for (var i = 0; i < array.length; i++)
  {
    if (array[i].length != array[0].length)
    {
      return false;
    }
  }
  return true;
}
