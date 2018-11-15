/*Implementation of functions used in kmeans update*/

#include "kmeans_update.h"

dataset** kmeans_update(dataset* data, dataset** centers, int clusters, int n)
{
  int i, j, k;

  // keeps sum of every coordinate
  float** sums = new float*[clusters];
  for(i = 0; i < clusters; i++)
    sums[i] = new float[VECTORSIZE];

  // keeps number of items per cluster
  int* enumerate = new int[clusters];
  for(i = 0; i < clusters; i++)
    enumerate[i] = 0;

  // update data for every cluster to calculate new centers
  for(i = 0; i < n; i++){
    for(j = 0; j < clusters; j++){
      if(data[i].get_center() == centers[j]){
        for(k = 0; k < VECTORSIZE; k++)
          sums[j][k] += data[i].get_xij()[k];
      }
      enumerate[j] += 1;
      break;
    }
  }

  // compute new cluster centers
  dataset** newcenters = new dataset*[clusters];
  for(i = 0; i < clusters; i++){
    // allocate memory for new point (out of dataset)
    newcenters[i] = new dataset;
    newcenters[i]->set_xij(new type[VECTORSIZE]);
    type* tmp = newcenters[i]->get_xij();
    for(j = 0; j < VECTORSIZE; j++)
      tmp[j] = sums[i][j]/enumerate[i];
    // MAYBE SET AN ID
  }

  return newcenters;
}
