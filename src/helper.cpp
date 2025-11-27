
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

// !!!this is different than before!!!


void write_to_csv(std::vector<unsigned int>& global_cases, std::string filename) {
  /*
   * Generates a csv (comma separated values) of (country, cases).
   * This creates a file "global_cases.csv" by default in the
   * current folder. We use the <fstream> header for writing to the
   * file.
   */

  // open file stream for output
  std::ofstream csv_file(filename);

  // csv column headers
  csv_file << "country,cases\n";

  for (size_t i = 0; i < global_cases.size(); i++) {

    /* We can write to a file in the same way as we write to std::cout.
     * This is because both are implemented as "streams"
     *
     * We do not need to pass the "countries" array to our
     * "function" since it is global. Avoid doing this,
     * we will learn better ways to organize our code later.
     */
    csv_file << countries[i] << "," << global_cases[i] << "\n";
  }

  csv_file.close();
}

void populate_vector(std::vector<unsigned int>& global_cases) {
  /*
   * Populate a vector with pseudo-random data generated using the mersenne
   * twister engine from <random>. The seed is set to 0 so that everyone
   * gets the same sequence of 'random' numbers.
   */

  auto seed = 0;
  auto min = 0;
  auto max = 10000;

  // mt19337: a pseudo random generator using the mersenne
  // twister engine ( from <random> )
  // The value of gen will be updated every time we access it.
  std::mt19937 gen(seed);
  // uniform_int_distribution: use the mersenne twister
  // engine to generate a uniform random distribution over (min, max)
  std::uniform_int_distribution<unsigned int> unif_distrib(min, max);

  /* 3. populate vector global_cases with random data
   * You can generate samples from the uniform distribution above like so:
   * unif_distrib(gen)
   */

  // 3. solution
  for (auto& elem : global_cases) {
    elem = unif_distrib(gen);
  }
}

std::ostream& operator<<(std::ostream& os, std::vector<unsigned> vec) {
  for (const auto& elem : vec) {
    os << elem << " ";
  }
  os << '\n';
  return os;
}

std::ostream& operator<<(std::ostream& os, std::vector<double> vec) {
  for (const auto& elem : vec) {
    os << elem << " ";
  }
  os << '\n';
  return os;
}
/********************************************
** Welcome back!
*********************************************
**
*/



/*
** You do not "need" to read this function right now.
*/
std::unique_ptr<DataFrame> read_from_csv(std::string filename) {
  /*
  ** Read from a csv and populate a DataFrame.
  ** Return a unique_ptr to this DataFrame.
  */

  std::ifstream database(filename);

  std::unique_ptr<DataFrame> data = std::make_unique<DataFrame>();

  // parse data into these vars
  unsigned day_of_month;
  unsigned cases;
  std::string region;
  unsigned population;
  std::string curr_region = "";

  std::string line;
  // throw away first line: contains csv header
  std::getline(database, line);

  // keep track of region number
  // region names are repeated in csv
  auto region_num = -1;

  // while lines in csv
  while (std::getline(database, line)) {
    std::replace(line.begin(), line.end(), ',', ' ');
    std::stringstream line_stream(line);
    // stringstream breaks on spaces
    line_stream >> day_of_month >> cases >> region >> population;

    // new region in csv
    if (curr_region != region) {
      // -> operator: dereference pointer + access member / field
      // e.g. imagine: DataFrame* data;
      // then to access the cases field
      // we need: (*data).cases == data->cases
      curr_region = region;
      data->regions.push_back(region);
      data->population.push_back(population);
      data->cases.push_back(std::vector<unsigned>{});

      ++region_num;
    }

    data->cases[region_num].push_back(cases);
  }
  return data;
}

std::map<std::string, std::vector<double>> normalize_per_capital(std::unique_ptr<DataFrame>& data_frame) {
  /*
  ** Normalize cases in data_frame by population i.e.
  ** compute cases per 100,000 people in each country.
  ** Returns a std::map<std::string, std::vector<double>>
  */

  // TODO: YOUR SOLUTION HERE

  /*
  ** 1. Extract references to regions, cases, and population
  **    from data_frame.
  ** 2. Declare a map<std::string, std::vector<double>>
  **    called cases_normalized. The std::string refers to the
  **    name of the region, while the associated vector contains
  **    normalized cases (per 100,000 people) in the region.
  ** 3. Populate the cases_normalized map by computing the cases
  **    per 100'000 people in the respective country. You'll need
  **    nexted loops( for(regions) { for(cases) } ).
  **    Hint: cases_normalized[name_of_region] gives you access
  **    to the associated vector.
  ** 4. Change the returned object to cases_normalized i.e.
  **    the map you just populated.
  */
  return std::map<std::string, std::vector<double>>{};
}