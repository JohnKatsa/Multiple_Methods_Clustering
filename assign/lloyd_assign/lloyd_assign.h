/*Definition of Lloyd's assignment algorithm*/

#ifndef LLOYDS_ASSIGN_H
#define LLOYDS_ASSIGN_H

#include <iostream>
#include "../../clustering/cluster.h"

class dataset;

// returns index of min value
int find_min(float* list, int k);
dataset* lloyd(dataset* data, dataset** centers, int n, int k, std::string metric);

#endif
