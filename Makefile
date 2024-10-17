# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mianni <mianni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/18 19:13:23 by mianni            #+#    #+#              #
#    Updated: 2024/08/27 15:23:24 by mianni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

SRC_DIR = ./sources_pushswap
BONUS_DIR = ./Bonus

OPS_DIR = $(SRC_DIR)/operations
UTILS_DIR = $(SRC_DIR)/push_swap_utils

SRCS_PUSH_SWAP = $(OPS_DIR)/push.c \
                  $(OPS_DIR)/reverse_rotate.c \
                  $(OPS_DIR)/rotate.c \
                  $(OPS_DIR)/swap.c \
                  $(UTILS_DIR)/define_median_cheapest.c \
                  $(UTILS_DIR)/define_target_index.c \
                  $(UTILS_DIR)/operation_list.c \
                  $(UTILS_DIR)/parsing_setup.c \
                  $(UTILS_DIR)/push_swap_algo.c \
                  $(UTILS_DIR)/push_swap_utils.c \
                  $(UTILS_DIR)/push_swap_utils_2.c \
                  $(UTILS_DIR)/push_swap_utils_3.c \
                  $(UTILS_DIR)/push_swap_utils_4.c \
                  $(UTILS_DIR)/push_swap_utils_5.c \
                  $(UTILS_DIR)/main.c \
                  $(UTILS_DIR)/split.c

OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)

SRC_CHECKER = $(BONUS_DIR)/main.c \
               $(BONUS_DIR)/get_next_line.c \
               $(BONUS_DIR)/get_next_line_utils.c \
               $(BONUS_DIR)/bonus_utils.c \
               $(BONUS_DIR)/bonus_utils_2.c \

OPERATIONS_SRC = $(SRC_DIR)/operations/swap.c \
                  $(SRC_DIR)/operations/rotate.c \
                  $(SRC_DIR)/operations/reverse_rotate.c \
                  $(SRC_DIR)/operations/push.c \

PUSH_SWAP_UTILS_SRC = $(SRC_DIR)/push_swap_utils/define_median_cheapest.c \
                       $(SRC_DIR)/push_swap_utils/define_target_index.c \
                       $(SRC_DIR)/push_swap_utils/operation_list.c \
                       $(SRC_DIR)/push_swap_utils/parsing_setup.c \
                       $(SRC_DIR)/push_swap_utils/push_swap_algo.c \
                       $(SRC_DIR)/push_swap_utils/push_swap_utils.c \
                       $(SRC_DIR)/push_swap_utils/push_swap_utils_2.c \
                       $(SRC_DIR)/push_swap_utils/push_swap_utils_3.c \
                       $(SRC_DIR)/push_swap_utils/push_swap_utils_4.c \
                       $(SRC_DIR)/push_swap_utils/push_swap_utils_5.c \
                       $(SRC_DIR)/push_swap_utils/split.c \

ALL_SRC_CHECKER = $(SRC_CHECKER) $(OPERATIONS_SRC) $(PUSH_SWAP_UTILS_SRC)
OBJ_CHECKER = $(ALL_SRC_CHECKER:.c=.o)

all: push_swap

push_swap: $(OBJS_PUSH_SWAP)
	$(CC) $(CFLAGS) -o $@ $(OBJS_PUSH_SWAP)

bonus: push_swap $(OBJ_CHECKER)
	$(CC) $(CFLAGS) -o checker $(OBJ_CHECKER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_PUSH_SWAP) $(OBJ_CHECKER)

fclean: clean
	$(RM) push_swap checker

re: fclean all

.PHONY: all bonus clean fclean re

