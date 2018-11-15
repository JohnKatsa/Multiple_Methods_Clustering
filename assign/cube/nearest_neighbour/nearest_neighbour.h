/*Definition of nearest neighbours functions*/

#ifndef NEAREST_NEIGHBOUR_H
#define NEAREST_NEIGHBOUR_H

#include <iostream>
#include "../../../clustering/cluster.h"

class dataset;

using namespace std;

dataset* find_neighbours(dataset* data, hashtable t, dataset* query, int d, string family, float range, int* g, float* new_min, int k, int flag, char* outputFile);
dataset* nearest_neighbours(dataset* data, dataset* query, int k, int d, int L, hashtable** table, string family, float range, int flag, char* outputFile);

#endif
