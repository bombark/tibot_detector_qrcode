cmake_minimum_required (VERSION 2.6)
project (camera_fake)

find_package( OpenCV REQUIRED )

add_executable (detector_qrcode src/main.cpp)
target_link_libraries (detector_qrcode tiobj ${OpenCV_LIBS} zbar)

