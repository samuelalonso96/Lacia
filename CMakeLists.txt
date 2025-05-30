cmake_minimum_required(VERSION 4.0.2)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_CXX_EXTENSIONS off)
message(STATUS "Building on ${CMAKE_BUILD_TYPE} mode...")
if(lacia_mac)
    set(CMAKE_OSX_ARCHITECTURES arm64)
endif()
project(Lacia)
if(lacia_mac)
    message(STATUS "Building for macOS...")
    get_filename_component(AbsolutePath "Resources/Mac" ABSOLUTE)
    file(GLOB_RECURSE ResourceFiles "Resources/Mac/*")
    foreach(ResourceFile ${ResourceFiles})
        file(RELATIVE_PATH ResourcePath "${AbsolutePath}" "${ResourceFile}")
        get_filename_component(NewResourcePath "${ResourcePath}" DIRECTORY)
        set_property(SOURCE "${ResourceFile}" PROPERTY MACOSX_PACKAGE_LOCATION "Resources/${NewResourcePath}")
        source_group("Resources/${NewResourcePath}" FILES "${ResourceFile}")
    endforeach(ResourceFile)
    file(GLOB_RECURSE MetalShaders "Shader/**.metal")
    add_executable(Lacia MACOSX_BUNDLE ${ResourceFiles} ${MetalShaders})
    set_target_properties(Lacia PROPERTIES MACOSX_BUNDLE_INFO_PLIST "${CMAKE_SOURCE_DIR}/Build/Info.plist" XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER com.salonso.lacia)
    set_source_files_properties(${MetalShaders} PROPERTIES LANGUAGE METAL COMPILE_OPTIONS -std=metal3.2)
    file(GLOB_RECURSE ObjCppSources "Source/**.mm")
    target_sources(Lacia PRIVATE ${ObjCppSources})
    find_library(foundation Foundation)
    if(NOT foundation)
        message(FATAL_ERROR "Foundation not found")
    endif()
    find_library(quartzcore QuartzCore)
    if(NOT quartzcore)
        message(FATAL_ERROR "QuartzCore not found")
    endif()
    find_library(metal Metal)
    if(NOT metal)
        message(FATAL_ERROR "Metal not found")
    endif()
    find_library(iokit IOKit)
    if(NOT iokit)
        message(FATAL_ERROR "IOKit not found")
    endif()
    find_library(appkit AppKit)
    if(NOT appkit)
        message(FATAL_ERROR "AppKit not found")
    endif()
    target_link_libraries(Lacia PRIVATE ${foundation} ${quartzcore} ${metal} ${iokit} ${appkit})
    target_compile_definitions(Lacia PRIVATE lacia_mac=)
endif()
target_compile_definitions(Lacia PRIVATE lacia_major=0 lacia_middle=0 lacia_minor=1 lacia_game=${lacia_game})
if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    target_compile_definitions(Lacia PRIVATE lacia_debug=)
    target_compile_options(Lacia PRIVATE -stdlib=libc++ -Werror -Wall -Wextra -Wpedantic -fno-rtti -fno-exceptions -g -Wno-dollar-in-identifier-extension -fms-extensions -Wno-language-extension-token)
    target_link_options(Lacia PRIVATE -g)
else()
    target_compile_options(Lacia PRIVATE -stdlib=libc++ -Werror -Wall -Wextra -Wpedantic -O3 -fno-rtti -fno-exceptions -flto=full -Wno-dollar-in-identifier-extension -fms-extensions -Wno-language-extension-token)
    target_link_options(Lacia PRIVATE -flto=full)
endif()
target_include_directories(Lacia PRIVATE Source)
target_compile_features(Lacia PRIVATE cxx_std_26)
file(GLOB_RECURSE CppSources "Source/**.cpp")
file(GLOB_RECURSE CppEditors "Editor/**.cpp")
target_sources(Lacia PRIVATE ${CppSources} ${CppEditors})