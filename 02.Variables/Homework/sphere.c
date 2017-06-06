#include <stdio.h>
#include <math.h>

int main(void)
{
    double radius, surface, volume, perimeter;

    printf("Enter sphere radius: ");
    scanf("%lf", &radius);

    surface = 4.0 * M_PI * radius * radius;
    volume = 4.0 / 3.0 * M_PI * radius * radius * radius;
    perimeter = 2.0 * M_PI * radius;

    printf("The perimeter is: %.6lf\n", perimeter);
    printf("The surface is  : %.6lf\n", surface);
    printf("The volume is   : %.6lf\n", volume);
    return 0;
}
