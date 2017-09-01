/*
---------------------------
Author: Liam Ormiston
Date late updated: 10-24-16
Project: Lab 06 - EECS 268
Instructor: Dr. Gibbons
TA: Prasanth Vivekanandan
School: University of Kansas
Title: Maze Walker
---------------------------
*/

#ifndef MAZEEXCEPTION_H
#define MAZEEXCEPTION_H

class mazeException: public std::runtime_error
{
  public:
    /**
    * @post Creates an exception with the message
    */
    mazeException(const char* message);
};

#endif
