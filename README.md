# XGoESP32
 
- mention Stelltron Education, XGo mini and Elecfreaks
- mention the code that I modified, reference in code and add a link here to their repository
- mentio all the libraries I have used, neo, PS, Xgo 



Makes use of Serial0
Files that you need to include in your project:
- xGo.h
-util/enum/xGo_names.h
-util/enum/send.h

List of functions to use:
-void stop_robot()
-int getMode()
-int getBatteryLevel()
-Version::Version getVersion()
-void setPerformanceMode(Mode::Mode mode)
-void unmount_all_motors()
-void unmount_limb(Limb::Limb limb)
-void walk(Axis::Axis axis, Direction::Direction direction, int speed)
-void rotate(int speed)
-void bodyShift(Axis::Axis axis, int value)
-void setBodyHeight(int height)
-int getBodyHeight()
-void adjustBodyHeight(int height)
-void setMaxRotationAngle(Axis::Axis axis, int angle)
-void setSteppingHeight(int height) 
-void setMovingMode(Speed::Speed speed) 
-void setAction(Action::Action action)
-void setFootPosition(Limb::Limb limb,int x_pos, int y_pos, int z_pos)
-void setServoPosition(Limb::Limb limb,int servo1, int servo2, int servo3)
-void IMU_stabilize(bool val)
-int getIMUAngle(IMU::IMU axis)

TODO:
-make Serial0 user defined
-include send.h into xGo class
-calibration mode
-bluetooth mode
-reset zero position of servo
-periodic body rotation
-periodic body shift
-get foot position
-re-map all function values 
-set servo position
-set servo speed
-standing postion 
