#ifndef PATIENT_H
#define PATIENT_H

#include <string>
class Patient
{
public:
  Patient();
  Patient(std::string name, int priority);
  std::string getName () const;
  int getPriority () const;
  bool operator <= (const Patient&  rhs);
  void operator = (const Patient& rhs);
  bool operator > (const Patient&  rhs);
  std::string m_name;
  int m_priority;
private:

};
#endif
