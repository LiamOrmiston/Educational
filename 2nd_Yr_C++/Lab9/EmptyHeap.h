#ifndef EMPTYHEAP_H
#define EMPTYHEAP_H
#include <string>
#include <stdexcept>
class EmptyHeap: public std::logic_error
{
public:
  EmptyHeap(const std::string& message);
};
#endif
