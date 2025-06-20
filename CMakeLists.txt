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
	modules
)

target_link_libraries(${target} INTERFACE
	hardware_gpio
	hardware_adc
)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/modules/radio)
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/modules/radio)
	target_link_libraries(${target} INTERFACE whale_radio_module)
endif()

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/modules/rtc)
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/modules/rtc)
	target_link_libraries(${target} INTERFACE whale_rtc_module)
endif()


if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/modules/eeprom)
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/modules/eeprom)
	target_link_libraries(${target} INTERFACE whale_eeprom_module)
endif()
