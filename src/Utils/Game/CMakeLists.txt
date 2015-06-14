#add_subdirectory( Debug )

set(SOURCE
   ${SOURCE}
   PARENT_SCOPE
)
set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/OrientationEnum.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/TeamColorEnum.hpp
   PARENT_SCOPE
)
