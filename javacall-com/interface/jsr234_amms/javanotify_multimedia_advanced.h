/*
 * Copyright  1990-2009 Sun Microsystems, Inc. All Rights Reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 only, as published by the Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License version 2 for more details (a copy is
 * included at /legal/license.txt).
 * 
 * You should have received a copy of the GNU General Public License
 * version 2 along with this work; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 * 
 * Please contact Sun Microsystems, Inc., 4150 Network Circle, Santa
 * Clara, CA 95054 or visit www.sun.com if you need additional
 * information or have any questions.
 */

#ifndef __JAVANOTIFY_MULTIMEDIA_ADVANCED_H
#define __JAVANOTIFY_MULTIMEDIA_ADVANCED_H

/**
 * @file javanotify_multimedia_advanced.h
 * @ingroup JSR234
 * @brief Javanotify interfaces for JSR-234, Advanced Multimedia Supplements
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <javacall_defs.h>

/**
 * @defgroup AMMSNotification API for Advanced Multimedia
 * @ingroup JSR234
 *
 * @brief Advanced multimedia related external events notification
 *
 * @{
 */

/* Event queue ID for AMMS. */
#define JSR234_EVENT_QUEUE_ID 234

/**
 * @typedef javacall_amms_notification_type. 
 * @brief Advanced multimedia notification type.
 * See JSR-234 MediaProcessorListener for description of 
 * \a JAVACALL_EVENT_AMMS_MEDIA_PROCESSOR_* events.
 */
typedef enum javacall_amms_notification_type {
    /** Posted when a Media processor has finished processing. */
    JAVACALL_EVENT_AMMS_MEDIA_PROCESSOR_COMPLETED,
    /** Posted when an error had occurred while processing. */
    JAVACALL_EVENT_AMMS_MEDIA_PROCESSOR_ERROR,
    
    /** This event is analogous to JSR-234 event RDSControl.RADIO_CHANGED,
      * see JSR-234 Spec at www.jcp.org
      */
    JAVACALL_EVENT_AMMS_RDS_RADIO_CHANGED,
    
    /** This event is analogous to JSR-234 event RDSControl.RDS_NEW_ALARM,
      * see JSR-234 Spec at www.jcp.org
      */
    JAVACALL_EVENT_AMMS_RDS_NEW_ALARM,
    
    /** This event is analogous to JSR-234 event RDSControl.RDS_NEW_DATA,
      * see JSR-234 Spec at www.jcp.org
      */
    JAVACALL_EVENT_AMMS_RDS_NEW_DATA,

    /** This event is analogous to JSR-234 event SnapshotControl.SHOOTING_STOPPED,
      * see JSR-234 Spec at www.jcp.org
      */
    JAVACALL_EVENT_AMMS_SNAP_SHOOTING_STOPPED,

    /** This event is analogous to JSR-234 event SnapshotControl.STORAGE_STOPPED,
      * see JSR-234 Spec at www.jcp.org
      */
    JAVACALL_EVENT_AMMS_SNAP_STORAGE_ERROR,
} javacall_amms_notification_type;

/**
 * Post native advanced multimedia event to Java event handler
 * 
 * @param type          Event type
 * @param processorId   Processor ID that came from \c javacall_media_processor_create 
 * function
 * @param data          Data that will be carried with this notification
 *                      - JAVACALL_EVENT_AMMS_MEDIA_PROCESSOR_COMPLETED
 *                          data = None.
 *                      - JAVACALL_EVENT_AMMS_MEDIA_PROCESSOR_ERROR
 *                          data = None.
 *                      - JAVACALL_EVENT_AMMS_RDS_RADIO_CHANGED
 *                          data = (int) The integer representing
 *                                 the PI of the new program
 *                      - JAVACALL_EVENT_AMMS_RDS_NEW_ALARM
 *                          data = (int) The integer representing
 *                                 the PI of the program where the alarm was 
 *                                  switched on
 *                      - JAVACALL_EVENT_AMMS_RDS_NEW_DATA
 *                          data = (int) The integer representing
 *                                 the PI of the program where the new data was
 *                                 received
 *                      - JAVACALL_EVENT_AMMS_SNAP_SHOOTING_STOPPED
 *                          data = (javacall_utf16_string)
 *                                 filename of last saved file 
 *                      - JAVACALL_EVENT_AMMS_SNAP_STORAGE_ERROR
 *                          data = (javacall_utf16_string)
 *                                 filename of last saved file 
 */
void javanotify_on_amms_notification(javacall_amms_notification_type type,
                                     javacall_int64 processorId,
                                     void* data);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /*__JAVANOTIFY_MULTIMEDIA_ADVANCED_H*/
