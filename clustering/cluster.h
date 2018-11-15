/*Header used for Main*/

#ifndef CLUSTER_H
#define CLUSTER_H

#include <iostream>
#include <list>
#include <limits>

typedef std::numeric_limits< double > dbl;
typedef double type;

#include "../configuration/data.h"
#include "../configuration/configure.h"
#include "../init/Random_Selection_of_k_points/random_init.h"
#include "../init/kmeanspp/kmeanspp_init.h"
#include "../assign/cube/lsh/lsh.h"
#include "../assign/cube/cube.h"
#include "../assign/lloyd_assign/lloyd_assign.h"
#include "../assign/cube/nearest_neighbour/nearest_neighbour.h"
#include "../update/kmeans_update/kmeans_update.h"

#endif
