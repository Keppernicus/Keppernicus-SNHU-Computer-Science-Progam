package org.example;

import org.junit.jupiter.api.Test;
import java.util.NoSuchElementException;
import static org.junit.jupiter.api.Assertions.*;

class ContactServiceTest {

    @Test
    void addContact_withUniqueId_succeeds() {
        ContactService svc = new ContactService();
        Contact c = new Contact("id1", "A", "Z", "0123456789", "addr");
        svc.addContact(c);

        //checking to see if we can fetch the same instance
        assertSame(c, svc.getContact("id1"));
    }

    @Test
    void addContact_duplicateId_throws() {
        ContactService svc = new ContactService();
        svc.addContact(new Contact("dupe", "A", "B", "0123456789", "addr"));

        assertThrows(IllegalArgumentException.class, () ->
                svc.addContact(new Contact("dupe", "X", "Y", "1112443333", "addr2")));
    }

    @Test
    void deleteContact_byId_returnsTrueWhenRemoved_falseWhenMissing() {
        ContactService svc = new ContactService();
        svc.addContact(new Contact("id2", "A", "B", "0123456789", "addr"));

        assertTrue(svc.deleteContact("id2"));   //alredy existed
        assertFalse(svc.deleteContact("id2"));  //already deleted
        assertNull(svc.getContact("id2"));
    }

    @Test
    void updateFields_byId_updatesEachField() {
        ContactService svc = new ContactService();
        svc.addContact(new Contact("id3", "A", "B", "0123456789", "addr"));

        svc.updateFirstName("id3", "Chris");
        svc.updateLastName("id3", "Koepp");
        svc.updatePhone("id3", "1112223333");
        svc.updateAddress("id3", "111 Sparrow pt");

        Contact c = svc.getContact("id3");
        assertAll(
                () -> assertEquals("Chris", c.getFirstName()),
                () -> assertEquals("Koepp", c.getLastName()),
                () -> assertEquals("1112223333", c.getPhone()),
                () -> assertEquals("111 Sparrow pt", c.getAddress())
        );
    }

    @Test
    void update_onMissingId_throwsNoSuchElement() {
        ContactService svc = new ContactService();

        assertThrows(NoSuchElementException.class, () -> svc.updateFirstName("nope", "X"));
        assertThrows(NoSuchElementException.class, () -> svc.updateLastName("nope", "Y"));
        assertThrows(NoSuchElementException.class, () -> svc.updatePhone("nope", "0123456789"));
        assertThrows(NoSuchElementException.class, () -> svc.updateAddress("nope", "addr"));
    }

    @Test
    void update_withInvalidValues_propagatesValidationErrors() {
        ContactService svc = new ContactService();
        svc.addContact(new Contact("id4", "A", "Z", "0123456789", "addr"));

        // invalid examples of each field
        assertThrows(IllegalArgumentException.class, () -> svc.updateFirstName("id4", null));
        assertThrows(IllegalArgumentException.class, () -> svc.updateLastName("id4", "ABCDEFGHIJK")); //11 characters
        assertThrows(IllegalArgumentException.class, () -> svc.updatePhone("id4", "notdigits"));      //non-digits
        assertThrows(IllegalArgumentException.class, () -> svc.updateAddress("id4", "x".repeat(31))); //31 characters
    }
}

