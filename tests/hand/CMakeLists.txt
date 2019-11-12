project(test_hand)

set(SOURCES  unitCatch.cpp  )
add_executable(${PROJECT_NAME} )
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE catchUnit hand bidding)
