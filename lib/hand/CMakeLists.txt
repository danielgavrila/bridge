
project( hand
         VERSION 1.0.0
         DESCRIPTION "The hand evaluation  " )


add_library( ${PROJECT_NAME} SHARED )
target_sources( ${PROJECT_NAME} PRIVATE    
    "src/evalhand.cpp"

    )

# Required include search-paths 
target_include_directories( ${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

target_link_libraries( ${PROJECT_NAME} PUBLIC  stdc++ ) 
install(TARGETS ${PROJECT_NAME} DESTINATION "${lib_dest}")
