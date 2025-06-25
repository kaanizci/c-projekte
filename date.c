#include <stdio.h>

int main() {
    int mm, dd, yy;
    printf("Enter date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &mm, &dd, &yy);

    // %04d = vierstellig mit führenden Nullen (z. B. 0001)
    // %02d = zweistellig mit führenden Nullen (z. B. 02)
    printf("You entered the date %04d%02d%02d\n", yy, mm, dd);

    return 0;
}