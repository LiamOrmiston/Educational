#include <string>
#include <iostream>

#include "bubbleSort.cpp"
#include "insertionSort.cpp"
#include "mergesort.cpp"
#include "quicksort.cpp"
#include "selectionSort.cpp"
#include <stdlib.h>
#include <time.h>


int main (int argc, char** argv)
{
//takes in the size of array, the order, and the type of sort from the user
//when the program is ran
  int dataSize = std::stoi(argv [1]);
  std::string dataOrder = argv [2];
  std::string sortType = argv [3];

//creates an array with the given size from the user
  double* array = new double [dataSize];
  srand48(1);
  double temp;
  clock_t start = 0, end = 0;
  double timeTaken;

//diplays the variables the user gave the program
  std::cout << dataSize << std::endl;
  std::cout << dataOrder << std::endl;
  std::cout << sortType << std::endl;

//fills the array with numbers starting at 0 and incrementing by 0.001
//ascending
  if (dataOrder == "ascending")
  {

    for (int i = 0; i < dataSize; i++)
    {
      array[i] = 0.001 * static_cast <double> (i);
    }
  }

//descending
  else if (dataOrder == "descending")
  {
    for (int i = 0; i < dataSize; i++)
    {
      array[i] = 0.001*static_cast<double>(dataSize - i - 1);
    }
  }

//random
  else if (dataOrder == "random")
  {
    for (int i = 0; i < dataSize; i++)
    {
      temp = drand48()*100000.0;
      array[i] = temp;
    }
  }

//anything else is invalid
  else
  {
    std::cout << "did not give a valid form of input" <<std::endl;
  }


/*
If you wanted to see the before and after array then you could uncomment this
and it would display it BEFORE the sorted method runs

  for (int i = 0; i < dataSize; i++)
  {
    //std::cout << array[i] << std::endl;
  }
*/

//depending on what sort type the user gave, it will start the clock and then
//run what ever sort method was given, and then stop the clock.
//bubble sort
  if (sortType == "bubble")
  {
    start = clock();
    bubbleSort(array, dataSize);
    end = clock();
  }

  //insertion sort
  else if (sortType == "insertion")
  {
    start = clock();
    insertionSort(array, dataSize);
    end = clock();
  }

//merge sort
  else if (sortType == "merge")
  {
    start = clock();
    mergeSort(array, dataSize);
    end = clock();
  }

//quick sort
  else if (sortType == "quick")
  {
    start = clock();
    quickSort(array, 0, dataSize-1);
    end = clock();
  }

//selection sort
  else if (sortType == "selection")
  {
    start = clock();
    selectionSort(array, dataSize);
    end = clock();
  }

//anything else is invalid
  else
  {
    std::cout << "not a valid sort type" << std::endl;
  }


  /*
  If you wanted to see the before and after array then you could uncomment this
  and it would display it AFTER the sorted method runs

    for (int i = 0; i < dataSize; i++)
    {
      //std::cout << array[i] << std::endl;
    }
  */

//displays the time it took to sort the array
  timeTaken = ((double)(end - start) / CLOCKS_PER_SEC);
  std::cout << "time taken: " << timeTaken << std::endl;

//destructor
  delete[] array;
}
