#ifndef POINT_H
#define POINT_H

typedef struct Point Point;

Point* CreatePoint(double x, double y);
void DestroyPoint(Point* point);
void MovePoint(Point* point, double dx, double dy);

#endif