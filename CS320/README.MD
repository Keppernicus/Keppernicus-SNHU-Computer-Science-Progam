## CS 320 Portfolio Submission - Module Eight Journal

I've submitted four files for this course, Contact.java, ContactService.java, ContactTest.java, and ContactServiceTest.java.

These files come from Project one, where I demonstrated my ability to write clean, functional code with unit tests to validate logic.
I’ve also included my Project Two summary and reflection, where I explain the testing  used and how the code was aligned with customer requirements.

## Reflection

### How can I ensure that my code, program, or software is functional and secure?

I start by writing clear, specific unit tests with JUnit to check that each method behaves as expected, this included edge cases and invalid inputs. I also look at constraints (like string length or null checks) and enforce them with validation logic. For security, even though this project was simple and didn’t involve sensitive data or external input sources, I still made sure no method silently failed and that exceptions were properly thrown. In more complex applications, I’d layer on secure coding practices like input sanitization, error handling, and use tools like OWASP Dependency Check to prevent known vulnerabilities, as we did in CS305.


### How do I interpret user needs and incorporate them into a program?

I break down requirements into very literal rules in code. For example, if the spec says a contact ID can't be longer than 10 characters, I make a constructor level check that throws if violated. Then I write tests to prove that valid data works and invalid data doesn't. Thinking through user needs also means checking how data might be used downstream. I try to keep things modular, maintainable, and not just pass the tests but support reality.

### How do I approach designing software?

I usually start small. I build one class at a time to satisfy the core functionality, then wrap it in a service layer that manages creation, lookup, update, and deletion. I pair each class with a test file from the start to catch errors early and also gives me confidence when making changes. Once the basic objects are functional and tested, I start layering more logic and checking how everything connects. I also look for patterns in my code. If I repeat something across classes, I pull it into shared logic.

These files show my ability to write and test code based on given requirements, while also documenting and reflecting on my approach to quality, security, and maintainability.
