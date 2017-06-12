cmake_minimum_required(VERSION 3.7)
project(ft_ls C)

set(CMAKE_C_STANDARD 99)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

set(SOURCE_FILES main.c ft_ls.h options/dirdata/filter/filter_dirdata.c options/dirdata/decorated/decorated_dirdata.c options/dirdata/decorated/decorated_dirdata.h options/dirdata/begavior/behavior_dirdata.c options/dirdata/begavior/behavior_dirdata.h options/dirdata/filter/filter_dirdata.h ft_ls.c read_directory.c options/options_init.c options/options.h options/options_new.c file/file.h file/file_new.c file/file_remove.c)

include_directories(.)
include_directories(libft)
include_directories(file)
include_directories(options)
include_directories(options/dirdata/begavior)
include_directories(options/dirdata/decorated)
include_directories(options/dirdata/filter)

add_executable(ft_ls ${SOURCE_FILES})

add_subdirectory(libft)

target_link_libraries(ft_ls libft)