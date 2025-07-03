#include <stdio.h>
#include <limits.h>
#include <float.h>

// Dieses Programm zeigt die Bereiche der verschiedenen Datentypen in C an.
// Es nutzt die Header-Dateien <limits.h> für Ganzzahlen und <float.h> für Gleitkommazahlen.
// Die Bereiche werden mit den Makros SCHAR_MIN, SCHAR_MAX, UCHAR_MAX, SHRT_MIN, SHRT_MAX,
// USHRT_MAX, INT_MIN, INT_MAX, UINT_MAX, LONG_MIN, LONG_MAX, ULONG_MAX, FLT_MIN, FLT_MAX, DBL_MIN und DBL_MAX
// aus den entsprechenden Header-Dateien angezeigt.

int main() {
    // Integer-Bereiche
    printf("Integer-Bereiche:\n");
    printf("signed char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char: 0 to %d\n", UCHAR_MAX);
    printf("short: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: 0 to %d\n", USHRT_MAX);
    printf("int: %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int: 0 to %u\n", UINT_MAX);
    printf("long: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long: 0 to %lu\n", ULONG_MAX);
    
    // Gleitkomma-Bereiche
    printf("\nGleitkomma-Bereiche:\n");
    printf("float: %.10e to %.10e\n", FLT_MIN, FLT_MAX);
    printf("double: %.10e to %.10e\n", DBL_MIN, DBL_MAX);
    
    return 0;
}