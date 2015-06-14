#add_subdirectory( Preset )

set(SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/Animation.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/AnimationSet.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/AnimatedObject.cpp
   PARENT_SCOPE
)
set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/Animation.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/AnimationSet.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/AnimatedObject.hpp
   PARENT_SCOPE
)
