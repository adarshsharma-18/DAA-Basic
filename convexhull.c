#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a point
typedef struct {
    int x, y;
} Point;

// Function to swap two points
void swap(Point* p1, Point* p2) {
    Point temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Function to find the next to top in a stack
Point nextToTop(Point stack[], int* top) {
    Point p = stack[*top];
    (*top)--;
    return stack[*top];
}

// Function to calculate the square of distance between two points
int distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// Function to perform the graham scan to find the convex hull
void convexHull(Point points[], int n) {
    // Find the point with the lowest y-coordinate (and the leftmost one in case of ties)
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }
    swap(&points[0], &points[min]);

    // Sort points based on their polar angle with respect to p0
    Point p0 = points[0];
    qsort(&points[1], n - 1, sizeof(Point), [](const void* p1, const void* p2) {
        Point* point1 = (Point*)p1;
        Point* point2 = (Point*)p2;

        int orientation = (point1->y - p0.y) * (point2->x - p0.x) - (point2->y - p0.y) * (point1->x - p0.x);
        if (orientation == 0)
            return distSq(p0, *point1) < distSq(p0, *point2) ? -1 : 1;
        return (orientation < 0) ? -1 : 1;
    });

    // Initialize the stack to store points on the convex hull
    Point stack[n];
    int top = -1;
    stack[++top] = points[0];
    stack[++top] = points[1];

    // Iterate over the remaining points
    for (int i = 2; i < n; i++) {
        while (top >= 1 && ((stack[top].y - stack[top - 1].y) * (points[i].x - stack[top].x) - (stack[top].x - stack[top - 1].x) * (points[i].y - stack[top].y)) <= 0)
            top--;
        stack[++top] = points[i];
    }

    // Print the points on the convex hull
    printf("Convex Hull Points:\n");
    for (int i = 0; i <= top; i++)
        printf("(%d, %d)\n", stack[i].x, stack[i].y);
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    Point points[n];
    printf("Enter the coordinates of the points:\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &points[i].x, &points[i].y);

    convexHull(points, n);

    return 0;
}
