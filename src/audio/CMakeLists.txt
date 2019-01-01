find_package(PulseAudio REQUIRED)

add_library(
  audio

  STATIC

  Audio.hpp

  PulseAudio.hpp
  PulseAudio.cpp
)

target_include_directories(
  audio

  PUBLIC

  "${CMAKE_CURRENT_BINARY_DIR}/../.."
)

target_compile_options(
  audio
  PRIVATE
  ${COMMON_COMPILER_FLAGS}
)

target_link_libraries(
  audio

  PRIVATE
  PulseAudio::Simple
)

set_property(TARGET audio PROPERTY CXX_STANDARD 17)
