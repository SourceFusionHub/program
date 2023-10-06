#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_POINTS 100
#define NUM_CLUSTERS 3
#define MAX_ITERATIONS 1000

struct Point
{
    double x;
    double y;
};

struct Cluster
{
    struct Point centroid;
    int num_points;
};

double distance(struct Point a, struct Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
    struct Point points[NUM_POINTS];
    struct Cluster clusters[NUM_CLUSTERS];
    int assignments[NUM_POINTS];

    // Initialize random data points
    for (int i = 0; i < NUM_POINTS; i++)
    {
        points[i].x = (double)rand() / RAND_MAX * 100.0;
        points[i].y = (double)rand() / RAND_MAX * 100.0;
    }

    // Initialize cluster centroids randomly
    for (int i = 0; i < NUM_CLUSTERS; i++)
    {
        int random_index = rand() % NUM_POINTS;
        clusters[i].centroid = points[random_index];
    }

    // K-Means clustering
    int iterations = 0;
    while (iterations < MAX_ITERATIONS)
    {
        // Assign points to the nearest cluster
        for (int i = 0; i < NUM_POINTS; i++)
        {
            double min_distance = distance(points[i], clusters[0].centroid);
            int min_cluster = 0;
            for (int j = 1; j < NUM_CLUSTERS; j++)
            {
                double d = distance(points[i], clusters[j].centroid);
                if (d < min_distance)
                {
                    min_distance = d;
                    min_cluster = j;
                }
            }
            assignments[i] = min_cluster;
        }

        // Update cluster centroids
        for (int i = 0; i < NUM_CLUSTERS; i++)
        {
            double sum_x = 0.0;
            double sum_y = 0.0;
            int num_assigned = 0;
            for (int j = 0; j < NUM_POINTS; j++)
            {
                if (assignments[j] == i)
                {
                    sum_x += points[j].x;
                    sum_y += points[j].y;
                    num_assigned++;
                }
            }
            clusters[i].centroid.x = sum_x / num_assigned;
            clusters[i].centroid.y = sum_y / num_assigned;
            clusters[i].num_points = num_assigned;
        }

        iterations++;
    }

    // Print cluster centroids
    for (int i = 0; i < NUM_CLUSTERS; i++)
    {
        printf("Cluster %d: Centroid (%.2f, %.2f), Number of Points: %d\n", i + 1, clusters[i].centroid.x, clusters[i].centroid.y, clusters[i].num_points);
    }

    return 0;
}
