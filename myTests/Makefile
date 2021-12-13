NONE			=	\033[0;0m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
PURPLE			=	\033[0;35m

CXX				=	clang++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98
RM				=	rm -rf

NAME			=	tester

OBJDIR			=	./obj/
HEADERDIR 		=	./includes/

SRCDIR_COMMON	=	./srcs/common/
SRCS_COMMON		=	main.cpp
OBJS_COMMON		=	$(addprefix $(OBJDIR), $(SRCS_COMMON:.cpp=.o))
HEADERS_COMMON 	=	$(addprefix $(HEADERDIR), common.hpp)


SRCDIR_VECTOR	=	./srcs/vector_tests/
SRCS_VECTOR		=	run_vector_tests.cpp constructors_v.cpp iterators_v.cpp\
					capacity_v.cpp element_access_v.cpp modifiers_v.cpp\
					relational_operators_v.cpp get_allocator_v.cpp swap_v.cpp
OBJS_VECTOR		=	$(addprefix $(OBJDIR), $(SRCS_VECTOR:.cpp=.o))
HEADER_VECTOR 	=	$(addprefix $(HEADERDIR), vector_tests.hpp)

SRCDIR_STACK	=	./srcs/stack_tests/
SRCS_STACK		=	run_stack_tests.cpp constructors_st.cpp\
					member_functions_st.cpp relational_operators_st.cpp
OBJS_STACK		=	$(addprefix $(OBJDIR), $(SRCS_STACK:.cpp=.o))
HEADER_STACK 	=	$(addprefix $(HEADERDIR), stack_tests.hpp)

SRCDIR_MAP		=	./srcs/map_tests/
SRCS_MAP		=	run_map_tests.cpp constructors_map.cpp iterators_map.cpp\
					element_access_m.cpp capacity_map.cpp modifiers_map.cpp\
					lookup_map.cpp observers_map.cpp non_member_functions.cpp
OBJS_MAP		=	$(addprefix $(OBJDIR), $(SRCS_MAP:.cpp=.o))
HEADER_MAP 		=	$(addprefix $(HEADERDIR), map_tests.hpp)

SRCDIR_SET		=	./srcs/set_tests/
SRCS_SET		=	run_set_tests.cpp constructors_set.cpp iterators_set.cpp\
					capacity_set.cpp modifiers_set.cpp lookup_set.cpp\
					observers_set.cpp non_member_functions_set.cpp
OBJS_SET		=	$(addprefix $(OBJDIR), $(SRCS_SET:.cpp=.o))
HEADER_SET 		=	$(addprefix $(HEADERDIR), set_tests.hpp)

OBJS_ALL		=	$(OBJS_COMMON) $(OBJS_VECTOR) $(OBJS_STACK) $(OBJS_MAP) $(OBJS_SET)

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJS_ALL)
	$(CXX) $(CXXFLAGS) $(OBJS_ALL) -o $@
	@echo "$(PURPLE) $@ has been created $(NONE)"

##############################
##    common compilation    ##
##############################

$(OBJS_COMMON): $(OBJDIR)%.o: $(SRCDIR_COMMON)%.cpp $(HEADERS_COMMON)
	$(CXX) $(CXXFLAGS) -I$(HEADERDIR) -c $< -o $@
	@echo "$(GREEN) Object file $(PURPLE)$@$(GREEN) for engine has been created $(NONE)"

####################################
##    vector tests compilation    ##
####################################

$(OBJS_VECTOR): $(OBJDIR)%.o: $(SRCDIR_VECTOR)%.cpp $(HEADER_VECTOR)
	$(CXX) $(CXXFLAGS) -I$(HEADERDIR) -c $< -o $@
	@echo "$(GREEN) Object file $(PURPLE)$@$(GREEN) for engine has been created $(NONE)"

##################################
##    stck tests compilation    ##
##################################

$(OBJS_STACK): $(OBJDIR)%.o: $(SRCDIR_STACK)%.cpp $(HEADER_STACK)
	$(CXX) $(CXXFLAGS) -I$(HEADERDIR) -c $< -o $@
	@echo "$(GREEN) Object file $(PURPLE)$@$(GREEN) for engine has been created $(NONE)"

##################################
##    map tests compilation     ##
##################################

$(OBJS_MAP): $(OBJDIR)%.o: $(SRCDIR_MAP)%.cpp $(HEADER_MAP)
	$(CXX) $(CXXFLAGS) -I$(HEADERDIR) -c $< -o $@
	@echo "$(GREEN) Object file $(PURPLE)$@$(GREEN) for engine has been created $(NONE)"

##################################
##    set tests compilation     ##
##################################

$(OBJS_SET): $(OBJDIR)%.o: $(SRCDIR_SET)%.cpp $(HEADER_SET)
	$(CXX) $(CXXFLAGS) -I$(HEADERDIR) -c $< -o $@
	@echo "$(GREEN) Object file $(PURPLE)$@$(GREEN) for engine has been created $(NONE)"


clean:
	$(RM) $(OBJDIR)
	@echo "$(RED) $(OBJDIR) has been deleted $(NONE)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(RED) $(NAME) has been deleted $(NONE)"

re:	fclean all

.PHONY: all clean fclean re
