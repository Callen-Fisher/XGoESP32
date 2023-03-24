#pragma once

namespace Action {
  enum Action {
    NONE,
    LIE,
    STAND,
    CREEP,
    CIRCLE,
    STEP,
    SQUAT,
    ROLL,
    PITCH,
    YAWN,
    JIGGLE,
    PEE,
    SIT,
    BECKON,
    STRETCH,
    WAVE,
    SWAY,
    BEG,
    SEARCH,
  };
}

namespace Axis {
  enum Axis {
    X,
    Y,
    Z,
  };
}

namespace BluetoothStatus {
  enum BluetoothStatus {
    NONE,
    DISCONNECTED,
    CONNRECTED,
  };
}

namespace Direction {
    enum Direction {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT,
    };
}

namespace Gear {
    enum Gear {
        ALL,
        LEFT_FORE,
        RIGHT_FORE,
        RIGHT_REAR,
        LEFT_REAR,
    };
}

namespace Limb {
    enum Limb {
        LEFT_FORE,
        RIGHT_FORE,
        RIGHT_REAR,
        LEFT_REAR,
    };
}

namespace Speed {
  enum Speed {
    NORMAL,
    SLOW,
    FAST,
  };
}

namespace Version {
  enum Version {
    MINI,
    LITE,
    PRO,
  };
}

namespace Mode {
  enum Mode {
    NORMAL,
    CYCLIC,
  };
}

namespace IMU {
  enum IMU {
    ROLL,
    PITCH,
    YAW,
  };
}