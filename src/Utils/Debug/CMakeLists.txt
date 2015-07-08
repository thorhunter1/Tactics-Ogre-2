#add_subdirectory( Debug )

message( ${CMAKE_CURRENT_SOURCE_DIR} )

set(SOURCE
   ${SOURCE}
   PARENT_SCOPE
)
set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/Debug.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/TraceReturn.hpp
   PARENT_SCOPE
)
