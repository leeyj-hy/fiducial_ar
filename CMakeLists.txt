cmake_minimum_required(VERSION 3.0.2)
project(fiducial_ar)


find_package(catkin REQUIRED COMPONENTS
  fiducial_msgs
  roscpp
  rospy
  std_msgs
  sensor_msgs
  cv_bridge
)

find_package(OpenCV REQUIRED)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES fiducial_ar
#  CATKIN_DEPENDS fiducial_msgs roscpp rospy std_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


add_executable(fiducial_ar src/fiducial_ar_node.cpp)

add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
  ${OpenCV_LIBS}
)
