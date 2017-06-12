cmake_minimum_required(VERSION 3.7)
project(ft_ls C)

set(CMAKE_C_STANDARD 99)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

set(SOURCE_FILES main.c)

include_directories(libft)

add_executable(ft_ls ${SOURCE_FILES})

add_subdirectory(libft)

target_link_libraries(ft_ls libft)