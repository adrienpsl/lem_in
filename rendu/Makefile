.PHONY: all, $(NAME), clean, fclean, re

#*------------------------------------*\
#    color
#*------------------------------------*/
__TEXT_1__ = @echo "\033[1;34m
__TEXT_2__ = \t\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"


#*------------------------------------*\
#    path all src
#*------------------------------------*/
__PATH__ = ./

#*------------------------------------*\
#    name
#*------------------------------------*/
__NAME__ = lem


#*------------------------------------*\
#    compilateur
#*------------------------------------*/
__CC__ = gcc
__CFLAGS__ = -Wall -Werror -Wextra


#*------------------------------------*\
#    lib sources
#*------------------------------------*/

#lib ft :
__LIB_FT_PATH__ = ${__PATH__}libft/
__LIB_FT_INC__ = ${__LIB_FT_PATH__}ft_library_header.h


#*------------------------------------*\
#    sources project push
#*------------------------------------*/
__SOURCES_PATH__ = ${__PATH__}src/

__TMP__ := $(shell cd ${__SOURCES_PATH__} ; find . -type f -name '*.c' | sed 's/^..//'  |  tr '\n' ' ')
#__TMP__ =  debug.c getter_data/build_list_a_index.c getter_data/get_list_a.c getter_data/getter_is_good_nb.c getter_data/getter_utils.c solver/algo/brain.c solver/algo/is_just_three.c solver/browse/browse_simple.c solver/browse/first_browser.c solver/commun/get_median.c solver/instruct/instruct_helper.c solver/instruct/push_new_instruct.c solver/main_solver.c solver/quick/get_med_quick.c solver/quick/quick.c solver/quick/set_and_get_quick.c solver/sort/manage_sort.c solver/sort/sort_3_and_2.c solver/sort/sort_4.c solver/sort/sort_bower.c stack/construct_stack.c stack/src/pile_p.c stack/src/pile_r.c stack/src/pile_rr.c stack/src/pile_s.c stack/src/swap.c

__SRC__ = $(addprefix $(__SOURCES_PATH__), $(__TMP__))

__OBJ__ = $(__SRC__:.c=.o)

__HEADER_DIR__ = ${__PATH__}includes/

__ALL_HADER__ = $(shell cd ${__HEADER_DIR__} ; find . -type f -name '*.h' | sed 's/^..//'  |  tr '\n' ' ')
#*------------------------------------*\
#    make rule
#*------------------------------------*/
all: push_push


push_push: $(__NAME__)

#*------------------------------------*\
#    buld and push
#*------------------------------------*/
$(__NAME__): $(__OBJ__)

#	build other lib 	################################
	@make -C $(__LIB_FT_PATH__)

#	compile project 	################################
	@$(__CC__) $(__CFLAGS__) -o $(__NAME__) $(__OBJ__) -L${__LIB_FT_PATH__} -lft

	$(shell mv lem ./test)
	$(__TEXT_1__) $(__NAME__) $(__TEXT_2__)

#*------------------------------------*\
#    if change into .c
#*------------------------------------*/
%.o: %.c $(__ALL_HADER__) ./src/includes/all_includes.h
	@$(__CC__) $(__CFLAG__) -I $(__HEADER_DIR__) -I $(__LIB_FT_INC__) -o $@ -c $<


clean:
	@make clean -C $(__LIB_FT_PATH__)
	@rm -rf $(__OBJ__)
	@echo "\033[1;34mpush_swap\t\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"


fclean: clean
	@make fclean -C $(__LIB_FT_PATH__)
	@rm -rf $(__NAME__)
	@echo "\033[1;34mpush_swap\t\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all

