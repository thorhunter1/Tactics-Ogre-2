add_subdirectory( Resources )
add_subdirectory( Utils )
add_subdirectory( Animation )
add_subdirectory( Unit )
add_subdirectory( Graphics )

set(SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
   PARENT_SCOPE
)
set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/SFML.hpp
   PARENT_SCOPE
)
