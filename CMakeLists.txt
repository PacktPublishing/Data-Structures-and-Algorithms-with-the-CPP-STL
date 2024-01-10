CMAKE_MINIMUM_REQUIRED(VERSION 3.9)

enable_language(CXX)

project(cppDataStructuresAndAlgorithms)

set(CMAKE_CONFIGURATION_TYPES Debug Release CACHE STRING INTERNAL FORCE)

# https://cmake.org/pipermail/cmake/2008-March/020347.html
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING
	   "Choose the type of build, options are: Debug Release"
	   FORCE )
endif()

set(CMAKE_CXX_STANDARD 23)

if(${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
	add_compile_options(/wd4251) # w4251 - 'identifier' : class 'type' needs to have dll-interface to be used by clients of class 'type2'
	# add_compile_options(/wd4275) # w4275 - non dll-interface class 'std::runtime_error' used as base for dll-interface class
	add_compile_options(/MP)
	add_compile_options(/D_SCL_SECURE_NO_WARNINGS)
	add_compile_options(/permissive-)

elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
	add_compile_options(-Wall)
	add_compile_options(-fPIC)

elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL Clang)
	if(${CMAKE_SYSTEM_NAME} STREQUAL Windows)
		add_compile_options(-Xclang -std=c++20)
		add_compile_options(-Wno-c++98-compat)
		add_compile_options(-Wno-c++98-compat-pedantic)
		add_compile_options(-Wno-reserved-id-macro)
	else()
		add_compile_options(-Wall)
		add_compile_options(-fPIC)
	endif()

elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL AppleClang)
	add_compile_options(-Wall)
	add_compile_options(-fPIC)
endif()

set(CMAKE_DEBUG_POSTFIX          "-d" CACHE STRING "add a postfix, usually d on windows")
set(CMAKE_RELEASE_POSTFIX        "" CACHE STRING "add a postfix, usually empty on windows")
set(CMAKE_RELWITHDEBINFO_POSTFIX "-rd" CACHE STRING "add a postfix, usually empty on windows")
set(CMAKE_MINSIZEREL_POSTFIX     "" CACHE STRING "add a postfix, usually empty on windows")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# This is not a good pattern for building C++ projects, but it is a good
# pattern for building the example code for this book.  Don't look at this
# as a good example for how to use CMake in general.  This is a bit of an
# abuse of CMake.

# Utility to format all of the code specifically for the book.
macro(run_clang_format source_files clang_format_file)
    foreach(source_file ${${source_files}})
        # Check if the file exists
        if(EXISTS ${source_file})
            # message("Formatting file: ${source_file}")
            execute_process(
                COMMAND clang-format -i -style=file -assume-filename=${clang_format_file} ${source_file}
                RESULT_VARIABLE clang_format_result
            )
            if(clang_format_result)
                message(FATAL_ERROR "Failed to run clang-format on ${source_file}")
            endif()
        else()
            message("File not found: ${source_file}")
        endif()
    endforeach()
endmacro()

# Define the macro for adding chapters
macro(add_chapter chapter_num chapter_desc)
    # Construct the chapter option name and directory based on the chapter number
    set(OPTION_NAME "STLBOOK_CHAPTER_${chapter_num}")
    set(CHAPTER_DIR "chapter${chapter_num}")
    set(CHAPTER_NAME "Chapter${chapter_num}_")

    # Create an option for the chapter
    option(${OPTION_NAME} "Build Chapter ${chapter_num}: ${chapter_desc}" ON)

    # Add the subdirectory if the option is enabled
    if(${OPTION_NAME})
    	set(PROJECT_CHAPTER ${CHAPTER_NAME})

		# Get all .cpp files in the current chapter directory.
		file(GLOB_RECURSE files "${CHAPTER_DIR}/*.cpp")

		# Optional: This helps ensure that if changes are made, they are still formatted for the book.
		# run_clang_format(files ${CMAKE_SOURCE_DIR}/.clang-format)

		# Loop over all of the .cpp files that we have found.
		foreach(INPUT_FILE ${files})
		    # Strip off the file extension and save the file name as PROJECT_FILE
		    # NAME_WE = File name without directory or longest extension
		    get_filename_component(PROJECT_FILE ${INPUT_FILE} NAME_WE)

		    # Build a project name based on the chapter name and the project file name.
		    project(${PROJECT_CHAPTER}${PROJECT_FILE})

		    # Add an executable with the same name as the project file.
		    add_executable(${PROJECT_NAME})

		    # The only source we need is the single source file that we found
		    # (we could also use "file" here.)
		    target_sources(${PROJECT_NAME} PRIVATE ${CHAPTER_DIR}/${PROJECT_FILE}.cpp)
		endforeach()
    endif()
endmacro()

# Not all chapters have fully running code examples.  Some only have snippets.

add_chapter(01 "The Basics of std::vector")
add_chapter(02 "Mastering Iterators with std::vector")
add_chapter(03 "Mastering Memory and Allocators with std::vector")
add_chapter(04 "Mastering Algorithms with std::vector")
# add_chapter(05, "Making the Case for std::vector")
add_chapter(06 "Advanced Sequence Container Usage")
add_chapter(07 "Advanced Ordered Associative Container Usage")
add_chapter(08 "Advanced Unordered Associative Container Usage")
add_chapter(09 "Advanced Container Adaptor Usage")
add_chapter(10 "Advanced Container View Usage")
add_chapter(11 "Fundamental Algorithms and Searching")
add_chapter(12 "Manipulation and Transformation")
add_chapter(13 "Numeric and Range-Based Operations")
# add_chapter(14 "Permutations, Partitions, and Heaps")
add_chapter(15 "STL With Ranges")
# add_chapter(16 "Creating STL-Compatible Types")
# add_chapter(17 "Creating STL-Compatible Algorithms")
add_chapter(18 "Type Traits and Policies")
add_chapter(19 "Exception Safety")
add_chapter(20 "Thread Safety and Concurrency with the STL")
add_chapter(21 "STL Interaction with Concepts and Coroutines")
add_chapter(22 "Parallel Algorithms with the STL")

project(cppDataStructuresAndAlgorithms)
