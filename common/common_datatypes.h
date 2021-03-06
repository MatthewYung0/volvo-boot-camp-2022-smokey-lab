#include <cstdint>

// Frame IDs
static const uint32_t USER_FRAME_ID = 0xAA;
static const uint32_t ENGINE_FRAME_ID = 0xBB;

// Exit code
namespace keyboard_common_input {
static const int EXIT = 'q';
}

namespace user_frame_data_partition {
static const uint8_t IGNITION = 0;
static const uint8_t LEVER = 1;
static const uint8_t PEDAL_POS = 2;
static const uint8_t EXIT = 7;
} // namespace user_frame_data_partition

namespace engine_frame_data_partition {
static const uint8_t VELOCITY = 0;
static const uint8_t LEVER = 1;
static const uint8_t GEAR = 2;
static const uint8_t IGNITION = 3;
static const uint8_t RPM_1 = 4;
static const uint8_t RPM_2 = 5;
static const uint8_t RPM_3 = 6;
static const uint8_t RPM_4 = 7;
} // namespace engine_frame_data_partition

namespace gear_lever {
static const uint8_t PARK = 0;
static const uint8_t NEUTRAL = 1;
static const uint8_t REAR = 2;
static const uint8_t DRIVE = 3;
} // namespace gear_lever