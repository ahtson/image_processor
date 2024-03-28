cmake_minimum_required(VERSION 3.5)
project("Image Processor")

include_directories(includes)

file(GLOB SOURCES "image_processor.cpp" "src/bmp/*.cpp" "src/util/*.cpp" "src/io/*.cpp" "src/matrix/*.cpp" "src/filters/*.cpp" "src/exceptions/*.cpp")

add_executable(image_processor ${SOURCES})

install(TARGETS image_processor
        RUNTIME DESTINATION /usr/local/bin)

