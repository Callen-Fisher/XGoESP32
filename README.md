# XGoESP32
 
Robot: XGo Lite, purchased from Stelltron Education. 
Robot name: SAM (Stelltron Automated Mutt)
Makes use of Serial0

Add ons:
- Added a DF Robot Beetle ESP32 C3 - RISC-V which this code runs on, and sends commands to SAM.
- Neo pixel

Wiring instructions: 
- PIN 2: neo pixel
- PIN 9: connected to ground through switch, ground on power up to enter flashing mode to upload code.
- PIN 20: RX to SAM
- PIN 21: TX to SAM

Libraries used:
- Adafruit NeoPixel

Code modified from:
- Adafruit NeoPixel example strandtest_wheel
- https://github.com/Xgorobot/mini-pythonlib 
- https://github.com/DeflatedPickle/xgo/tree/2eb56ac9d3cce067436461d3ea573ca003f76b67


Files that you need to include in your project:
- xGo.h
- util/enum/xGo_names.h
- util/enum/send.h

List of functions to use:
- void stop_robot()                                                             :Tested and working
- int getMode()                                                                 :NEED TO CODE
- int getBatteryLevel()                                                         :NEED TO CODE
- Version::Version getVersion()                                                 :NEED TO CODE
- void setPerformanceMode(Mode::Mode mode)                                      :Tested and working.
- void unmount_all_motors()                                                     :NEED TO TEST
- void unmount_limb(Limb::Limb limb)                                            :NEED TO TEST
- void walk(Direction::Direction direction, int speed)                          :Tested and working. Speed 0-128;
- void rotate(Direction::Direction direction,int speed)                         :Tested and working. Speed 0-128;
- void bodyShift(Direction::Direction direction, int value)                     :Tested and working. value 0-128;
- void setBodyHeight(int height)                                                :Tested and working. Height 0-255;
- int getBodyHeight()                                                           :NEED TO CODE
- void adjustBodyHeight(int height)                                             :NEED TO CODE
- void setMaxRotationAngle(Axis::Axis axis, int angle)                          :NEED TO TEST
- void setSteppingHeight(int height)                                            :NEED TO TEST
- void setMovingMode(Speed::Speed speed)                                        :NEED TO TEST
- void setAction(Action::Action action)                                         :Tested and working.
- void setFootPosition(Limb::Limb limb,int x_pos, int y_pos, int z_pos)         :NEED TO TEST
- void setServoPosition(Limb::Limb limb,int servo1, int servo2, int servo3)     :NEED TO TEST
- void IMU_stabilize(bool val)                                                  :Tested and working. 
- int getIMUAngle(IMU::IMU axis)                                                :NEED TO CODE

TODO:
- make Serial0 user defined
- include send.h into xGo class
- calibration mode
- bluetooth mode
- reset zero position of servo
- periodic body rotation
- periodic body shift
- get foot position
- re-map all function values 
- set servo position
- set servo speed
- standing postion 
