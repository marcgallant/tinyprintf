#ifndef TINYPRINTF_H
#define TINYPRINTF_H

#include <stdarg.h>
#include <stddef.h>

/**
 * \brief Display the string on stdout
 *
 * Display s or (null)
 *
 * \param s String to display
 * \return Length of the displayed string
 */
int disp_str(char *s);

/**
 * \brief Convert to string, and display it on stdout
 *
 * \param nb Value to convert
 * \return Length of the displayed string
 */
int my_itoa(int nb);

/**
 * \brief Convert to string in the according base, and display it on stdout
 *
 * \param nb Value to convert
 * \param base Length of the base string
 * \return Length of the displayed string
 */
int my_itoa_base(unsigned int nb, size_t base);

/**
 * \brief Format the string and display it on stdout
 *
 * \param c Current character
 * \param ap List of argument to take from
 * \return
 */
int parser(char c, va_list ap);

/**
 * \brief Small printf(3)
 *
 * \param format
 * \param ... Variable list of params
 * \return Length of the displayed string
 */
int tinyprintf(const char *format, ...);

#endif /* ! TINYPRINTF_H */
