NAME			= harlFilter

CFLAGS			= -Wall -Werror -Wextra
CXX				= g++

# --- Source File Lists ---
SRCS =	main.cpp Harl.cpp

# --- Object File Generation ---
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

# --- Make Targets ---
all: $(NAME)

# --- Final Executable Linkage ---
$(NAME): $(OBJS) 
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

# --- Compilation Rules for Object Files ---
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CXX) $(CFLAGS) 

# --- Cleaning Rules ---
clean :
	rm -rf $(OBJS_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re