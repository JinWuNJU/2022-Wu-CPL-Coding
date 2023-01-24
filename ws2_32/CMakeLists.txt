add_executable(demo demo.c)
link_libraries(ws2_32)
target_link_libraries(demo ws2_32)