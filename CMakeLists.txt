cmake_minimum_required(VERSION 3.9.4)

set(PROJECT_NAME Lem-in)


#*------------------------------------*\
#    --  NAME PROJET  --
#*------------------------------------*/

project(${PROJECT_NAME} C)

#*------------------------------------*\
#    --  COMPILATEUR OPTION  --
#*------------------------------------*/
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")

#-fsanitize=memory-fsanitize-memory-track-origins=2 -fsanitize=address

#*------------------------------------*\
#    --  PATH  --
#*------------------------------------*/
set(REPO "src")
set(LIBFT "libft")

#*------------------------------------*\
#    --  THE HEADERS --
#*------------------------------------*/
file(GLOB head "${REPO}/includes/*.h")
#include_directories("${REPO}/includes/*.h")

#*------------------------------------*\
#    -- LIB FT FILE --
#*------------------------------------*/
file(GLOB head_lib "${LIBFT}/include/*.h")
file(GLOB all_head_lib "${LIBFT}/ft_library_header.h")
file(GLOB sources0 "${LIBFT}/src/*.c")
file(GLOB sources1 "${LIBFT}/src/**/*.c")
file(GLOB sources2 "${LIBFT}/src/**/**/*.c")
file(GLOB sources3 "${LIBFT}/src/**/**/**/*.c")
file(GLOB sources4 "${LIBFT}/src/**/**/**/**/*.c")
file(GLOB sources5 "${LIBFT}/**/**/**/**/**/*.c")
file(GLOB sources6 "${LIBFT}/test/*.c")

#*------------------------------------*\
#    --  PROJET FILE  --
#*------------------------------------*/
file(GLOB sources00 "${REPO}/*.c")
file(GLOB sources01 "${REPO}/**/*.c")
file(GLOB sources02 "${REPO}/**/**/*.c")
file(GLOB sources03 "${REPO}/**/**/**/*.c")
file(GLOB sources04 "${REPO}/**/**/**/**/*.c")
file(GLOB sources05 "${REPO}/**/**/**/**/**/*.c")


#*------------------------------------*\
#    --  TEST FILE  --
#*------------------------------------*/
#file(GLOB sources06 "test/*.c")
#file(GLOB sources07 "includes/*.c")
#file(GLOB sources08 "includes/*.h")

#*------------------------------------*\
#    --  MIXE ALL SOURCES  --
#*------------------------------------*/
set(
        sources
        ${sources0}
        ${sources1}
        ${sources2}
        ${sources3}
        ${sources4}
        ${sources5}
        ${sources6}

        ${sources00}
        ${sources01}
        ${sources02}
        ${sources03}
        ${sources04}
        ${sources05}
        ${sources06}
        #        ${sources07}
        #        ${sources08}
        )


set(
        header
        ${head}
        ${head_lib}
        ${all_head_lib}
        )
#*------------------------------------*\
#    --  ADD TO PROGRAMME  --
#*------------------------------------*/

add_executable(
        ${PROJECT_NAME}

        src/main.c
        ${sources}
        ${header}
)



#*------------------------------------*\
#    --  LINK OTHER LIB  --
#*------------------------------------*/
#target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/mlx/libmlx.a)
#
#target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
#target_link_libraries(${PROJECT_NAME} "-framework AppKit")