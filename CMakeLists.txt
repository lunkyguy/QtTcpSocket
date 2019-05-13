
cmake_minimum_required(VERSION 3.5)
project(QtTcp)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Core)
find_package(Qt5Network)

set(APP_SRC 
	"main.cpp" 
	"QtTcpSocket.cpp" 
	"QtTcpSocket.cpp"
	)

add_executable(QtTcpSocket ${APP_SRC})
target_link_libraries(QtTcpSocket Qt5::Core Qt5::Network)