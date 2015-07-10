add_subdirectory( Preset )

set(SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/Preset.cpp
   PARENT_SCOPE
)
set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/Preset.hpp
   PARENT_SCOPE
)
