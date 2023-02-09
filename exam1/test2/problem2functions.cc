// Minh My Tran - CSCE 240 003 - Exam 1 

#include <cmath>

double Distance(double x1, double y1, double x2 = 0, double y2 = 0) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int OnCircle(double cx, double cy, double r, double x, double y) {
    double d = sqrt((x - cx) * (x - cx) + (y - cy) * (y - cy));
    if (d < r) {
        return -1;
    } else if (d == r) {
        return 0;
    } else {
        return 1;
    }
}

bool OnLine(double x1, double y1, double x2, double y2, double x3, double y3) {
    return (y3 - y1) * (x2 - x1) == (y2 - y1) * (x3 - x1);
}