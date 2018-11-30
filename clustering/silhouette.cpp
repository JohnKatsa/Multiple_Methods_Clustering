/*Implementation of silhouette functions*/

#include <iostream>
#include "silhouette.h"

using namespace std;

// Function to calculate silhuette of every item
double silhuette_item(dataset* item, vector<dataset*> cluster1, vector<dataset*> cluster2, string metric)
{
  double sum1 = 0.0;
  double sum2 = 0.0;
  int counter1 = 0;
  int counter2 = 0;

  for(int i = 0; i < cluster1.size(); i++){
    sum1 += insert_distance_in_map(item,cluster1[i],metric);
    counter1++;
  }
  for(int i = 0; i < cluster2.size(); i++){
    sum2 += insert_distance_in_map(item,cluster2[i],metric);
    counter2++;
  }

  if(sum1 == 0)
    sum1 = 1;
  if(sum2 == 0)
    sum2 = 1;
  double mean1 = sum1/counter1;
  double mean2 = sum2/counter2;
  if(mean1 > mean2)
    return ((mean2-mean1)/(mean1));
  else
    return ((mean2-mean1)/(mean2));
}

double silhuette_cluster(unordered_map<string,int> center_pairs, vector<dataset*>* clusters, string metric, int index)
{

  double sum = 0.0;
  int counter = 0;
  vector<dataset*> cluster1 = clusters[index];
  vector<dataset*> cluster2;
  for(int i = 0; i < cluster1.size(); i++){
    cluster2 = clusters[center_pairs.find(cluster1[i]->get_id())->second];
    //cout << "SECOND: " << cluster2[0]->get_center()->get_id() << endl;
    double tmp = silhuette_item(cluster1[i],cluster1,cluster2,metric);
    if(!isnan(tmp))
      sum += tmp;
    counter++;
  }

  return (sum/counter);
}

void silhuette_whole(dataset* data, dataset** centers, int clusters, string metric)
{
  int i, j;
  unordered_map<string,int>::iterator it;

  // make array of vector for every cluster of datapoints
  vector<dataset*>* cluster_members = new vector<dataset*>[clusters];
  for(i = 0; i < n; i++){
    for(j = 0; j < clusters; j++){
      if(data[i].get_center() == centers[j]){
        cluster_members[j].push_back(&data[i]);
        break;
      }
    }
  }

  // calculate pairs of centers
  unordered_map<string,int> center_pairs = closer_centers(data,centers,clusters,metric);

  // for every cluster calculate its silhuette
  double sum = 0.0;
  int counter = 0;
  for(i = 0; i < clusters; i++){
    cout << "cluster  " << i << endl;
    double tmp = silhuette_cluster(center_pairs,cluster_members,metric,i);
    if(!isnan(tmp)){
      sum += tmp;
      cout << "cluster " << i << " " << tmp << endl;
    }
    else
      cout << "cluster " << i << " " << 0 << endl;
    counter++;
  }

  cout << "Whole silhuette: " << sum/counter << endl;

  delete[] cluster_members;
}
