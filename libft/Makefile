
#*------------------------------------*\
#    commande tric
#*------------------------------------*/
trick = cd src ; find . -type f -name '*.c' | sed 's/^..//'  |  tr '\n' ' ' | pbcopy  ; ..
trick = ls | tr '\n' ' ' | pbcopy


#*------------------------------------*\
#    Name
#*------------------------------------*/
__NAME__ = libft.a


#*------------------------------------*\
#    compilateur
#*------------------------------------*/
__CC__ = gcc
__CFLAGS__ = -Wall -Werror -Wextra


#*------------------------------------*\
#    source files
#*------------------------------------*/
__SOURCES_PATH__ = ./src/

#*------------------------------------*\
#    header
#*------------------------------------*/
__HEADER__ = ./ft_library_header.h


#*------------------------------------*\
#    sources
#*------------------------------------*/
__TMP__ := $(shell cd ${__SOURCES_PATH__} ; find . -type f -name '*.c' | sed 's/^..//'  |  tr '\n' ' ')
#__TMP__ = argv/ask_gnl.c argv/errno_exit.c argv/ft_error.c argv/get_next_line.c argv/open_file.c argv/split/construct_split.c argv/split/ft_free_split.c argv/split/ft_strsplit.c debug/print_tab.c list/double_list/double_linked_list/debug/dll_func.c list/double_list/double_linked_list/debug/dll_print_nb.c list/double_list/double_linked_list/debug/dll_print_str.c list/double_list/double_linked_list/dll_construct.c list/double_list/double_linked_list/src/dll_add.c list/double_list/double_linked_list/src/dll_drop_end.c list/double_list/double_linked_list/src/dll_drop_index.c list/double_list/double_linked_list/src/dll_drop_top.c list/double_list/double_linked_list/src/dll_fill_list_circular.c list/double_list/double_linked_list/src/dll_find.c list/double_list/double_linked_list/src/dll_index.c list/double_list/double_linked_list/src/dll_push.c list/double_list/double_linked_list/utils.c list/double_list/double_linked_list_circular/debug/dll_c_debug_print.c list/double_list/double_linked_list_circular/dll_c_construct.c list/double_list/double_linked_list_circular/src/dll_c_add_after.c list/double_list/double_linked_list_circular/src/dll_c_copie.c list/double_list/double_linked_list_circular/src/dll_c_drop_link.c list/double_list/double_linked_list_circular/src/dll_c_iter.c list/double_list/double_linked_list_circular/src/dll_c_push_link.c list/double_list/double_linked_list_link/dll_l_construct.c list/double_list/double_linked_list_link/src/dll_l_get_content.c list/simple_list/simple_linked_list/debug/sll_print_str.c list/simple_list/simple_linked_list/sll_construct.c list/simple_list/simple_linked_list/src/drop_utils.c list/simple_list/simple_linked_list/src/sll_add.c list/simple_list/simple_linked_list/src/sll_drop_link.c list/simple_list/simple_linked_list_link/sll_l_construct.c memory/ft_bzero.c memory/ft_exit_lack_memory.c memory/ft_malloc_protect.c memory/ft_memalloc.c memory/ft_memccpy.c memory/ft_memchr.c memory/ft_memcmp.c memory/ft_memcpy.c memory/ft_memdel.c memory/ft_memmove.c memory/ft_memset.c memory/soa.c nb/ft_atoi.c nb/ft_putnbr.c nb/ft_putnbr_fd.c nb/putnbr_str.c printf/buffer/head_buffer.c printf/data/manage_before_printer.c printf/data/nb/float/head_double.c printf/data/nb/integer/head_integer_signed.c printf/data/nb/integer/head_interger_n.c printf/data/nb/unsigned/head_integer_unsigned.c printf/data/nb/unsigned/utils_unsigned_integer.c printf/data/nb/unsigned_variation/head_unsigned_binairy.c printf/data/nb/unsigned_variation/head_unsigned_hexa.c printf/data/nb/unsigned_variation/head_unsigned_octal.c printf/data/nb/unsigned_variation/head_unsigned_ptr.c printf/data/text/char/head_char.c printf/data/text/other/head_percent.c printf/data/text/str/manage_str.c printf/main_pfff.c printf/parseur/head_parseur.c printf/parseur/parseur_flag.c printf/parseur/parseur_flag_utils.c printf/parseur/parseur_utils.c printf/printer/function_printer.c printf/printer/head_printer.c printf/printer/utils_printer.c printf/utils_main.c sort/ft_quick_sort.c sort/quick_sort_dll.c string/char/ft_free_doublechar_tab.c string/char/ft_isalnum.c string/char/ft_isalpha.c string/char/ft_isascii.c string/char/ft_isdigit.c string/char/ft_isprint.c string/char/ft_put_uni.c string/char/ft_putchar.c string/char/ft_putchar_fd.c string/char/ft_tolower.c string/char/ft_toupper.c string/str/check_char_into_str.c string/str/free_str.c string/str/is_all_number.c string/str/ft_itoa.c string/str/ft_putendl.c string/str/ft_putendl_fd.c string/str/ft_putstr.c string/str/ft_putstr_fd.c string/str/ft_str_rev.c string/str/ft_strcat.c string/str/ft_strchr.c string/str/ft_strchr_dup.c string/str/ft_strchr_how_many.c string/str/ft_strchr_len.c string/str/ft_strclr.c string/str/ft_strcmp.c string/str/ft_strcpy.c string/str/ft_strdel.c string/str/ft_strdup.c string/str/ft_strequ.c string/str/ft_striter.c string/str/ft_striteri.c string/str/ft_strjoin.c string/str/ft_strlcat.c string/str/ft_strlen.c string/str/ft_strmap.c string/str/ft_strmapi.c string/str/ft_strncat.c string/str/ft_strncmp.c string/str/ft_strncpy.c string/str/ft_strndup.c string/str/ft_strnequ.c string/str/ft_strnew.c string/str/ft_strnjoin.c string/str/ft_strnstr.c string/str/ft_strrchr.c string/str/ft_strstr.c string/str/ft_strsub.c string/str/ft_strtrim.c string/str/get_last_char_str.c string/str/index_of_char.c string/str/str_by_func.c

__SRC__ = $(addprefix $(__SOURCES_PATH__), $(__TMP__))

__OBJ__ = $(__SRC__:.c=.o)

__H__ = ft_library_header.h dll_c_header.h dll_header.h dll_l_header.h gnl.h libft_debug.h libft_define.h libft_memory_function.h libft_nb_function.h libft_str_function.h printf_header.h sll_header.h sll_l_header.h


#*------------------------------------*\
#    make rule
#*------------------------------------*/
all: $(__NAME__)


#*------------------------------------*\
#    buld and link the lib
#*------------------------------------*/
$(__NAME__): $(__OBJ__)
	@ar rc $(__NAME__) $(__OBJ__)
	@ranlib $(__NAME__)
	@echo "\033[1;34mLibft\t\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"


#*------------------------------------*\
#    if change into .c
#*------------------------------------*/
%.o: %.c $(__H__)
	@$(__CC__) $(__CFLAG__) -I $(__HEADER__) -o -c $@  $<


clean:
	@rm -rf $(__OBJ__)
	@echo "\033[1;34mLibft\t\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"


fclean: clean
	@rm -rf $(__NAME__)
	@echo "\033[1;34mLibft\t\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"


re: fclean all


.PHONY: all clean fclean re