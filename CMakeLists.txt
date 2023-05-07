cmake_minimum_required(VERSION 3.25)
project(rush_shell C)

set(CMAKE_C_STANDARD 11)

add_executable(rush_shell main.c views/messages/messages.view.c views/messages/messages.view.h io-exceptions/exceptions.c io-exceptions/exceptions.h services/commandline/commandline.service.c services/commandline/commandline.service.h services/engine/engine.service.c services/engine/engine.service.h services/allocation/allocation.sevice.c services/allocation/allocation.sevice.h)
