#include <stdio.h>

#define PI 3.1415927f  // define π as a float constant

int main() {
    float radius;  
    float volume;

    
    printf("What is the radius of the sphere in meters? Please enter a number: ");
    scanf("%f", &radius);  // read the radius from user input
    
    volume = (4.0f / 3.0f) * PI * radius * radius * radius;
    printf("The volume of a sphere with a radius of %.1f meters is %.6f cubic meters.\n", radius, volume);

    return 0;
}