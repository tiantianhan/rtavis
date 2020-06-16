#include <iostream>
#include "vec3_tests.hpp"
#include "test.hpp"

int test(void){ //TODO commandline arguments
  bool pass;

  bool pass_vec3 = test_vec3(true);
  std::cout << std::boolalpha;
  std::cout << "\nTEST VEC3: " << pass_vec3 << '\n';

  pass = pass_vec3;
  std::cout << std::boolalpha;   
  std::cout << "\n\nALL TESTS: " << pass << '\n';
  return 0;
}
