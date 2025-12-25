NAME        := convert

CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror
SRCS        := main.cpp ScalarConverter.cpp
OBJS_DIR    := objs
OBJS        := $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

# --- Source File Lists ---
SRCS =	main.cpp ScalarConverter.cpp Helper_func.cpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Compile .cpp -> .o into objs/
$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

