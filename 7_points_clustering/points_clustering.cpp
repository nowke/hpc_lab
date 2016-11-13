#include <iostream>
#include <cstdlib> // or <stdlib.h> rand, srand
#include <ctime> // or <time.h> time
#include <omp.h>
#include <math.h>

#define K 4

using namespace std;

int num_threads;
long num_points;
long** points; // 2D array points[x][0] -> point location, points[x][1] -> index of cluster to which point belongs to
double cluster_mean[K]; // Holds mean value for each cluster (Total K)
long cluster_count[K]; // Number of points in each cluster (Total K)

void populate_points() {
    // Dynamically allocate points[num_points][2] 2D array
    points = new long*[num_points];
    for (long i=0; i<num_points; i++)
        points[i] = new long[2];

    // Fill random points (0 to 100)
    srand(time(NULL));
    for (long i=0; i<num_points; i++) {
        points[i][0] = rand() % 100;
        points[i][1] = -1;
    }

    // Initialize cluster_mean & cluster_count
    for (int i=0; i<K; i++) {
        cluster_mean[i] = points[i][0]; // Some random point
        cluster_count[i] = 1;
        points[i][1] = i;
    }
}

void cluster_points() {
    #pragma omp parallel for num_threads(num_threads)
    for (long i=0; i<num_points; i++) {
        double min_dist = 1000, cur_dist = -1;
        int cluster_index = -1;
        for (int j=0; j<K; j++) {
            cur_dist = fabs((double)points[i][0] - cluster_mean[j]);
            if (cur_dist < min_dist) {
                min_dist = cur_dist;
                cluster_index = j;
            }
        }
        points[i][1] = cluster_index;
        #pragma omp critical
        {
            // Calculate Cluster mean
            cluster_mean[cluster_index] = ((cluster_mean[cluster_index] * cluster_count[cluster_index]) + points[i][0]) /
                                            ( cluster_count[cluster_index] + 1);
            cluster_count[cluster_index]++;
        }
    }
}

int main(int arc, char* argv[]) {
    num_points = atol(argv[1]);
    num_threads = atoi(argv[2]);
    populate_points();
    double t1 = omp_get_wtime();
    cluster_points();
    double t2 = omp_get_wtime();
    double t = (t2 - t1) * 1000;

    cout << "Time Taken: " << t << "ms" << endl;
}
