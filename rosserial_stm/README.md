## rosserial_stm

This package is aimed to connect with STM32 platforms via rosserial. Currently, we are testing this on STM32F7 MCU.

### How to Use
#### Connect with board
* $roslaunch rosserial_stm rosserial.launch

#### Generate ros_lib for stm32 
* rosrun rosserial_stm make_libraries.py ${PATH}
( ${PATH}) is the path of the MCU project)

P.S. more information about the usage of ros_lib, please check another repo(tongtybj/MCU/STM32/stm_ros)
