/*Implementation of nearest neighbour functions*/

#include "nearest_neighbour.h"

list<int> hamming_distance_on_random_bit(list<int> l, int* x){
  *x = *x+1;

  return l;
}

dataset* find_neighbours(dataset* data, hashtable t, dataset* query, int d, string family, float range, int* g, int fi, int k, int flag, char* outputFile){
  int M = 1;
  bucket* b = t.get_bucket()->get_bucket();
  type* p;
  int* g_bucket;
  type* point = query->get_xij();
  float f;

  while(b != NULL){
    p = b->get_point()->get_p();

    if(!family.compare("euclidean")){
      g_bucket = b->get_point()->get_g();
      if(compare_g(g,g_bucket,k)){
        b = b->get_bucket();
        continue;
      }
    }

    f = distance(p,point,family);
    if(f <= range){
      // for the LSH - nearest neighbours
      if((mapping[b->get_point()->get_index()] &&
        (distance(data[b->get_point()->get_index()].get_center()->get_xij(),p,family) > f)) ||
         !mapping[b->get_point()->get_index()]){  // because if the new is smaller or no old then change
        data[b->get_point()->get_index()].set_center(query);
        mapping[b->get_point()->get_index()] = 1;
      }
    }

    b = b->get_bucket();

    // check for M points checked in hypercube
    if((--M == 0) && flag)
      break;
  }

  return data;
}

dataset* nearest_neighbours(dataset* data, dataset* query, int k, int d, int L, hashtable** table, string family, float range, int flag, char* outputFile){
  int M = 1, probes = 1;
  int i, fi;
  int* g;
  euclidean_return e;

  string tmp;
  string min_point = "NULL";
  float min_distance = 10000.0, new_min;

  for(i = 0; i < L; i++){
    if(!family.compare("cosine"))
      fi = cosine_similarity(k,d,query->get_xij());
    else{
      e = euclidean(k,d,query->get_xij(),flag,i);    // because it returns both g and fi
      fi = e.fi;
      g = e.g;
    }

    // check for M points checked
    if((--M <= 0) && flag)
      break;

    // if statement to determine probes number exploration
    list<int> l;
    if(!probes) // if it is 0, that means we are in lsh method
      probes = 1;

    // first probe (original)
    data = find_neighbours(data,table[i][fi%tablesize],query,d,family,range,g,fi,k,flag,outputFile);
    int ham = 1;
    // for every probe find min (works for both lsh and cube)
    for(int z = 0; z < probes; z++){

      // cube
      if(flag){
        l = hamming_distance_on_random_bit(l,&ham);
      }

      data = find_neighbours(data,table[i][ham%tablesize],query,d,family,range,g,ham,k,flag,outputFile);
    }
  }

  return data;
}
