/*Main function*/

#include "cluster.h"

using namespace std;

int main(int args, char** argv)
{
  // get command line arguments
  char *inputFile, *configurationFile, *outputFile, *metric;
  read_arguments(args,argv,&inputFile,&configurationFile,&outputFile,&metric);

  // read input and make database
  dataset* data = read_inputFile(inputFile,&n);

  // configure system
  int clusters, hash_functions, hash_tables;
  configurate(configurationFile,&clusters,&hash_functions,&hash_tables);

  // INITIALIZE
  //dataset** centers = random_selection_of_k_points(data,clusters,n);
  dataset** centers = k_means_plus_plus(data,clusters,n,metric);
  for(int i = 0; i < clusters; i++)
    cout << centers[i] << " ";
  cout << endl;
  //////////////////////////////////////////////////////////////////

  // ASSIGN (FOR LSH/CUBE, MORE INITIALIZATION NEEDED)
  hashtable** table = lsh_main(data,metric);
  //hashtable** table = cube_main(data,metric);

  int k = 4, L = 5, R = 100;
  for(int i = 0; i < clusters; i++){
    data = nearest_neighbours(data,centers[i],k,VECTORSIZE,L,table,metric,R,0,outputFile);   // LSH-neighnours
  }
  //data = lloyd(data,centers,n,clusters,metric);
  //////////////////////////////////////////////////////////////////

  // UPDATE
  dataset** newcenters = kmeans_update(data,centers,clusters,n);
  /////////////////////////////////////////////////////////////////

  // clean up
  clean_data(data,n);

  return 0;
}
