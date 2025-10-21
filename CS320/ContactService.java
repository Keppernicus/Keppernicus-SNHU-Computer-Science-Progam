package org.example;

import java.util.Objects;
import java.util.HashMap;
import java.util.Map;
import java.util.NoSuchElementException;

public class ContactService {

    private final Map<String, Contact> contacts = new HashMap<>();

    // Create or add a contact with it's own unique id. Throw if it's null or a dupe.
    public void addContact(Contact contact) {
        Objects.requireNonNull(contact, "contact cannot be null");
        String id = contact.getContactId();
        if (contacts.containsKey(id)) {
            throw new IllegalArgumentException("Contact with id " + id + " already exists");
        }
        contacts.put(id, contact);
    }

    //User can delete by the contactId, returns true if successful
    public boolean deleteContact(String contactId) {
        return contacts.remove(contactId) != null;
    }

    // update the firstName
    public void updateFirstName(String contactId, String firstName) {
        getOrThrow(contactId).setFirstName(firstName);
    }

    // update lastName
    public void updateLastName(String contactId, String lastName) {
        getOrThrow(contactId).setLastName(lastName);
    }

    // update the phone number
    public void updatePhone(String contactId, String phone) {
        getOrThrow(contactId).setPhone(phone);
    }

    // update address
    public void updateAddress(String contactId, String address) {
        getOrThrow(contactId).setAddress(address);
    }

    // this is just for testing contactId
    public Contact getContact(String contactId) {
        return contacts.get(contactId);
    }

    // for me/the dev working on this
    private Contact getOrThrow(String contactId) {
        Contact c = contacts.get(contactId);
        if (c == null) throw new NoSuchElementException("No contact with id " + contactId);
        return c;
    }
 }
