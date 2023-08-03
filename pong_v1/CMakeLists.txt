cmake_minimum_required(VERSION 3.23)

project(GAME VERSION 1.0)

# Enable C++20 features
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)


add_executable(${PROJECT_NAME}
    src/main.cpp 
    src/userInput.cpp 
    src/ball.cpp
  )

# add_subdirectory(../Pong/)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${PROJECT_SOURCE_DIR}/src/
)

target_link_directories(${PROJECT_NAME}
  PRIVATE src/
)

target_link_libraries(${PROJECT_NAME}
  ${SDL2_LIBRARIES} 
  ${SDL2_TTF_LIBRARIES}
  SDL2main
  SDL2
  # Game
  
)
