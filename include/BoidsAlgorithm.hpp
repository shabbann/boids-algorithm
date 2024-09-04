#pragma once
#include "const.hpp"
void update(std::vector<bird>& birds);
v2f Separation(std::vector<bird>& birds ,const bird& curr);
v2f Alignment(std::vector<bird>& birds ,const bird& curr);
v2f Cohesion(std::vector<bird>& birds ,const bird& curr);
