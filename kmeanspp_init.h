/*Header for k-means++ initialization functions*/

#ifndef KMEANSPP_INIT_H
#define KMEANSPP_INIT_H

#include <iostream>
#include <cstring>
#include <time.h>
#include <set>
#include <iterator>
#include <random>
#include <math.h>
#include "data.h"
#include "configure.h"

float distance(type* point1, type* point2, std::string metric);
dataset** k_means_plus_plus(dataset* data, int k, int n, std::string metric);

#endif