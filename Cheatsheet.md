# Most commonly used functions in C:

## String functions

1. **strlen** - Length of a string:
```
int strlen(char *s) return len; 
```
2. **strcmp** - Compares two strings lexicographically: 
```
int strcmp(char *s1, char *s2) return 0 (equal) or != 0 (not equal);
```
3. **strncmp** - Compares two strings up to a specified number of characters: 
```
int strncmp(char *s1, char *s2, int n) return 0 (equal) or != 0 (not equal);
```
4. **strcasecmp** - Case-insensitive string comparison: 
```
int strcasecmp(char *s1, char *s2) return 0 (equal) or != 0 (not equal);
```
5. **strcpy** - Copies a string: 
```
char *strcpy(char *dest, char *src) return dest;
```
6. **strncpy** - Copies a certain amount of characters from one string to another: 
```
char *strncpy(char *dest, char *src, int n) return dest;
```
7. **strcat** - Concatenates two strings: 
```
char *strcat(char *dest, char *src) return dest;
```
8. **strncat** - Concatenates two strings up to a specified number of characters: 
```
char *strncat(char *dest, char *src, int n) return dest;
```
9. **strdup** - Duplicates a string: 
```
char *strdup(char *s) return dup;
```
10. **strchr** - Locates the first occurrence of a character in a string: 
```
char *strchr(char *s, int c) return s;
```
11. **strstr** - Locates the first occurrence of a substring in a string: 
```
char *strstr(char *haystack, char *needle) return haystack;
```
12. **atoi** - Converts a string to an integer:
```
int atoi(char *str) return result;
```

## Memory functions
1. **malloc** - Takes a single argument, which is the number of bytes to allocate:
```
int* allocated_with_malloc = malloc(5 * sizeof(int));
```
2. **calloc** - Takes two arguments, number of blocks to be allocated and size of each block in bytes:
```
int* allocated_with_calloc = calloc(5, sizeof(int));
```
3. **free** - Free the allocated memory;
```
free(memory);
```

## Standard Input/Output functions

1. **scanf** - Opens a file:
```
int scanf(char *format, variable);
```
2. **printf** - Closes a file:
```
int printf(char *format, variable);
```

## File functions

### Opening and Closing

1. **fopen** - Opens a file:
```
FILE *fopen(char *filename, char *mode); mode -> "r", "w", "rb", "wb", "r+", "w+", "a" ...
```
2. **fclose** - Closes a file:
```
int fclose(FILE *stream);
```

### File Reading

1. **fgetc** - Reads a character from a file:
```
int fgetc(FILE *stream);
```
2. **fgets** - Reads a line from a file:
```
char *fgets(char *s, int size, FILE *stream);
```
3. **fscanf** - Reads formatted input from a file:
```
int fscanf(FILE *stream, char *format, variable);
```
4. **fread** - Reads binary data from a file:
```
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
```

### File Writing

1. **fputc** - Writes a character to a file:
```
int fputc(int c, FILE *stream);
```
2. **fputs** - Writes a string to a file:
```
int fputs(char *s, FILE *stream);
```
3. **fprintf** - Writes formatted output to a file:
```
int fprintf(FILE *stream, char *format, variable);
```
4. **fwrite** - Writes binary data to a file:
```
size_t fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream);
```

### File Positioning

1. **fseek** - Sets the file position indicator for a file stream:
```
int fseek(FILE *stream, long offset, int whence);
```
2. **rewind** - Sets the file position indicator to the beginning of the file:
```
void rewind(FILE *stream);
```
3. **fgetpos** - Gets the current file position indicator:
```
int fgetpos(FILE *stream, fpos_t *pos);
```
4. **fsetpos** - Sets the file position indicator:
```
int fsetpos(FILE *stream, const fpos_t *pos);
```

## Char functions
```
#include <ctype.h>
```

1. **isalnum** - Checks alphanumeric character:
```
int isalnum(int argument);
```
2. **isdigit** - Checks whether a character is a number or not:
```
int isdigit(int argument);
```
3. **isalpha** - Checks whether a character is an alphabet or not:
```
int isalpha(int argument);
```
4. **islower** - Checks lowercase alphabet:
```
int islower(int argument);
```
5. **isupper** - Checks uppercase alphabet:
```
int isupper(int argument);
```
6. **tolower** - Converts alphabet to lowercase:
```
int tolower(int argument);
```
7. **toupper** - Converts alphabet to uppercase:
```
int toupper(int argument);
```

## Math functions
```
#include <math.h>
```

1. **floor** - Computes the nearest integer less than argument:
```
double floor(double argument);
```
2. **ceil** - Computes the nearest integer greater than argument:
```
double ceil(double argument);
```
3. **pow** - Computes power of a number:
```
double pow(double x, double y);
```
4. **sqrt** - Computes square root of a number:
```
double sqrt(double arg);;
```

### Number Conversion

- bin to decimal
```
(1010 -> 10) -> 1 * 2^3 + 0 * 2^2 + 1 * 1^2 + 0 * 0^2 = 8 + 2 = 10
```
- octal to decimal
```
(12 -> 10) -> 1 * 8^1 + 2 * 8^0 = 8 + 2 = 10
```
- octal to decimal
```
(A -> 10) -> 10 * 16^0 = 10
(A = 10, B = 11, C = 12, D = 13, E = 14, F = 15)
```

### Data Types and Sizes

- char -> 1 byte
- short -> 2 bytes
- int -> 4 bytes
- long -> 8 bytes

### Working with bytes

```
We have a byte (b) -> 00101100
1st bit - 0, 2nd - 0, 3rd - 1, 4th - 1 ...

If we want to go from first to second bit we do this b >> 1
From this: 00101100
We get this: 00010110
Now: 1st bit - 0, 2nd - 1, 3rd - 1, 4th - 0 ...

a & b -> 1 (a == 1 && b == 1)
b | a -> 1 (a == 1 || b == 1)
b ^ a -> 1 (a == 1 && b == 0) || (a == 0 && b == 1)

10000000
&
00000001
---------
00000000

1
&
00101001
---------
00000001

1
|
00101001
---------
00101001

1
^
00101001
---------
00101000

10011001 >> 1 -> 01001100
11111111 >> 2 -> 00111111
11111111 << 2 -> 1111111100
```