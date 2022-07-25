#ifndef UNIT_TEST_TOOLS_HEADER
#define UNIT_TEST_TOOLS_HEADER

#include <stdio.h>

static unsigned _failures = 0;

static void _record_failure(unsigned line_no)
{
	++_failures;
	fprintf(stderr, "FAILURE Line %u\n", line_no);
}

// Used for determine exit codes
static int _failure_result(void) {return _failures ? 3 : 0; }

#define UNIT_CHECK(cond) if(!(cond)) _record_failure(__LINE__)

#endif // UNIT_TEST_TOOLS_HEADER