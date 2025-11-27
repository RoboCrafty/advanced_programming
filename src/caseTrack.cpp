
#include <algorithm>
#include <array>
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <random>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
#include "helper.h"

const auto num_countries = 195;
int main() {

  // populate vector from worksheet 2
  std::vector<unsigned int> global_cases(num_countries, 0);
  populate_vector(global_cases);

  std::cout << "**********Choose**********\n"
            << "Press (d) for dummy data\n"
            << "Press (r) for real data" << std::endl;
  char choice;
  std::cin >> choice;

  std::unique_ptr<DataFrame> data_frame;
  if (choice == 'd') {
    // create DataFrame members for dummy data
    std::vector<std::vector<unsigned>> dummy_cases;
    std::vector<unsigned> dummy_population;

    for (size_t country_num = 0; country_num < countries.size(); ++country_num) {
      // reuse global_cases -
      dummy_cases.push_back(std::vector<unsigned>{global_cases[country_num]});
      dummy_population.push_back(1);
    }

    // TODO: Make a unique_ptr and assign it to the
    // data_frame declared above.
    // Make sure that cases = dummy_cases
    // and population = dummy_population
    // and regions = countries.
    // Hint: You need to dereference the pointer first.

    // Since this is not yet implemented, throw an exception.
    // This would make more sense in another function, which we
    // could then wrap in a try{}catch(){} block.
    throw std::runtime_error("Tracking is not yet implemented for dummy data.\n");
    // TODO: Remove the above exception, once implemented.
  } else if (choice == 'r') {
    // TODO: get a unique_ptr from read_from_csv()
    // and assign it to the data_frame variable.
    // This unique pointer provides you real data.

    throw std::runtime_error("Tracking is not yet implemented for real data.\n");
    // TODO: Remove the above exception, once implemented.
  } else {
    std::cout << "It's fine if you cannot make up your mind. Maybe another time then...\n";
    std::exit(EXIT_FAILURE);
  }

  // TODO: Use a for loop to print "cases" for each country using the
  // data_frame pointer you just initialized. Hint: You can use the existing
  // operator<< overload (implemented above) for printing vectors.

  // TODO: After implementing normalize_per_capita()
  // 1. Call normalize_per_capita
  // 2. Print out the new normalized case numbers.
  // Hint: You can use the example in the worksheet to
  // iterate over the map.
}
