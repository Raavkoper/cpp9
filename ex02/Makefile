NAME = PmergeMe

COMP = c++
C_FLAGS = -std=c++11 -Wall -Wextra -Werror

SRC = main.cpp PmergeMe.cpp
OBJS = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(COMP) $(C_FLAGS) $^ -o $(NAME)
	@echo "compiled:)"

%.o: %.cpp
	@$(COMP) -c $(CFLAGS) -o $@ $<

clean:
	@$(RM) *.o

fclean: clean
	@$(RM) $(NAME)
	@echo "deleted:("

re: fclean all

.PHONY: all clean fclean re