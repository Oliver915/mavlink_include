#pragma once
// MESSAGE CHANGE_FPV PACKING

#define MAVLINK_MSG_ID_CHANGE_FPV 95


typedef struct __mavlink_change_fpv_t {
 uint64_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 uint8_t vehicle_id; /*<  */
} mavlink_change_fpv_t;

#define MAVLINK_MSG_ID_CHANGE_FPV_LEN 9
#define MAVLINK_MSG_ID_CHANGE_FPV_MIN_LEN 9
#define MAVLINK_MSG_ID_95_LEN 9
#define MAVLINK_MSG_ID_95_MIN_LEN 9

#define MAVLINK_MSG_ID_CHANGE_FPV_CRC 127
#define MAVLINK_MSG_ID_95_CRC 127



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CHANGE_FPV { \
    95, \
    "CHANGE_FPV", \
    2, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_change_fpv_t, time_boot_ms) }, \
         { "vehicle_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_change_fpv_t, vehicle_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CHANGE_FPV { \
    "CHANGE_FPV", \
    2, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_change_fpv_t, time_boot_ms) }, \
         { "vehicle_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_change_fpv_t, vehicle_id) }, \
         } \
}
#endif

/**
 * @brief Pack a change_fpv message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param vehicle_id  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_change_fpv_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_boot_ms, uint8_t vehicle_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CHANGE_FPV_LEN];
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_uint8_t(buf, 8, vehicle_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CHANGE_FPV_LEN);
#else
    mavlink_change_fpv_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.vehicle_id = vehicle_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CHANGE_FPV_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CHANGE_FPV;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CHANGE_FPV_MIN_LEN, MAVLINK_MSG_ID_CHANGE_FPV_LEN, MAVLINK_MSG_ID_CHANGE_FPV_CRC);
}

/**
 * @brief Pack a change_fpv message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param vehicle_id  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_change_fpv_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_boot_ms,uint8_t vehicle_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CHANGE_FPV_LEN];
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_uint8_t(buf, 8, vehicle_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CHANGE_FPV_LEN);
#else
    mavlink_change_fpv_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.vehicle_id = vehicle_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CHANGE_FPV_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CHANGE_FPV;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CHANGE_FPV_MIN_LEN, MAVLINK_MSG_ID_CHANGE_FPV_LEN, MAVLINK_MSG_ID_CHANGE_FPV_CRC);
}

/**
 * @brief Encode a change_fpv struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param change_fpv C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_change_fpv_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_change_fpv_t* change_fpv)
{
    return mavlink_msg_change_fpv_pack(system_id, component_id, msg, change_fpv->time_boot_ms, change_fpv->vehicle_id);
}

/**
 * @brief Encode a change_fpv struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param change_fpv C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_change_fpv_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_change_fpv_t* change_fpv)
{
    return mavlink_msg_change_fpv_pack_chan(system_id, component_id, chan, msg, change_fpv->time_boot_ms, change_fpv->vehicle_id);
}

/**
 * @brief Send a change_fpv message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param vehicle_id  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_change_fpv_send(mavlink_channel_t chan, uint64_t time_boot_ms, uint8_t vehicle_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CHANGE_FPV_LEN];
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_uint8_t(buf, 8, vehicle_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHANGE_FPV, buf, MAVLINK_MSG_ID_CHANGE_FPV_MIN_LEN, MAVLINK_MSG_ID_CHANGE_FPV_LEN, MAVLINK_MSG_ID_CHANGE_FPV_CRC);
#else
    mavlink_change_fpv_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.vehicle_id = vehicle_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHANGE_FPV, (const char *)&packet, MAVLINK_MSG_ID_CHANGE_FPV_MIN_LEN, MAVLINK_MSG_ID_CHANGE_FPV_LEN, MAVLINK_MSG_ID_CHANGE_FPV_CRC);
#endif
}

/**
 * @brief Send a change_fpv message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_change_fpv_send_struct(mavlink_channel_t chan, const mavlink_change_fpv_t* change_fpv)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_change_fpv_send(chan, change_fpv->time_boot_ms, change_fpv->vehicle_id);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHANGE_FPV, (const char *)change_fpv, MAVLINK_MSG_ID_CHANGE_FPV_MIN_LEN, MAVLINK_MSG_ID_CHANGE_FPV_LEN, MAVLINK_MSG_ID_CHANGE_FPV_CRC);
#endif
}

#if MAVLINK_MSG_ID_CHANGE_FPV_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_change_fpv_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_boot_ms, uint8_t vehicle_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_uint8_t(buf, 8, vehicle_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHANGE_FPV, buf, MAVLINK_MSG_ID_CHANGE_FPV_MIN_LEN, MAVLINK_MSG_ID_CHANGE_FPV_LEN, MAVLINK_MSG_ID_CHANGE_FPV_CRC);
#else
    mavlink_change_fpv_t *packet = (mavlink_change_fpv_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->vehicle_id = vehicle_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHANGE_FPV, (const char *)packet, MAVLINK_MSG_ID_CHANGE_FPV_MIN_LEN, MAVLINK_MSG_ID_CHANGE_FPV_LEN, MAVLINK_MSG_ID_CHANGE_FPV_CRC);
#endif
}
#endif

#endif

// MESSAGE CHANGE_FPV UNPACKING


/**
 * @brief Get field time_boot_ms from change_fpv message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint64_t mavlink_msg_change_fpv_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field vehicle_id from change_fpv message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_change_fpv_get_vehicle_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Decode a change_fpv message into a struct
 *
 * @param msg The message to decode
 * @param change_fpv C-struct to decode the message contents into
 */
static inline void mavlink_msg_change_fpv_decode(const mavlink_message_t* msg, mavlink_change_fpv_t* change_fpv)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    change_fpv->time_boot_ms = mavlink_msg_change_fpv_get_time_boot_ms(msg);
    change_fpv->vehicle_id = mavlink_msg_change_fpv_get_vehicle_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CHANGE_FPV_LEN? msg->len : MAVLINK_MSG_ID_CHANGE_FPV_LEN;
        memset(change_fpv, 0, MAVLINK_MSG_ID_CHANGE_FPV_LEN);
    memcpy(change_fpv, _MAV_PAYLOAD(msg), len);
#endif
}
