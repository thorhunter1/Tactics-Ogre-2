#add_subdirectory( Unit )

set(SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/SmallUnit.cpp
   PARENT_SCOPE
)
set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/SmallUnit.hpp
   PARENT_SCOPE
)
