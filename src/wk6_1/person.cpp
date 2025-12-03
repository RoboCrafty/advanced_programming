#include "person.h"

// 1. TODO: Implement a constructor that takes a
// location array and creates a unique_id for the
// object.
Person::Person(std::array<double, 2> loc)
 : curr_location{loc}, _id{counter++}
{
}
// 2. TODO: Implement the copy constructor

Person::Person(const Person& other)
 : status{other.status}, curr_location{other.curr_location}, _id{counter++}
{ 
}

// 3. TODO: Implement the copy assignment operator.

Person &Person::operator=(Person const &other) {
  status = other.status;
  curr_location = other.curr_location;
  return *this;
}

// You can find the signatures of these functions in
// the header file. :)

std::array<double, 2> Person::get_location() const {
  return curr_location;
}

unsigned Person::get_id() const {
  return _id;
}

void Person::advance() {
  // for now, do advance doesn't
  // do anything sensible
  curr_location[0] += 0.1;
  curr_location[1] -= 0.1;
}
