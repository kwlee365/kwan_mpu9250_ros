cmake_minimum_required(VERSION 3.0.2)
project(kwan_mpu9250_ros)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  visualization_msgs
  tf2
  tf2_ros
)

catkin_package(
  CATKIN_DEPENDS roscpp rospy std_msgs visualization_msgs
  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)


set(SRC_FILES src/imu_tf_broadcaster.cpp)
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Specify libraries to link a library or executable target against
target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
)
