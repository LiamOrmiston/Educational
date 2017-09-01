/*
---------------------------
Author: Liam Ormiston
Date late updated: 9-6-16
Project: Lab 01 - EECS 268
Instructor: Dr. Gibbons
TA: Prasanth Vivekanandan
School: University of Kansas
Title: Voter Registration
---------------------------
*/

#include "executive.h"
#include "vpr.h"
#include <iostream>
#include <fstream>
#include <string>

//creates a temporary char array (fileName) in order to read the text file
//that is given upon initializing the program.
Executive::Executive(char fileName[128])
{
//opens file
    std::ifstream VIDfile;
    VIDfile.open(fileName);

//if the file can be opened properly then this code is run
    if(VIDfile.is_open())
    {
        exist = true;
//taks the first line of code that is assumed to be the given
//number of entries
        VIDfile >> n_records;
//creates an object array the size of the number of entries given
        records = new VPR [n_records];

//will read line by line inputing the different entries that are
//seperated by a space into the proper strings
        for(int i=0; i<n_records; i++)
        {
            std::string firstName;
            std::string lastName;
            std::string aff;
            int age;

            VIDfile >> firstName;
            VIDfile >> lastName;
            VIDfile >> age;
            VIDfile >> aff;

//Then takes the strings and inputs them into the array
            records[i].setfirstName(firstName);
            records[i].setlastName(lastName);
            records[i].setage(age);
            records[i].setaff(aff);
        }
    }
    else
    {
        exist = false;
    }
//closes file
    VIDfile.close();
}
//deconstructor
Executive::~Executive()
{
  delete [] records;
}

//main run method
void Executive::run()
{
//checks to see if the file exists. If it doesn't then the program displays
//that the file is unreadable.

  if (!exist)
  {
        std::cout << "Unreadable file" <<std::endl;
  }

//if the file does exist then the program prompts the user with different
//options the user can do.
//The user can either search by last name, age rang between two numbers,
//search by affiliation, report the number of people with a certain
//affiliation, or close the program. This is on a loop until the user
//closes the program.

  while (exist)
    {
        char choice = ' ';
        std::cout << "-------------------------------------------" <<std::endl;
        std::cout << "1: Query last name" <<std::endl;
        std::cout << "2: Query age range" <<std::endl;
        std::cout << "3: Query affiliations" <<std::endl;
        std::cout << "4: Report number of people with affiliation" <<std::endl;
        std::cout << "5: Exit" <<std::endl;
        std::cout << "-------------------------------------------" <<std::endl;

//begining of loop
        do {

          choice = '0';
          std::cin >> choice;

//search by last name
          if(choice == '1')
          {
              std::string temp;
              std::cout << "Last name: " <<std::endl;
              std::cin >> temp;
              for (int i=0; i<n_records; i++)
              {
                records[i].getlastName(temp);
              }
          }

//search by an age range
          else if(choice == '2')
          {
              int low = 0;
              int high = 0;
              std::cout << "Low: " <<std::endl;
              std::cin >> low;
              std::cout << "High: " <<std::endl;
              std::cin >> high;
              for (int i=0; i<n_records; i++)
              {
                records[i].getage(low, high);
              }
          }

//search by affiliation
          else if(choice == '3')
          {
            std::string temp;
            std::cout << "Affiliation: " <<std::endl;
            std::cin >> temp;
            for (int i=0; i<n_records; i++)
            {
              records[i].getaff(temp);
            }
          }

//display the number of people registered with a certain
//affiliation
          else if(choice == '4')
          {
            int temp = 0;
            std::string aff;
            std::cout << "Affiliation: " <<std::endl;
            std::cin >> aff;
            for (int i=0; i<n_records; i++)
            {

              temp += records[i].getaffCount(aff);
            }
            std::cout << "There are " << temp << " " << aff << " registered voters" << std::endl;
          }

//exits the program
          else if(choice == '5')
          {
            exit (0);
          }

//if the user inputs anything else other than numbers 1-5 then the
//user is prompted to try again.
          else
          {
              std::cout << "Incorrect input. Please try again. " <<std::endl;
              break;
          }
        } while(choice !='1' && choice !='2' && choice !='3' && choice !='4');
    }
}
