all: cluster

cluster : cluster.o configure.o data.o random_init.o kmeanspp_init.o lsh_item.o lsh_bucket.o lsh_hashtable.o lsh.o cube.o lloyd_assign.o nearest_neighbour.o kmeans_update.o pam_lloyd_update.o
	g++ -std=c++11 -o cluster cluster.o configure.o data.o random_init.o kmeanspp_init.o lsh_item.o lsh_bucket.o lsh_hashtable.o lsh.o cube.o lloyd_assign.o nearest_neighbour.o kmeans_update.o pam_lloyd_update.o -lm -g

cluster.o : cluster.cpp cluster.h
	g++ -std=c++11 -c cluster.cpp

configure.o : configure.cpp configure.h
	g++ -std=c++11 -c configure.cpp

data.o : data.cpp data.h
	g++ -std=c++11 -c data.cpp

random_init.o : random_init.cpp random_init.h
	g++ -std=c++11 -c random_init.cpp

kmeanspp_init.o : kmeanspp_init.cpp kmeanspp_init.h
	g++ -std=c++11 -c kmeanspp_init.cpp

lsh_item.o : lsh_item.cpp lsh_item.h
	g++ -std=c++11 -c lsh_item.cpp

lsh_bucket.o : lsh_bucket.cpp lsh_bucket.h
	g++ -std=c++11 -c lsh_bucket.cpp

lsh_hashtable.o : lsh_hashtable.cpp lsh_hashtable.h
	g++ -std=c++11 -c lsh_hashtable.cpp

lsh.o : lsh.cpp lsh.h
	g++ -std=c++11 -c lsh.cpp

cube.o : cube.cpp cube.h
	g++ -std=c++11 -c cube.cpp

lloyd_assign.o : lloyd_assign.cpp lloyd_assign.h
	g++ -std=c++11 -c lloyd_assign.cpp

nearest_neighbour.o : nearest_neighbour.cpp nearest_neighbour.h
	g++ -std=c++11 -c nearest_neighbour.cpp

kmeans_update.o : kmeans_update.cpp kmeans_update.h
	g++ -std=c++11 -c kmeans_update.cpp

pam_lloyd_update.o : pam_lloyd_update.cpp pam_lloyd_update.h
	g++ -std=c++11 -c pam_lloyd_update.cpp

clean :
	rm cluster cluster.o configure.o data.o random_init.o kmeanspp_init.o lsh.o cube.o lsh_item.o lsh_bucket.o lsh_hashtable.o lloyd_assign.o nearest_neighbour.o kmeans_update.o pam_lloyd_update.o
