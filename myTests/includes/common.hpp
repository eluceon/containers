#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
# include <string>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <unistd.h>
# include <cstring>
# include <cerrno>
# include <cstdlib>

# if 1 == 5 //CREATE A REAL STL EXAMPLE
	# include <map>
	# include <set>
	# include <stack>
	# include <vector>
	namespace ft = std;
# else
	# include "../../containers/vector.hpp"
	# include "../../containers/map.hpp"
	# include "../../containers/set.hpp"
	# include "../../containers/stack.hpp"
	# include "../../containers/vector.hpp"
# endif

# define PURPLE_COLOR	"\033[0;35m"
# define RED_COLOR		"\033[0;31m"
# define GREEN_COLOR	"\033[0;32m"
# define RESTORE_COLOR	"\033[0;0m"

enum	e_namespaces
{
	STD,
	FT
};

void	runVectorTests(bool isTimerOn);
void	runStackTests(bool isTimerOn);
void	runMapTests(bool isTimerOn);
void	runSetTests(bool isTimerOn);
int		runTests(std::string& filename, char **argv, char **env);
void	runTest(void (*func)(), bool isTimerOn, const char* testDescription);
time_t	getTime();

#endif