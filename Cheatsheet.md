# Simplified implementations of some of the most commonly used string and memory manipulation functions in C:

strlen: Computes the length of a string.

```
size_t strlen(const char *str) {
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}
```