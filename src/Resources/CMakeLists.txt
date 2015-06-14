add_subdirectory( Preset )

set(SOURCE
   ${SOURCE}
   PARENT_SCOPE
)
set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/Preset.hpp
   PARENT_SCOPE
)
