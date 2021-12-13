#include <sys/time.h>
#include "common.hpp"

void	runTest(void (*func)(), bool isTimerOn, const char* testDescription) {
	std::cout << PURPLE_COLOR << "Testing " << testDescription << RESTORE_COLOR << '\n';
	if (isTimerOn) {
		time_t startTime = getTime();
		func();
		time_t endTime = getTime();
		std::cout << "\ntime: " << endTime - startTime << "ms";
	} else {
		func();
	}
	std::cout << '\n' << std::endl;
}

int	error_message(const char *description, int error_code)
{
	std::cerr << RED_COLOR << "[!] tester: "
		<< RESTORE_COLOR << description << std::endl;
	return (error_code);
}


time_t	getTime() {
	struct timeval	s_time;

	if (gettimeofday(&s_time, (void *)0))
		exit(error_message("gettimeofday() error", errno));
	return s_time.tv_sec * 1000 + s_time.tv_usec / 1000;
}

int main(int argc, char **argv) {
	bool	isTimerOn;

	isTimerOn = argc > 1 && !std::strcmp(argv[1], "-t") ? true : false;
	runVectorTests(isTimerOn);
	runStackTests(isTimerOn);
	runMapTests(isTimerOn);
	runSetTests(isTimerOn);

	return 0;
}