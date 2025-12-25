NAME        = Mutaded

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror

SRCS        = main.cpp
OBJS_DIR    = obj
OBJS        = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re