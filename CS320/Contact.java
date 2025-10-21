package org.example;

import java.util.Objects;

public class Contact {
    private final String contactId;
    private String firstName;
    private String lastName;
    private String phone;
    private String address;

    public Contact(String contactId, String firstName, String lastName, String phone, String address) {
        this.contactId = validateId(contactId);
        this.firstName = validateName("firstName", firstName);
        this.lastName = validateName("lastName", lastName);
        this.phone = validatePhone(phone);
        this.address = validateAddress(address);
    }

    public String getContactId() { return contactId; }
    public String getFirstName() { return firstName; }
    public String getLastName() { return lastName; }
    public String getPhone() { return phone; }
    public String getAddress() { return address; }

    public void setFirstName(String firstName) {
        this.firstName = validateName("firstName", firstName);
    }

    public void setLastName(String lastName) {
        this.lastName = validateName("lastName", lastName);
    }

    public void setPhone(String phone) {
        this.phone = validatePhone(phone);
    }

    public void setAddress(String address) {
        this.address = validateAddress(address);
    }

    private static String validateId(String contactId) {
        if (contactId == null) throw new IllegalArgumentException("Contact ID is null, please provide a valid contact ID");
        if (contactId.length() >  10) throw new IllegalArgumentException("Contact ID is too long, maximum length is 10 characters");
        return contactId;
    }

    private static String validateName(String field, String value) {
        if (value == null) throw new IllegalArgumentException(field +" is null, please provide a valid contact name");
        if (value.length() > 10) throw new IllegalArgumentException(field +" is too long, maximum length is 10 characters");
        return value;
    }

    private static String validatePhone(String phone) {
        if (phone == null) throw new IllegalArgumentException("Phone is null, please provide a valid phone number");
        if (phone.length() !=10 || !phone.chars().allMatch(Character::isDigit)) throw new IllegalArgumentException("Phone number must be 10 digits");
        return phone;
    }

    private static String validateAddress(String address) {
        if (address == null) throw new IllegalArgumentException("Address is null, please provide a valid address");
        if (address.length() > 30) throw new IllegalArgumentException("Address is too long, maximum length is 30 characters");
        return address;
    }
}

