#include "main.h"

/**
 * handle_interrupt - handle interrupt
 * @signal: signal int
 */
void handle_interrupt(int signal __attribute__((unused)))
{
	_puts("\n($) ");
}
