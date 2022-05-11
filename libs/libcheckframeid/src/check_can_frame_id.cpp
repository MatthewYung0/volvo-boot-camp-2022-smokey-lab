#include "check_can_frame_id.h"

bool check_can_frame_id(scpp::CanFrame can_message, int const frame_id) {
    return (can_message.id == frame_id);
}