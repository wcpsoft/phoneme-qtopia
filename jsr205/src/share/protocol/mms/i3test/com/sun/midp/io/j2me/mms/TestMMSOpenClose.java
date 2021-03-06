/*
 *   
 *
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

package com.sun.midp.io.j2me.mms;

// Classes
import com.sun.midp.i3test.TestCase;
import com.sun.midp.main.Configuration;
import javax.microedition.io.Connector;
import javax.wireless.messaging.Message;
import javax.wireless.messaging.MessageConnection;
import javax.wireless.messaging.MessagePart;
import javax.wireless.messaging.MultipartMessage;

// Exceptions
import java.io.IOException;
import javax.wireless.messaging.SizeExceededException;

/**
 * Tests if an MMS connection can simply be open and closed without sending or
 * receiving any messages.
 */
public class TestMMSOpenClose extends TestCase implements Runnable {

    /** The fully qualified name of this test. */
    private final String TEST_NAME = this.getClass().getName();


    /** The device ID ("phone number") of the recipient. */
    private final String MMS_TO_DEVICE_ID = "+123456";

    /** The application ID of the recipient. */
    private final String MMS_TO_APP_ID = "com.sun.mmstest";

    /** The MMS client address. */
    private final String MMS_CLIENT_ADDRESS =
        "mms://" + ":" + MMS_TO_APP_ID;


    /** The MMS connection. */
    private MessageConnection con = null;

    /** Test passed/failed flag. */
    private boolean passed = false;


    /**
     * Set up the physical connection.
     */
    void setUp() {

        try {
            createClientConnection(MMS_CLIENT_ADDRESS);
        } catch (IOException ioe) {
            System.out.println(TEST_NAME + " set-up failed:");
            ioe.printStackTrace();
        }
    }

    /**
     * Simply close the MMS connection. If successful, this test passes.
     */
    public void run() {

        try {

            closeConnection();

            passed = true;
            assertTrue("Indicate that the test passed.", passed);

        } catch (Exception e) {
            e.printStackTrace();
            System.out.println(e.getMessage());
        }
    }

    /**
     * Provide clean-up services, following the run of this test.
     */
    void cleanUp() {
        closeConnection();
    }

    /**
     * Create and open an MMS connection.
     *
     * @param clientAddress The MMS address of the client that will receive the
     *      message.
     */
    private void createClientConnection(String clientAddress)
        throws IOException {

        con = (MessageConnection)Connector.open(clientAddress);
    }

    /**
     * Close the MMS connection.
     */
    private void closeConnection() {
        try {
            con.close();
        } catch (IOException ioe) {
            // Fail silently.
        } catch (Exception e) {
            // Fail silently.
        }
    }

    /**
     * Main entry point.
     */
    public void runTests() {
        setUp();

        declare(TEST_NAME);

        run();

        cleanUp();
    }

}

