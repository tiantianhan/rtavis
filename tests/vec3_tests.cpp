#include <iostream>

#include "vec3_tests.hpp"
#include "..\src\utils\vec3.hpp"

bool test_init(bool verbose);
bool test_access(bool verbose);
bool test_immutable(bool verbose);
bool test_pluseq(bool verbose);

bool test_vec3(bool verbose){
  std::cout << std::boolalpha;
  bool pass_init = test_init(verbose);
  bool pass_access_op = test_access(verbose);
  bool pass_pluseq = test_pluseq(verbose);

  bool pass = pass_init && pass_access_op && pass_pluseq;
  return pass;
}

bool test_init(bool verbose){
  // Test initialize and access
  Vec3 v1 = Vec3();
  bool pass_init = (v1.x() == 0) && (v1.y() == 0) && (v1.z() == 0);
  if(verbose) std::cout << "Test initialize and access: " << pass_init << '\n';

  return pass_init;
}

bool test_access(bool verbose){
  // Test access operator
  Vec3 v2 = Vec3(-1, 4.9, 0);
  bool pass_access_op = (v2[0] == -1.0) && (v2[1] == 4.9) && (v2[2] == 0.0);
  if(verbose) std::cout << "Test access operator: " << pass_access_op << '\n';

  return pass_access_op;
}

bool test_pluseq(bool verbose){
  // Test += operator
  Vec3 v1 = Vec3();
  const Vec3 v2 = Vec3(-1, 4.9, 0);
  v1 += v2;
  v1 += v2;
  bool pass_pluseq = (v1[0] == -2.0) && (v1[1] == 9.8) && (v1[2] == 0.0);
  if(verbose) std::cout << "Test +=: " << pass_pluseq << '\n';

  return pass_pluseq;
}
