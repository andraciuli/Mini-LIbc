// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	// return if no memory is allocated to the destination
    if (destination == NULL) {
        return NULL;
    }

 
    // copy the C-string pointed by source into the array
    // pointed by destination
    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }
 
    // include the terminating null character
    *destination = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	size_t i;

    // Copy characters from source to destination
    for (i = 0; i < len && source[i] != '\0'; i++) {
        destination[i] = source[i];
    }

    // Pad with null characters if necessary
	while (i < len) {
		destination[i] = '\0';
		i++;
	}

    return destination;	
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	// Find the null-terminator at the end of the destination string
    char *destEnd = destination;
    while (*destEnd != '\0') {
        destEnd++;
    }

    // Copy characters from source to the end of destination
    while (*source != '\0') {
        *destEnd = *source;
        destEnd++;
        source++;
    }

    // Ensure that the destination string is null-terminated
    *destEnd = '\0';

    return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	// Find the null-terminator at the end of the destination string
    char *destEnd = destination;
    while (*destEnd != '\0') {
        destEnd++;
    }

    // Append characters from source to the end of destination, up to len characters
    while (*source != '\0' && len > 0) {
        *destEnd = *source;
        destEnd++;
        source++;
        len--;
    }

    // Ensure that the destination string is null-terminated
    *destEnd = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	while (*str1 != '\0' || *str2 != '\0') {
        if (*str1 < *str2) {
            return -1;  // str1 is lexicographically smaller
        } else if (*str1 > *str2) {
            return 1;   // str1 is lexicographically greater
        }
        str1++;
        str2++;
    }

    return 0;  // Both strings are equal
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	while (len > 0 && (*str1 != '\0' || *str2 != '\0')) {
        if (*str1 < *str2) {
            return -1;  // str1 is lexicographically smaller
        } else if (*str1 > *str2) {
            return 1;   // str1 is lexicographically greater
        }
        str1++;
        str2++;
        len--;
    }

    return 0;  // The first 'len' characters of both strings are equal
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	while (*str != '\0') {
        if (*str == (char)c) {
            return (char *)str; // Cast to char* because the return type is char*
        }
        str++;
    }

    // If the character is not found, return NULL
    return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	char *result = NULL;

    while (*str != '\0') {
        if (*str == (char)c) {
            result = (char *)str; // Update the result when a match is found
        }
        str++;
    }

    // If the character is not found, return NULL or return the last occurrence found
    return result;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
 	// If the needle is an empty string, return the haystack
    if (*needle == '\0') {
        return (char *)haystack;
    }

    while (*haystack != '\0') {
        const char *h = haystack;
        const char *n = needle;

        // Check for a substring match
        while (*n != '\0' && *h == *n) {
            h++;
            n++;
        }

        // If the substring is found, return the pointer to the start of the match
        if (*n == '\0') {
            return (char *)haystack;
        }

        haystack++;
    }

    // If the needle is not found, return NULL
    return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	const char *lastOccurrence = NULL;
    const char *found = strstr(haystack, needle);

    while (found != NULL) {
        lastOccurrence = found;
        found = strstr(found + 1, needle);
    }

    return (char *)lastOccurrence;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	// Typecast the void pointers to char pointers for byte-wise copying
    char *dest = (char *)destination;
    const char *src = (const char *)source;

    // Copy 'num' bytes from source to destination
    for (size_t i = 0; i < num; i++) {
        dest[i] = src[i];
    }

    return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *dest = (char *)destination;
    const char *src = (const char *)source;

    if (dest < src) {
        // Copy forward from the beginning (no overlap)
        for (size_t i = 0; i < num; i++) {
            dest[i] = src[i];
        }
    } else if (dest > src) {
        // Copy backward from the end (no overlap)
        for (size_t i = num; i > 0; i--) {
            dest[i - 1] = src[i - 1];
        }
    }
    
    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const unsigned char *p1 = ptr1;
    const unsigned char *p2 = ptr2;

    for (size_t i = 0; i < num; i++) {
        if (p1[i] < p2[i]) {
            return -1;
        } else if (p1[i] > p2[i]) {
            return 1;
        }
    }

    return 0; // Both memory blocks are equal
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	unsigned char *p = source;
    unsigned char val = (unsigned char)value;

    for (size_t i = 0; i < num; i++) {
        p[i] = val;
    }

    return source;
}
