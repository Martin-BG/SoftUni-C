#include <stdio.h>
#include <math.h>

int main(void)
{
    double side_a, side_b, side_c, p, triangle_area;

    printf("Enter side a: ");
    scanf("%lf", &side_a);

    printf("Enter side b: ");
    scanf("%lf", &side_b);

    printf("Enter side c: ");
    scanf("%lf", &side_c);

    p = (side_a + side_b + side_c) / 2.0;

    triangle_area = sqrt(p * (p - side_a) * (p - side_b) * (p - side_c));

    printf("Triangle surface is: %.6lf", triangle_area);

    return 0;
}
