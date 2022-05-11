static const uint32_t USER_FRAME_ID = 0xAAA;
static const uint32_t ENGINE_FRAME_ID = 0xBBB;

namespace user_frame_data_partition {
static const uint8_t IGNITION = 0;
static const uint8_t LEVER = 1;
static const uint8_t PEDAL_POS = 2;
} // namespace user_frame_data_partition

namespace engine_frame_data_partition {
static const uint8_t VELOCITY = 0;
static const uint8_t RPM = 1;
static const uint8_t GEAR = 2;
} // namespace engine_frame_data_partition

namespace gear_lever {
static const uint8_t PARK = 0;
static const uint8_t REAR = 1;
static const uint8_t NEUTRAL = 2;
static const uint8_t DRIVE = 3;
} // namespace gear_lever