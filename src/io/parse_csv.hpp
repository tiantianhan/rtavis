#ifndef PARSE_CSV_HPP
#define PARSE_CSV_HPP

#include <fstream>
#include "../hittable/hittable_list.hpp"

HittableList parse_csv_for_hittable_list(std::ifstream &input_file);

#endif