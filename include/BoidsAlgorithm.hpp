#pragma once
#include "const.hpp"
void simulate(const float& dt,std::vector<bird>& birds,std::vector<bird>& predators);
v2f Separation(const std::vector<bird>& birds ,const bird& curr);
v2f Alignment(const std::vector<bird>& birds ,const bird& curr);
v2f Cohesion(const std::vector<bird>& birds ,const bird& curr);
v2f Avoid(const std::vector<bird>& predators ,const bird& curr);
v2f Hunt(const std::vector<bird>& birds , const bird& curr);
