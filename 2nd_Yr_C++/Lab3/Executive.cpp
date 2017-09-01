#include <string>
#include <iostream>
#include "Executive.h"
#include "MathTools.h"

//Declares the int that stores the choice of the user.
Executive::Executive()
{
  num = 0;
}

//Method to check to see if the user gives an int
double Executive::isDouble()
{
  double input;
  std::cin >> input;

//If the user doesn't give an int then it will ignore their choice until they give an int
  while(std::cin.fail())
  {
    std::cin.clear();
    std::cin.ignore();
    std::cout << "Please give a valid option" << std::endl;
    std::cin >> input;
  }
  return(input);
}

//The run method called in main
void Executive::run()
{
//Will loop until the user selects 4 to quit
  while (num != 4)
  {
    std::cout << "1. Enter A, B, C for a quadratic equation to be solved" << std::endl;
    std::cout << "2. Enter the d, e, f parameters for a line to be intersected with a unit circle" << std::endl;
    std::cout << "3. Enter Area, Extra, and minRequiredLength for a ballroom" << std::endl;
    std::cout << "4. Quit" << std::endl;
    std::cout << "" << std::endl;
    std::cin >> choice;

    try
    {
//turn the users input into an int
      num = std::stoi (choice);

//if the user gives a value between 1 - 4
      if (num < 5 && num > 0)
      {

//if the user selects 1
        if (num == 1)
        {
//ask for an input and then check to make sure it is an int
          std::cout<< "A: ";
          a = isDouble();
          std::cout << "";
          std::cout<< "B: ";
          b = isDouble();
          std::cout << "";
          std::cout<< "C: ";
          c = isDouble();;
          std::cout << "";

//Runs the solve quatradic with users inputs
            int n_roots = math.solveQuadratic(a, b, c, roots);

//Displays the solutions
            std::cout << n_roots << " solution(s)" << std::endl;
            std::cout << "The root(s) are/is: ";
            for (int i = 0; i < n_roots; i++)
            {
              std::cout << roots[i] <<" ";
            }
            std::cout << "" << std::endl;
        }

//if the user selects 2
        else if (num == 2)
        {
//ask for an input and then check to make sure it is an int
          std::cout<< "d: ";
          d = isDouble();
          std::cout << "";
          std::cout<< "e: ";
          e = isDouble();
          std::cout << "";
          std::cout<< "f: ";
          f = isDouble();;
          std::cout << "";

//runs Intersect Line method
          int intersect = math.intersectLineUnitCircle(d, e, f, xy);

//Displays solutions
          std::cout << "There are/is " << intersect << " point(s) of intersection:" << std::endl;
          for (int i=0; i < intersect ; i++)
          {
            std::cout << "(" << xy[0][i] <<", " << xy[1][i] << ")" <<std::endl;
          }
        }

//If the user selects 3
        else if (num == 3)
        {
//ask for an input and then check to make sure it is an int
          std::cout<< "Area: ";
          Area = isDouble();
          std::cout << "";
          std::cout<< "Extra Distance: ";
          Extra = isDouble();
          std::cout << "";
          std::cout<< "Minimum Length: ";
          minRequiredLength = isDouble();;
          std::cout << "";

//runs Room Dimensions method
          math.roomDimensions(Area, Extra, minRequiredLength, width, length);
          //Displays solutions
          if (width == 0 && length == 0)
          {
            throw NoIntersection();
          }
          std::cout << "Width can be: " << width << " Length can be: " << length << std::endl;
        }

//If the user selects 4
        else
        {
          std::cout << "Program Ended" << std::endl;
        }
      }

//if the user gives an int the isn't 1-4 then throws exception
      else if (num == 0 || num > 4)
      {
        throw std::logic_error("Your selection is out the given range");
      }
    }

//if the user enters anything but an int
    catch (std::invalid_argument)
    {
      std::cout << "Please enter an int" << std::endl;
      std::cout << "" << std::endl;
    }

//if the user enters an int that isn't 1-4
    catch (std::logic_error e)
    {
      std::cout << e.what() << std::endl;
    }

//If the room dimensions can't exist
    catch (CannotDetermineRoomDimensions e)
    {
      std::cout << e.what() <<std::endl;
    }

//If there are no intersections
    catch (NoIntersection e)
    {
      std::cout << e.what() <<std::endl;
    }

//If the discriminant is negative
    catch (NegativeDiscriminant e)
    {
      std::cout << e.what() <<std::endl;
    }
  }
}
