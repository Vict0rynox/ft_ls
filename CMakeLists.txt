cmake_minimum_required(VERSION 3.7)
project(ft_ls C)

set(CMAKE_C_STANDARD 11)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

include_directories(includes)
include_directories(lib/libft)

set(HEADER_FILES
        includes/options/options.h
        includes/file.h
        includes/ft_ls.h
        )

set(FILE_SOURCE_FILES
        src/file/file_new.c
        src/file/file_remove.c
        src/file/file_get_type.c
        src/file/file_get_acr.c
        src/file/file_get_owner.c src/file/file_get_group.c src/file/file_get_mimedate.c src/file/file_get_filename.c src/file/file_get_lcount.c src/file/file_get_size.c src/file/file_get_basename.c src/file/file_get_path.c src/file/file_get_pathname.c src/file/file_is_dir.c src/file/file_get_time.c src/file/file_is_adir.c src/file/new_file_info.c src/file/file_info_size_init.c)

set(OPTIONS_SOURCE_FILES
        src/options/dirdata/behavior.c
        src/options/dirdata/decorated.c
        src/options/dirdata/filter.c
        src/options/options_by_string.c
        src/options/new_args.c
        src/options/dirdata/decorated_default.c
        src/options/dirdata/decorated_columns.c
        )

set(SOURCE_FILES
        ${HEADER_FILES}
        ${FILE_SOURCE_FILES}
        ${OPTIONS_SOURCE_FILES}
        src/ft_ls.c
        src/main.c
        src/read_info.c
        src/options/dirdata/decorated_columns.c src/error_message.c src/illegal_option.c src/filter_args.c)

add_executable(ft_ls ${SOURCE_FILES})

add_subdirectory(lib/libft)

target_link_libraries(ft_ls libft)