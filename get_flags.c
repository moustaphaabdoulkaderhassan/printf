#include "main.h"

/**
 * get_flags - Extracts formatting flags from the given format string
 * @format: Formatted string containing flags
 * @i: Current index in the format string
 * Return: Active flags
 */
int get_flags(const char *format, int *i)
{
    /* Flag characters and their corresponding values */
    const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
    const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

    int j, currIndex;
    int flags = 0;

    /* Iterate through the format string to find flags */
    for (currIndex = *i + 1; format[currIndex] != '\0'; currIndex++)
    {
        /* Check if the current character is a valid flag */
        for (j = 0; FLAGS_CH[j] != '\0'; j++)
        {
            if (format[currIndex] == FLAGS_CH[j])
            {
                flags |= FLAGS_ARR[j]; /* Set the corresponding flag */
                break;
            }
        }

        /* If the current character is not a valid flag, exit the loop */
        if (FLAGS_CH[j] == '\0')
            break;
    }

    *i = currIndex - 1; /* Update the index */

    return (flags);
}

