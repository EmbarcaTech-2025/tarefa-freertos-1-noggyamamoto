# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

cmake_minimum_required(VERSION 3.12)

# Defina o caminho absoluto do FreeRTOS Kernel
set(FREERTOS_PATH "C:/FreeRTOS-KernelV11.2.0")
message("FreeRTOS Kernel located in ${FREERTOS_PATH}")

# Importe as bibliotecas necessárias
include(pico_sdk_import.cmake)
include(${FREERTOS_PATH}/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)

# Defina o projeto
project(embarcatech-freertos-tarefa-1 C CXX ASM)

# Inicialize o SDK do Raspberry Pi Pico
pico_sdk_init()

add_executable(embarcatech-freertos-tarefa-1
    main.c
)

target_include_directories(embarcatech-freertos-tarefa-1 PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(embarcatech-freertos-tarefa-1 
    pico_stdlib 
    FreeRTOS-Kernel-Heap4 
    hardware_i2c
)

pico_add_extra_outputs(embarcatech-freertos-tarefa-1)

# Se você tiver algo na pasta "lib", descomente abaixo - lembre-se de adicionar um CMakeLists.txt
# na pasta "lib"
#add_subdirectory(lib)