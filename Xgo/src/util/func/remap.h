#pragma once

int remap(
    int value,
    int oldLow,
    int oldHigh,
    int newLow,
    int newHigh
) {
    return newLow + (value - oldLow) * (newHigh - newLow) / (oldHigh - oldLow);
}