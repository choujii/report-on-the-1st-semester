#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Xy{
    float x,y;
} Xy;
static const Xy *xy_origin;
int cmp_polar_angle(const void *p1, const void *p2){
    const Xy *xy1 = p1, *xy2 = p2;
    Xy
    origin_xy1 = {xy1->x - xy_origin->x, xy1->y - xy_origin->y},
    origin_xy2 = {xy2->x - xy_origin->x, xy2->y - xy_origin->y};

    long long area =
            (long long) origin_xy1.x * origin_xy2.y -
            (long long) origin_xy1.y * origin_xy2.x;
    return (area > 0) - (area < 0);
}

float distance(Xy p1, Xy p2)
{
    float dx = p2.x - p1.x, dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}
float traverse_clockwise(Xy poly[], int n)
{
    for (int i = 1; i < n; ++i)
        if (poly[i].y < poly[0].y){
            Xy temp =poly[0];
            poly[0] = poly[i];
            poly[i] = temp;
        }
    xy_origin = &poly[0];
    qsort(poly + 1, n - 1, sizeof *poly, cmp_polar_angle);

    float f = 0;
    for (int i = 0; i < n; ++i)
    {
       f += distance(poly[i], poly[(i + 1) % n]);
    }
    return f;
}
int main (){
    float rect[] = {1,5,7,1,7,5,1,1};
    int pointsCount = 4;
    float star[] = {3.97, 0.82, 2.26, 3.69, 5.39, 2.16, 2.03, 2.11, 5.36, 4.06};
    int pointsCount1 = 5;
    float enneagon[] = { 76, 67.1, -8.3, 18, 55, 93.3, 77, 33, 21.3, 99, -20, 50, -8.3, 82, 55, 6.7,  21.3, 0.76};
    int pointsCount2 = 9;
    float traverse = traverse_clockwise(enneagon, pointsCount2);
    printf("%f", traverse);
}
