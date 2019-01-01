add_subdirectory(audio)

add_executable(
  pptuner

  main.cpp
)

target_link_libraries(
  pptuner

  PRIVATE

  audio
)
