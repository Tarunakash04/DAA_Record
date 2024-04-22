#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_CITIES 10
typedef struct {
    double x, y;
} City;
double dis(City city1, City city2) {
    return sqrt(pow(city1.x - city2.x, 2) + pow(city1.y - city2.y, 2));
}
void input(int n, City cities[]) {
    int i;
    printf("Enter the coordinates of each city:\n");
    for (i = 0; i < n; i++) {
        printf("City %d: ", i + 1);
        scanf("%lf %lf", &cities[i].x, &cities[i].y);
    }
}
void display(int n, City cities[]) {
    int i,j;
    printf("Distance Matrix:\n");
    printf("       ");
    for (i = 0; i < n; i++) {
        printf("%6d", i + 1);
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("City %d:", i + 1);
        for (j = 0; j < n; j++) {
            if (i == j) {
                printf("   -  ");
            } else {
                double dist = dis(cities[i], cities[j]);
                printf("%6.2f", dist);
            }
        }
        printf("\n");
    }
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void trvl(int path[], int start, int n, double *min, int minPath[], City cities[]) {
    int i;
    if (start == n - 1) {
        double totalDistance = 0.0;
        for (i = 0; i < n - 1; i++) {
            totalDistance += dis(cities[path[i]], cities[path[i + 1]]);
        }
        totalDistance += dis(cities[path[n - 1]], cities[path[0]]); // Return to starting city

        if (totalDistance < *min) {
            *min = totalDistance;
            for (i = 0; i < n; i++) {
                minPath[i] = path[i];
            }
        }
    } else {
        for (i = start; i < n; i++) {
            swap(&path[start], &path[i]);
            trvl(path, start + 1, n, min, minPath, cities);
            swap(&path[start], &path[i]);
        }
    }
}
void shortest(int n, int path[]) {
    int i;
    printf("Shortest path: ");
    for (i = 0; i < n; i++) {
        printf("%d ", path[i] + 1);
    }
    printf("\n");
}
int main() {
    int n;
    City cities[MAX_CITIES];
    int path[MAX_CITIES];
    int i;
    printf("Enter the number of cities (max %d): ", MAX_CITIES);
    scanf("%d", &n);
    if (n <= 0 || n > MAX_CITIES) {
        printf("Invalid number of cities.\n");
        return 1;
    }
    input(n, cities);
    display(n, cities);
    for (i = 0; i < n; i++) {
        path[i] = i;
    }
    double min = INFINITY;
    int minPath[MAX_CITIES];
    trvl(path, 0, n, &min, minPath, cities);
    printf("\nTotal distance traveled: %.2f\n", min);
    shortest(n, minPath);
    return 0;
}
