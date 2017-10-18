cmake_minimum_required(VERSION 3.7)
project(ft_ls C)

set(CMAKE_C_STANDARD 11)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

include_directories(includes)
include_directories(lib/libft)

set(HEADER_FILES
        includes/options/dirdata/behavior.h
        includes/options/dirdata/decorated.h
        includes/options/dirdata/filter.h
        includes/options/options.h
        includes/file.h
        includes/ft_ls.h
        )

set(FILE_SOURCE_FILES
        src/file/file_new.c
        src/file/file_remove.c
        src/file/file_get_type.c src/file/file_get_acr.c src/file/file_get_owner.c src/file/file_get_group.c src/file/file_get_mimedate.c src/file/file_get_filename.c src/file/file_get_lcount.c src/file/file_get_size.c)

set(OPTIONS_SOURCE_FILES
        src/options/dirdata/behavior.c
        src/options/dirdata/decorated.c
        src/options/dirdata/filter.c
        src/options/options_init.c
        src/options/options_new.c
        src/options/dirdata/decorated_default.c src/options/dirdata/decorated_columns.c)

set(SOURCE_FILES
        ${HEADER_FILES}
        ${FILE_SOURCE_FILES}
        ${OPTIONS_SOURCE_FILES}
        src/ft_ls.c
        src/main.c
        src/read_directory.c
        src/options/dirdata/decorated_columns.c)

add_executable(ft_ls ${SOURCE_FILES})

add_subdirectory(lib/libft)

target_link_libraries(ft_ls libft)