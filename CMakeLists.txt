cmake_minimum_required(VERSION 3.13)

set(target "wisdom_hal_extender")
project(${target} C CXX ASM)

add_library(${target} INTERFACE)

target_sources(${target} INTERFACE
	src/modules_weak/radio_weak.c
	src/modules_weak/rtc_weak.c
	src/modules_weak/eeprom_weak.c
)

target_include_directories(${target} INTERFACE
	src
	submodules
)

target_link_libraries(${target} INTERFACE
	hardware_gpio
	hardware_adc
)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/submodules/radio)
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/submodules/radio)
	target_link_libraries(${target} INTERFACE whale_radio_module)
endif()

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/submodules/rtc)
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/submodules/rtc)
	target_link_libraries(${target} INTERFACE whale_rtc_module)
endif()


if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/submodules/eeprom)
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/submodules/eeprom)
	target_link_libraries(${target} INTERFACE whale_eeprom_module)
endif()
