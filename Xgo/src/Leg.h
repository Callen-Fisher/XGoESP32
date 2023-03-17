#pragma once

#include "util/enum/Limb.h"
#include "util/func/send.h"

class Leg {
	public:
		Leg(Limb::Limb limb) {
			switch (limb) {
				case Limb::LEFT_FORE:
					x = 0x40;
					y = 0x41;
					z = 0x42;
				case Limb::RIGHT_FORE:
					x = 0x43;
					y = 0x44;
					z = 0x45;
				case Limb::RIGHT_REAR:
					x = 0x46;
					y = 0x47;
					z = 0x48;
				case Limb::LEFT_REAR:
					x = 0x49;
					y = 0x4A;
					z = 0x4B;
			}
		}

		void set(Axis::Axis axis, int value) {
			switch (axis) {
				case Axis::X:
					send(0x00, x, value);
				case Axis::Y:
					send(0x00, y, value);
				case Axis::Z:
					send(0x00, z, value);
			}
		}
	private:
		int x;
		int y;
		int z;
};
