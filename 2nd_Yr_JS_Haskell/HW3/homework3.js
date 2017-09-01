var flatten = function (array)
{
    return array.reduce(function (a,b){
      return a.concat(Array.isArray(b) ? flatten(b) : b);},[]);
}

/*
Before concat, it will check to see if b is an array and
if it is then it will recursively call 'flatten' again
using b as the array it is reducing. If b is not an array
then it will concat with a. Using reduce and recursion, it
will ensure that every element of the array is checked, no
matter how many dimensions the array contains.
*/

//http://stackoverflow.com/questions/10865025/merge-flatten-an-array-of-arrays-in-javascript
