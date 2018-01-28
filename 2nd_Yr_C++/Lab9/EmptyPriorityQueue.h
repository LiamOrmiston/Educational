#ifndef EMPTYPRIORITYQUEUE_H
#define EMPTYPRIORITYQUEUE_H
#include <string>
#include <stdexcept>
class EmptyPriorityQueue: public std::logic_error
{
public:
  EmptyPriorityQueue(const std::string& message);
};
#endif
