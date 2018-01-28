#include "Executive.h"
#include "Patient.h"
#include "Heap.h"
#include <string>
#include <iostream>
#include <ostream>


//constructor; it opens the indicated file and calls runSimulation.
Executive::Executive(const char* fileName)
{
  file.open(fileName);
}

//run simulation will read in the values in the text file
void Executive::runSimulation()
{
  file >> size;
  PriorityQueue<Patient> myQueue(size);
  while(file.peek() != EOF)
  {
    //as long as the file has not reached the end of the file it will continue getting information
    file >> command;
    //will add using the name and priority given folling the command
    if (command.compare("arrival") == 0)
    {
      file >> name;
      file >> priority;
      Patient* newPatient = new Patient(name, priority);
      myQueue.enqueue(*newPatient);
    }
    //will remove the first person in the priority queue
    else if (command.compare("serve") == 0)
    {
      try
      {
        myQueue.dequeue();
      }
      catch (EmptyPriorityQueue e)
      {
        std::cout << e.what() << std::endl;
      }

    }
    //will display the priority queue with the user.
    else if (command.compare("preview") == 0)
    {
      PriorityQueue<Patient> copy(myQueue);
      preview(copy);
    }
    //clears the command to get rid of duplicate prints
    command = "";
  }
}

//will print the priority queue using the copy by printing the first value and then removing it until the whole thing is done.
template <typename T>
void Executive::preview(PriorityQueue<T>& pq)
{
    std::cout << "=============Assuming no new arrivals, the current set of patients will be processed as follows============" << std::endl;
    while(!pq.isEmpty())
    {
      Patient temp = pq.peekFront();
      std::string name = temp.getName();
      int priority = temp.getPriority();
      std::cout << name << " with priority " << priority <<std::endl;
      pq.dequeue();
    }
    std::cout << "============================================End of Preview=================================================" << std::endl;
} // NOTE: The Priority Queue is passed by value!!!
