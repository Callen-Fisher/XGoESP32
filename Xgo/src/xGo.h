//Code modified from https://github.com/DeflatedPickle/xgo/tree/2eb56ac9d3cce067436461d3ea573ca003f76b67
#pragma once
#include "util/enum/xGo_names.h"
#include "util/func/send.h"
#define serial Serial0


//ADD THE SEND AND RECEIVE FUNCTIONS HERE!!


//two command types
int send_command=0x00;// no data returned
int receive_command=0x02;// data returned 

class Dog{
    public: 
        void setup()
        {
            serial.begin(baud_rate);
            while(!serial);
        }

        //Stop the robot, all params return to default
        void stop_robot(){
            walk(Direction::FORWARD,0);
            walk(Direction::LEFT,0);
            rotate(Direction::CW,0);
            setSteppingHeight(0);
            send(send_command, 0x3E, 255);//send action 255. Not sure if correct
        }

        //0x00 Mode of operation (R)
        //state information mode
        int getMode() {
            send(receive_command, 0x00,0x01);
            return read_data();         
        }
        
        //0x01 Battery level (R)
        //0(min) to 100(max)
        int getBatteryLevel() {
            send(receive_command, 0x01,0x01);
            return read_data();       
        }

        //0x02 XGO version (R)
        //0x00 Mini, 0x01 Lite, 0x02 Pro
        Version::Version getVersion() {
            send(receive_command, 0x02,0x01);
            int value = read_data();      

            switch (value) {
                case 0x00:
                    return Version::MINI;
                case 0x01:
                    return Version::LITE;
                case 0x02:
                    return Version::PRO;
                default:
                    break;
            }
        }
        //0x03 Performance mode (W)
        //0x00 normal control, 0x01 cyclic action
        //mode can be NORMAL or CYCLIC
        void setPerformanceMode(Mode::Mode mode) {
            switch (mode) {
                case Mode::NORMAL:
                    send(send_command, 0x03, 0x00);
                    break;
                case Mode::CYCLIC:
                    send(send_command, 0x03, 0x01);
                    break;
            }
        }

        //0x04 Calibration mode (W) 
        //0x01 enter calibration mode, 0x00 exit calibration mode
                                                     //TODO        not sure what to write here
        




        //0x13 Bluetooth (W) 
        //length of name is 10 bytes, after naming its XGO_xxxxx
                                                    //TODO         not sure what to write here







        //0x20 Unmount servo (RW)
        //0x00 normal operation, 0x01 unmount all, 0x11-0x14 unmount legs 1-4 in order, 0x21-0x24 remount legs 1-4
        //debug mode
        void unmount_all_motors(){
            send(send_command,0x20,0x01);
        }
        //limb can be LEFT_FORE, RIGHT_FORE, RIGHT_REAR, LEFT_REAR
        void unmount_limb(Limb::Limb limb){
            switch (limb) {
                case Limb::LEFT_FORE:
                    send(send_command, 0x20, 0x11);
                    break;
                case Limb::RIGHT_FORE:
                    send(send_command, 0x20, 0x12);
                    break;
                case Limb::RIGHT_REAR:
                    send(send_command, 0x20, 0x13);
                    break;
                case Limb::LEFT_REAR:
                    send(send_command, 0x20, 0x14);
                    break;
                default:
                    return;
            }
        }







        //0x21 Reset zero position of servo (W)
        //0x00 servo normal, 0x01 record the current position as zero position. 







        //0x30 Forward/Backwards movement speed (RW)
        //0x31 left/right movement speed (RW)
        //Speed: 0 to 128
        //direction can be FORWARD, BACKWARD, LEFT or RIGHT
        //whole unit mode
        void walk(Direction::Direction direction, int speed) {
            int value;
            switch (direction) {
                case Direction::FORWARD:
                    send(send_command, 0x30, speed+128);
                    break;
                case Direction::BACKWARD:
                    send(send_command, 0x30, 128-speed);
                    break;
                case Direction::LEFT:
                    send(send_command, 0x31, speed+128);
                    break;
                case Direction::RIGHT:
                    send(send_command, 0x31, 128-speed);
                    break;
                default:
                    return;
            }
            
        }
        //0x32 CW/CCW rotation speed (RW)                                 
        //Speed: 0-128
        //direction can be CW or CCW
        void rotate(Direction::Direction direction,int speed) {
            switch(direction)
            {
                case Direction::CW:
                    send(send_command, 0x32, 128-speed); 
                    break;
                case Direction::CCW:
                    send(send_command, 0x32, 128+speed); 
                    break;
            }
        }

        //0x33 Body shift X (RW)
        //0x34 Body shift Y (RW)
        //value: 0->128
        //direction can be FORWARD, BACKWARD, LEFT or RIGHT
        void bodyShift(Direction::Direction direction, int value) {
            switch(direction){
                case Direction::FORWARD:
                    send(send_command, 0x33, 128+value);
                    break;
                case Direction::BACKWARD:
                    send(send_command, 0x33, 128-value);
                    break;
                case Direction::LEFT:
                    send(send_command, 0x34, 128+value);
                    break;
                case Direction::RIGHT:
                    send(send_command, 0x34, 128-value);
                    break; 
            }
        }

        //0x35 Body height (RW)
        //height 0->255
        void setBodyHeight(int height) {
            send(send_command, 0x35, height); 
        }
        int getBodyHeight(){
            send(receive_command, 0x35,0x01);
            return read_data();                     
        }
        //height can be added/subtracted from the current height.
        //ranges from 0->255
        void adjustBodyHeight(int height){
            int temp=height+getBodyHeight();
            if(temp>255){
                temp=255;
            }else if(temp<0){
                temp=0;
            }
            send(send_command,0x35,temp);
        }

        //0x36 Body rotate about X (RW)
        //0x37 Body rotate about Y (RW)
        //0x38 Body rotate about Z (RW)
        void setMaxRotationAngle(Axis::Axis axis, int angle) {
            switch (axis) {
                case Axis::X:
                    send(send_command, 0x36, angle);
                    break;
                case Axis::Y:
                    send(send_command, 0x37, angle);
                    break;
                case Axis::Z:
                    send(send_command, 0x38, angle);
                    break;
            }
        }

        //0x39 A given period in which body rotates around X (RW)
        //0x3A A given period in which body rotates around Y (RW)
        //0x3B A given period in which body rotates around Z (RW)
        //0x00 stops, 0x01-0xff min-max rotation speed






        
        





        //0x3C mark time (RW)
        //0x00 stop, 0x01-0xff min-max mark time height
        void setSteppingHeight(int height) {
            send(send_command, 0x3C, height);
        }

        //0x3D moving mode (RW)
        //0x00 normal, 0x01 slow, 0x02 high speed
        //speed can be NORMAL, SLOW or FAST
        void setMovingMode(Speed::Speed speed) {
            switch (speed) {
                case Speed::NORMAL:
                    send(send_command, 0x3D, 0x00);
                    break;
                case Speed::SLOW:
                    send(send_command, 0x3D, 0x01);
                    break;
                case Speed::FAST:
                    send(send_command, 0x3D, 0x02);
                    break;
                default:
                    return;
            }
        }

        //0x3E action (W)
        //list of action commands
        //Look at xGo_names.h for a list of actions. 
        void setAction(Action::Action action) {
            switch (action) {
                case Action::NONE:
                    send(send_command, 0x3E, 0);
                    break;
                case Action::LIE:
                    send(send_command, 0x3E, 1);
                    break;
                case Action::STAND:
                    send(send_command, 0x3E, 2);
                    break;
                case Action::CREEP:
                    send(send_command, 0x3E, 3);
                    break;
                case Action::CIRCLE:
                    send(send_command, 0x3E, 4);
                    break;
                case Action::STEP:
                    send(send_command, 0x3E, 5);
                    break;
                case Action::SQUAT:
                    send(send_command, 0x3E, 6);
                    break;
                case Action::ROLL:
                    send(send_command, 0x3E, 7);
                    break;
                case Action::PITCH:
                    send(send_command, 0x3E, 8);
                    break;
                case Action::YAWN:
                    send(send_command, 0x3E, 9);
                    break;
                case Action::JIGGLE:
                    send(send_command, 0x3E, 10);
                    break;
                case Action::PEE:
                    send(send_command, 0x3E, 11);
                    break;
                case Action::SIT:
                    send(send_command, 0x3E, 12);
                    break;
                case Action::BECKON:
                    send(send_command, 0x3E, 13);
                    break;
                case Action::STRETCH:
                    send(send_command, 0x3E, 14);
                    break;
                case Action::WAVE:
                    send(send_command, 0x3E, 15);
                    break;
                case Action::SWAY:
                    send(send_command, 0x3E, 16);
                    break;
                case Action::BEG:
                    send(send_command, 0x3E, 17);
                    break;
                case Action::SEARCH:
                    send(send_command, 0x3E, 18);
                    break;
                default:
                    return;
            }
        }

        

        //0x80 a given period in which the body shifts along X axis (RW)
        //0x81 a given period in which the body shifts along Y axis (RW)
        //0x82 a given period in which the body shifts along Z axis (RW)
        //0x00 stop, 0x01 to 0xff min/max shift speed






        





        





        //0x40 to 0x4B leg positon (RW)
        //leg mode
        void setFootPosition(Limb::Limb limb,int x_pos, int y_pos, int z_pos){
            foot_position_address(limb);
            set(Axis::X, x_pos);
            set(Axis::Y, y_pos);
            set(Axis::Z, z_pos);
        }



        //TODO GET FOOT POSITION
    
    








        //0x50 to 0x5B servo position (RW)
        //servo mode
        void setServoPosition(Limb::Limb limb,int servo1, int servo2, int servo3){
            servo_address(limb);
            set(Axis::X, servo1);
            set(Axis::Y, servo2);
            set(Axis::Z, servo3);
        }



        //TODO GET SERVO POSITION
    






        //0x5C servo speed (RW)
        //0x00 to 0xff min-max value. Only applicable under this mode





        //0x5D standing posture (W) 
        //0x00 inactive, 0x01 returns to standing position




        //0x61 IMU state (RW) 
        //0x00 close, 0x01 self-stabilizing mode
        //val=true: stabilize with IMU
        //val=false: no stabilization
        void IMU_stabilize(bool val){
            if(val){
                send(send_command,0x61,0x01);
            }else{
                send(send_command,0x61,0x00);
            }
        }

        //0x62 ROLL (R)
        //0x63 PITCH (R)
        //0x64 YAW (R)
        int getIMUAngle(IMU::IMU axis){
            switch (axis){
                case IMU::ROLL:
                    send(receive_command,0x62,0x01);
                    break;
                case IMU::PITCH:
                    send(receive_command,0x63,0x01);
                    break;
                case IMU::YAW:
                    send(receive_command,0x64,0x01);
                    break;
                default:
                    return -1;
            }
            return read_data();                         
        }

    private:
        long baud_rate = 115200;
        int data_bit = 8;
        int stop_bit = 1;
        int x;
		int y;
		int z;
        int remap(int value,int oldLow,int oldHigh,int newLow,int newHigh) {
            return 0;
        }
        int read_data()
        {
            //will only work for functions returning 1 byte
            //add a timer to kick out if it gets stuck and misses comms
            while(serial.available()==0);
            int packetStart=serial.read();
            if(packetStart!=0x55){return 0;}
            while(serial.available()==0);
            packetStart=serial.read();
            if(packetStart!=0x00){return 0;}
            while(serial.available()==0);
            int frameLength=serial.read()-8;
            while(serial.available()==0);
            int commandType=serial.read();
            while(serial.available()==0);
            int firstAddress=serial.read();
            //should loop through data here
            while(serial.available()==0);
            int data=serial.read();
            while(serial.available()==0);
            int checkSum=serial.read();
            while(serial.available()==0);
            int packetEnd=serial.read();
            while(serial.available()==0);
            packetEnd=serial.read();

            return data;
        }
        int read_array(int *array)
        {
            //works for multiple values
            //add a timer to kick out if it gets stuck and misses comms
            while(serial.available()==0);
            int packetStart=serial.read();
            if(packetStart!=0x55){return 0;}
            while(serial.available()==0);
            packetStart=serial.read();
            if(packetStart!=0x00){return 0;}
            while(serial.available()==0);
            int frameLength=serial.read()-8;
            while(serial.available()==0);
            int commandType=serial.read();
            while(serial.available()==0);
            int firstAddress=serial.read();
            //should loop through data here
            int i=0;
            for(i=0;i<frameLength;i++)
            {
                while(serial.available()==0);
                array[i]=serial.read();
            }
            while(serial.available()==0);
            int checkSum=serial.read();
            while(serial.available()==0);
            int packetEnd=serial.read();
            while(serial.available()==0);
            packetEnd=serial.read();
            return 1;
        }
        void set(Axis::Axis axis, int value) {
			switch (axis) {
				case Axis::X:
					send(send_command, x, value);
                    break;
				case Axis::Y:
					send(send_command, y, value);
                    break;
				case Axis::Z:
					send(send_command, z, value);
                    break;
			}
		}
        //sets the address for the relevant positions for the specified limb
        void foot_position_address(Limb::Limb limb) 
        {
			switch (limb) {
				case Limb::LEFT_FORE:
					x = 0x40;
					y = 0x41;
					z = 0x42;
                    break;
				case Limb::RIGHT_FORE:
					x = 0x43;
					y = 0x44;
					z = 0x45;
                    break;
				case Limb::RIGHT_REAR:
					x = 0x46;
					y = 0x47;
					z = 0x48;
                    break;
				case Limb::LEFT_REAR:
					x = 0x49;
					y = 0x4A;
					z = 0x4B;
                    break;
			}
		}
        //sets the address for the relevant servos for the specified limb
        void servo_address(Limb::Limb limb) 
        {
			switch (limb) {
				case Limb::LEFT_FORE:
					x = 0x50;
					y = 0x51;
					z = 0x52;
                    break;
				case Limb::RIGHT_FORE:
					x = 0x53;
					y = 0x54;
					z = 0x55;
                    break;
				case Limb::RIGHT_REAR:
					x = 0x56;
					y = 0x57;
					z = 0x58;
                    break;
				case Limb::LEFT_REAR:
					x = 0x59;
					y = 0x5A;
					z = 0x5B;
                    break;
			}
		}
};