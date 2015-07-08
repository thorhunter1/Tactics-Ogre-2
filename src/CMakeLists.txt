add_subdirectory( Resources )
add_subdirectory( Utils )
add_subdirectory( Animation )
add_subdirectory( Unit )
add_subdirectory( Graphics )
add_subdirectory( Factory )
add_subdirectory( Isometry )

set(SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
   PARENT_SCOPE
)
set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/SFML.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/Animation.hh
   ${CMAKE_CURRENT_SOURCE_DIR}/Factory.hh
   ${CMAKE_CURRENT_SOURCE_DIR}/Graphics.hh
   ${CMAKE_CURRENT_SOURCE_DIR}/Isometry.hh
   ${CMAKE_CURRENT_SOURCE_DIR}/Resources.hh
   ${CMAKE_CURRENT_SOURCE_DIR}/Unit.hh
   ${CMAKE_CURRENT_SOURCE_DIR}/Utils.hh

   PARENT_SCOPE
)
