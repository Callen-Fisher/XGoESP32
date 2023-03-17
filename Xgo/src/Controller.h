#pragma once

#include "util/enum/Speed.h"
#include "util/enum/Action.h"
#include "util/enum/Axis.h"
#include "util/enum/Direction.h"
#include "util/func/remap.h"

class Controller {
  public:
    //Controller();

    /*0x30,0x31*/ int getMovementSpeed(Axis::Axis axis);
    
    /*0x30,0x31*/ void walk(Axis::Axis axis, /*Direction direction,*/ int speed) {
      /*int value;

      switch (direction) {
        case Direction.FORWARD:
          value = remap(speed, 0, 100, 128, 255);
        case Direction.BACKWARD:
          value = remap(speed, 0, 100, 128, 0);
        default:
          return;
      }*/

      switch (axis) {
        case Axis::X:
          send(0x30, speed);
        case Axis::Y:
          send(0x31, speed);
        default:
          return;
      }
    }
    
    /*0x32*/ int getRotationSpeed();
    /*0x32*/ void rotate(int speed) {
      send(0x32, speed);
    }

    /*0x33,0x34*/ int getTwist(Axis::Axis axis);
    /*0x33,0x34*/ void setTwist(Axis::Axis axis, int value) {
      switch (axis) {
        case Axis::X:
          send(0x33, value);
        case Axis::Y:
          send(0x34, value);
        default:
          return;
      }
    }

    /*0x35*/ int getBodyHeight();
    /*0x35*/ void setBodyHeight(int height) {
      send(0x35, height);
    }

    /*0x36,0x37,0x38*/ int getMaxRotationAngle(Axis::Axis axis);
    /*0x36,0x37,0x38*/ void setMaxRotationAngle(Axis::Axis axis, int angle) {
      switch (axis) {
        case Axis::X:
          send(0x36, angle);
        case Axis::Y:
          send(0x37, angle);
        case Axis::Z:
          send(0x38, angle);
      }
    }

    /*0x39,0x3A,0x3B*/ int getMinRotationSpeed(Axis::Axis axis);
    /*0x39,0x3A,0x3B*/ void setMinRotationSpeed(Axis::Axis axis);
    /*0x39,0x3A,0x3B*/ int getMaxRotationSpeed(Axis::Axis axis);
    /*0x39,0x3A,0x3B*/ void setMaxRotationSpeed(Axis::Axis axis);

    /*0x3C*/ int getSteppingHeight();
    /*0x3C*/ void setSteppingHeight(int height) {
      send(0x3C, height);
    }

    /*0x3D*/ Speed::Speed getMovingMode();
    /*0x3D*/ void setMovingMode(Speed::Speed speed) {
      switch (speed) {
        case Speed::NORMAL:
          send(0x3D, 0x00);
        case Speed::SLOW:
          send(0x3D, 0x01);
        case Speed::FAST:
          send(0x3D, 0x02);
        default:
          return;
      }
    }

    /*0x3E*/ void setAction(Action::Action action) {
      switch (action) {
        case Action::NONE:
          send(0x3E, 0);
        case Action::LIE:
          send(0x3E, 1);
        case Action::STAND:
          send(0x3E, 2);
        case Action::CREEP:
          send(0x3E, 3);
        case Action::CIRCLE:
          send(0x3E, 4);
        case Action::STEP:
          send(0x3E, 5);
        case Action::SQUAT:
          send(0x3E, 6);
        case Action::ROLL:
          send(0x3E, 7);
        case Action::PITCH:
          send(0x3E, 8);
        case Action::YAWN:
          send(0x3E, 9);
        case Action::JIGGLE:
          send(0x3E, 10);
        case Action::PEE:
          send(0x3E, 11);
        case Action::SIT:
          send(0x3E, 12);
        case Action::BECKON:
          send(0x3E, 13);
        case Action::STRETCH:
          send(0x3E, 14);
        case Action::WAVE:
          send(0x3E, 15);
        case Action::SWAY:
          send(0x3E, 16);
        case Action::BEG:
          send(0x3E, 17);
        case Action::SEARCH:
          send(0x3E, 18);
        default:
          return;
      }
    }
    
    /*0x80,0x81,0x82*/ int getMinSteppingSpeed(Axis::Axis axis);
    /*0x80,0x81,0x82*/ void setMinSteppingSpeed(Axis::Axis axis);
    /*0x80,0x81,0x82*/ int getMaxSteppingSpeed(Axis::Axis axis);
    /*0x80,0x81,0x82*/ void setMaxSteppingSpeed(Axis::Axis axis);
};
