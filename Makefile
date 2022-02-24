NAME = philo
CC = gcc
CFLAGS = -pthread -Wall -Werror -Wextra
INC = philo.h

CFILES = ft_atoi.c ft_how_to_use.c ft_list_lib.c ft_philo_basic_tools.c ft_timestamp_in_ms.c philo_logic.c philo.c
OCFILES = ${CFILES:.c=.o}

BCFILES = bonus/ft_atoi.c bonus/ft_how_to_use.c  bonus/ft_list_lib.c bonus/philo_bonus.c bonus/ft_timestamp_in_ms.c \
bonus/process_handler.c
OBFILES = ${BCFILES:.c=.o}

all : display program
$(NAME) = all
display:
	@echo "\x1B[34m██████╗ ██╗  ██╗██╗██╗      ██████╗ ███████╗ ██████╗ ██████╗ ██╗  ██╗███████╗██████╗ ███████╗"
	@echo "██╔══██╗██║  ██║██║██║     ██╔═══██╗██╔════╝██╔═══██╗██╔══██╗██║  ██║██╔════╝██╔══██╗██╔════╝"
	@echo "██████╔╝███████║██║██║     ██║   ██║███████╗██║   ██║██████╔╝███████║█████╗  ██████╔╝███████╗"
	@echo "██╔═══╝ ██╔══██║██║██║     ██║   ██║╚════██║██║   ██║██╔═══╝ ██╔══██║██╔══╝  ██╔══██╗╚════██║"
	@echo "██║     ██║  ██║██║███████╗╚██████╔╝███████║╚██████╔╝██║     ██║  ██║███████╗██║  ██║███████║"
	@echo "╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝\x1B[33m"

program : $(OCFILES)
	@ echo "Compiling Philo...."
	@$(CC) $(CFLAGS) $(CFILES) -o philo
bonus : display $(OBFILES)
	@ echo "Compiling Philo Bonus...."
	@$(CC) $(CFLAGS) $(BCFILES) -o philo_bonus
clean :
	@ echo "\x1B[31mCleaning..."
	@ rm -rf $(OCFILES) $(OBFILES)
fclean : clean
	@ echo "\x1B[31mCleaning all..."
	@ rm -rf philo philo_bonus
re : fclean all
.PHONY : all clean fclean re bonus checker
