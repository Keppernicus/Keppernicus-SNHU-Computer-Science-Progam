package org.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class ContactTest {

    // if it goes well
    @Test
    void createsValidContact() {
        Contact c = new Contact(
                "ABC1234567",
                "FirstName",
                "LastName",
                "0123456789",
                "111 Broad st, Apt 6"
        );

        assertEquals("ABC1234567", c.getContactId());
        assertEquals("FirstName", c.getFirstName());
        assertEquals("LastName", c.getLastName());
        assertEquals("0123456789", c.getPhone());
        assertEquals("111 Broad st, Apt 6", c.getAddress());
    }

    //the rules for contactId
    @Test
    void contactId_isRequired_andMax10_andImmutabe() {
        assertThrows(IllegalArgumentException.class,
                () -> new Contact(null, "A", "Z", "0123456789", "addr"));
        assertThrows(IllegalArgumentException.class,
                () -> new Contact("11111111111", "A", "Z", "0123456789", "addr")); //too many characters

        Contact c = new Contact("idd", "z", "c", "0123456789", "addr"); //check immutability of contactId
        assertEquals("idd", c.getContactId());
    }

    //first name rules
    @Test
    void firstName_required_andMax10() {
        assertThrows(IllegalArgumentException.class,
                () -> new Contact("id", null, "B", "0123456789", "addr"));

        assertThrows(IllegalArgumentException.class,
                () -> new Contact("id", "ABCDEFGHIJK", "B", "0123456789", "addr")); // 11 characters in firstName
    }

    //last name rules
    @Test
    void lastName_required_andMax10() {
        assertThrows(IllegalArgumentException.class,
                () -> new Contact("id", "A", null, "0123456789", "addr"));

        assertThrows(IllegalArgumentException.class,
                () -> new Contact("id", "A", "ABCDEFGHIJK", "0123456789", "addr")); // 11 characters in lastName
    }

    //phone rules
    @Test
    void phone_required_exactly10Digits() {
        assertThrows(IllegalArgumentException.class,
                () -> new Contact("id", "A", "Z", null, "addr"));

        assertThrows(IllegalArgumentException.class,
                () -> new Contact("id", "A", "Z", "123456789", "addr"));   // 9 digits

        assertThrows(IllegalArgumentException.class,
                () -> new Contact("id", "A", "Z", "12345678901", "addr")); // 11 digits

        assertThrows(IllegalArgumentException.class,
                () -> new Contact("id", "A", "Z", "1a2b3c4d5e", "addr"));  // non-digits in the phone number
    }

    //address rules
    @Test
    void address_required_andMax30() {
        assertThrows(IllegalArgumentException.class,
                () -> new Contact("id", "A", "Z", "0123456789", null));

        assertThrows(IllegalArgumentException.class,
                () -> new Contact("id", "A", "Z", "0123456789",
                        "1234567890123456789012345678901")); // 31
    }

    // make sure hte setters enforce validation
    @Test
    void setters_enforceValidation_andAllowValidUpdates() {
        Contact c = new Contact("id", "A", "B", "0123456789", "addr");

        //bad updates
        assertThrows(IllegalArgumentException.class, () -> c.setFirstName(null));
        assertThrows(IllegalArgumentException.class, () -> c.setLastName("ABCDEFGHIJK")); // 11 characters
        assertThrows(IllegalArgumentException.class, () -> c.setPhone("notdigits"));
        assertThrows(IllegalArgumentException.class, () -> c.setAddress("x".repeat(31)));

        //good, valid updates
        c.setFirstName("Chris");
        c.setLastName("Koepp");
        c.setPhone("8318675309");
        c.setAddress("111 Sparrow point lane");

        assertAll(
                () -> assertEquals("Chris", c.getFirstName()),
                () -> assertEquals("Koepp", c.getLastName()),
                () -> assertEquals("8318675309", c.getPhone()),
                () -> assertEquals("111 Sparrow point lane", c.getAddress())
        );
    }

    //check the limits
    @Test
    void boundaryValues_passAtLimits_failPastLimits() {
        String ten = "ABCDEFGHIJ";           //10 character variable because i'm too lazy to retype it
        String thirty = "123456789012345678901234567890"; //30 character variable because i'm too lazy to retype it

        Contact c = new Contact("1234567890", ten, ten, "0123456789", thirty);
        assertEquals(ten, c.getFirstName());
        assertEquals(ten, c.getLastName());
        assertEquals("0123456789", c.getPhone());
        assertEquals(thirty, c.getAddress());

        assertThrows(IllegalArgumentException.class,
                () -> new Contact("12345678901", ten, ten, "0123456789", thirty)); //id 11 characters
        assertThrows(IllegalArgumentException.class,
                () -> new Contact("dude", ten + "Z", ten, "0123456789", thirty));    //firstName is 11 characters
        assertThrows(IllegalArgumentException.class,
                () -> new Contact("dudette", ten, ten + "X", "0123456789", thirty));    //lastName is 11 characters
        assertThrows(IllegalArgumentException.class,
                () -> new Contact("bro", ten, ten, "01234567890", thirty));         //phone is 11 characters
        assertThrows(IllegalArgumentException.class,
                () -> new Contact("sis", ten, ten, "0123456789", thirty + "Z"));    //address is 31 characters
    }
}