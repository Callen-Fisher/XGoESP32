#pragma once
#define serial Serial0
//code modified from https://github.com/DeflatedPickle/xgo/tree/2eb56ac9d3cce067436461d3ea573ca003f76b67
// Credit to DarthTux from the Arduino Discord server for coming up with this
// Thanks for all your help!

// Compile-time summation
template <typename ... Args> constexpr
uint8_t sum(const uint8_t data, Args ... args) {
    return data + sum(args...);
}

// Specialization for the single, remaining data byte
template <>
inline uint8_t sum(const uint8_t data) {
    return data;
}

// Compile-time frame/packet build/send
template <typename ... Args> constexpr
void send(uint8_t command_type, Args ... args) {
    const uint8_t data_count = sizeof... (Args);   // command, value
    const uint8_t frame_count = data_count + 3;    // + checksum & length & commandType
    const uint8_t packet_length = frame_count + 4; // + prefix & suffix

    /* frame: prefix, length, command, checksum, suffix */
    const uint8_t data[packet_length] = {
        0x55, 0x0,  // prefix
        packet_length,
        command_type,
        uint8_t(args)..., uint8_t(~sum(packet_length,command_type, args...)),
        0x00, 0xAA  // suffix
    };
    //uint8_t temp[9]={0x55, 0x00, 0x09, 0x00, 0x30, 0xFF, 0xC7, 0x00, 0xAA};
    serial.write(data, packet_length);
}

