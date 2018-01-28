#include "Patient.h"
//constructor defining name and priority with values if there are no values given
Patient::Patient()
{
  m_name = "temp";
  m_priority = 0;
}

//constructor if there are name and priority values given
Patient::Patient(std::string name, int priority)
{
  m_name = name;
  m_priority = priority;
}

//get name returns name
std::string Patient::getName () const
{
  return(m_name);
}

//get priority returns priority
int Patient::getPriority () const
{
  return(m_priority);
}


//** OVERLOADED OPERATORS **//

void Patient::operator = (const Patient& rhs)
{
  m_name = rhs.m_name;
  m_priority = rhs.m_priority;
}
bool Patient::operator <= (const Patient&  rhs)
{
  return(m_priority <= rhs.m_priority);
}

bool Patient::operator > (const Patient&  rhs)
{
  return(m_priority > rhs.m_priority);
}
