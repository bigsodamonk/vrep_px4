#pragma once
// MESSAGE SYSTEM_TIME_UTC PACKING

#define MAVLINK_MSG_ID_SYSTEM_TIME_UTC 4

MAVPACKED(
typedef struct __mavlink_system_time_utc_t {
 uint32_t utc_date; /*< GPS UTC date ddmmyy*/
 uint32_t utc_time; /*< GPS UTC time hhmmss*/
}) mavlink_system_time_utc_t;

#define MAVLINK_MSG_ID_SYSTEM_TIME_UTC_LEN 8
#define MAVLINK_MSG_ID_SYSTEM_TIME_UTC_MIN_LEN 8
#define MAVLINK_MSG_ID_4_LEN 8
#define MAVLINK_MSG_ID_4_MIN_LEN 8

#define MAVLINK_MSG_ID_SYSTEM_TIME_UTC_CRC 191
#define MAVLINK_MSG_ID_4_CRC 191



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SYSTEM_TIME_UTC { \
    4, \
    "SYSTEM_TIME_UTC", \
    2, \
    {  { "utc_date", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_system_time_utc_t, utc_date) }, \
         { "utc_time", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_system_time_utc_t, utc_time) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SYSTEM_TIME_UTC { \
    "SYSTEM_TIME_UTC", \
    2, \
    {  { "utc_date", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_system_time_utc_t, utc_date) }, \
         { "utc_time", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_system_time_utc_t, utc_time) }, \
         } \
}
#endif

/**
 * @brief Pack a system_time_utc message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param utc_date GPS UTC date ddmmyy
 * @param utc_time GPS UTC time hhmmss
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_system_time_utc_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t utc_date, uint32_t utc_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYSTEM_TIME_UTC_LEN];
    _mav_put_uint32_t(buf, 0, utc_date);
    _mav_put_uint32_t(buf, 4, utc_time);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SYSTEM_TIME_UTC_LEN);
#else
    mavlink_system_time_utc_t packet;
    packet.utc_date = utc_date;
    packet.utc_time = utc_time;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SYSTEM_TIME_UTC_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SYSTEM_TIME_UTC;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SYSTEM_TIME_UTC_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_UTC_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_UTC_CRC);
}

/**
 * @brief Pack a system_time_utc message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param utc_date GPS UTC date ddmmyy
 * @param utc_time GPS UTC time hhmmss
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_system_time_utc_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t utc_date,uint32_t utc_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYSTEM_TIME_UTC_LEN];
    _mav_put_uint32_t(buf, 0, utc_date);
    _mav_put_uint32_t(buf, 4, utc_time);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SYSTEM_TIME_UTC_LEN);
#else
    mavlink_system_time_utc_t packet;
    packet.utc_date = utc_date;
    packet.utc_time = utc_time;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SYSTEM_TIME_UTC_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SYSTEM_TIME_UTC;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SYSTEM_TIME_UTC_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_UTC_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_UTC_CRC);
}

/**
 * @brief Encode a system_time_utc struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param system_time_utc C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_system_time_utc_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_system_time_utc_t* system_time_utc)
{
    return mavlink_msg_system_time_utc_pack(system_id, component_id, msg, system_time_utc->utc_date, system_time_utc->utc_time);
}

/**
 * @brief Encode a system_time_utc struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param system_time_utc C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_system_time_utc_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_system_time_utc_t* system_time_utc)
{
    return mavlink_msg_system_time_utc_pack_chan(system_id, component_id, chan, msg, system_time_utc->utc_date, system_time_utc->utc_time);
}

/**
 * @brief Send a system_time_utc message
 * @param chan MAVLink channel to send the message
 *
 * @param utc_date GPS UTC date ddmmyy
 * @param utc_time GPS UTC time hhmmss
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_system_time_utc_send(mavlink_channel_t chan, uint32_t utc_date, uint32_t utc_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYSTEM_TIME_UTC_LEN];
    _mav_put_uint32_t(buf, 0, utc_date);
    _mav_put_uint32_t(buf, 4, utc_time);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_TIME_UTC, buf, MAVLINK_MSG_ID_SYSTEM_TIME_UTC_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_UTC_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_UTC_CRC);
#else
    mavlink_system_time_utc_t packet;
    packet.utc_date = utc_date;
    packet.utc_time = utc_time;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_TIME_UTC, (const char *)&packet, MAVLINK_MSG_ID_SYSTEM_TIME_UTC_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_UTC_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_UTC_CRC);
#endif
}

/**
 * @brief Send a system_time_utc message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_system_time_utc_send_struct(mavlink_channel_t chan, const mavlink_system_time_utc_t* system_time_utc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_system_time_utc_send(chan, system_time_utc->utc_date, system_time_utc->utc_time);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_TIME_UTC, (const char *)system_time_utc, MAVLINK_MSG_ID_SYSTEM_TIME_UTC_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_UTC_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_UTC_CRC);
#endif
}

#if MAVLINK_MSG_ID_SYSTEM_TIME_UTC_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_system_time_utc_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t utc_date, uint32_t utc_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, utc_date);
    _mav_put_uint32_t(buf, 4, utc_time);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_TIME_UTC, buf, MAVLINK_MSG_ID_SYSTEM_TIME_UTC_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_UTC_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_UTC_CRC);
#else
    mavlink_system_time_utc_t *packet = (mavlink_system_time_utc_t *)msgbuf;
    packet->utc_date = utc_date;
    packet->utc_time = utc_time;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_TIME_UTC, (const char *)packet, MAVLINK_MSG_ID_SYSTEM_TIME_UTC_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_UTC_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_UTC_CRC);
#endif
}
#endif

#endif

// MESSAGE SYSTEM_TIME_UTC UNPACKING


/**
 * @brief Get field utc_date from system_time_utc message
 *
 * @return GPS UTC date ddmmyy
 */
static inline uint32_t mavlink_msg_system_time_utc_get_utc_date(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field utc_time from system_time_utc message
 *
 * @return GPS UTC time hhmmss
 */
static inline uint32_t mavlink_msg_system_time_utc_get_utc_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Decode a system_time_utc message into a struct
 *
 * @param msg The message to decode
 * @param system_time_utc C-struct to decode the message contents into
 */
static inline void mavlink_msg_system_time_utc_decode(const mavlink_message_t* msg, mavlink_system_time_utc_t* system_time_utc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    system_time_utc->utc_date = mavlink_msg_system_time_utc_get_utc_date(msg);
    system_time_utc->utc_time = mavlink_msg_system_time_utc_get_utc_time(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SYSTEM_TIME_UTC_LEN? msg->len : MAVLINK_MSG_ID_SYSTEM_TIME_UTC_LEN;
        memset(system_time_utc, 0, MAVLINK_MSG_ID_SYSTEM_TIME_UTC_LEN);
    memcpy(system_time_utc, _MAV_PAYLOAD(msg), len);
#endif
}
