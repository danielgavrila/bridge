cmake_minimum_required( VERSION 3.14 )

project( HeadresOnlyExtLib
         VERSION 2.0
         DESCRIPTION " header-only lib." )

# Provide target for "catchUnit  library.
add_library( catchUnit INTERFACE IMPORTED GLOBAL )

# Store include search-path containing headers of "catchUnit 
target_include_directories(catchUnit  SYSTEM INTERFACE ${ROOT_PATH_THIRD_PARTY}/catchUnit)

# Require at least compiling with C++17.
target_compile_features(catchUnit  INTERFACE cxx_std_17 )





# Provide target for "RangeV3  library.
add_library( RangeV3 INTERFACE IMPORTED GLOBAL )

# Store include search-path containing headers of "RangeV3 
target_include_directories(RangeV3  SYSTEM INTERFACE ${ROOT_PATH_THIRD_PARTY}/range-v3-master/include)

# Require at least compiling with C++17.
target_compile_features(RangeV3  INTERFACE cxx_std_17 )

