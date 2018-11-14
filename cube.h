/*Definition of hypercube functions*/

#ifndef CUBE_H
#define CUBE_H

#include "cluster.h"
#include "lsh_item.h"
#include "lsh_bucket.h"
#include "lsh_hashtable.h"

hashtable** cube_main(dataset* data, std::string family);

#endif
