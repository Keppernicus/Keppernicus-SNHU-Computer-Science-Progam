### The Client
Throughout this term my client was Artemis Financial, a consulting company that creates individualized finance plans. 
They handle people's sensitive financial info and needed to make sure their web application was up to date with modern security protocols, especially for secure communicaiton to and from the customer.

### What I addressed with the software
As I worked I identified and fixed software vulnerabilities in part by adding a cryptographic has function and enforcing HTTPS using TLS. 
I added a checksum verification step that ensured secure certificate generation and handling, and I validated the refactored code with both static and functional tests. 
My goal was to provide a secure channel for client data to and from Artemis Financial, with mession integrity and confidentiality as a priority.

### What I did well
The integration of checksum verification using the SHA-256 went well. I made sure to use Java's standard cryptographic libraries instead of trying something custom,
There's no good reason to try and create my own version of something tried and true. I also verified my HTTPS config with a functional self signed cert and confirmed it worked for secure browser access.

### Why this matters
Secure, clean, disciplined coding practices are important for a good foundation. This helps protect the data involved with a project, avoid hangups and breaches that are expensive, and establishes and maintains trust with the customer.
These practices minimize the risk of attacks, leaving us with an appropriately hardened system against known threats.

### The Challenging parts
I ran into some issues with corruption on my self signed cert on creation, I spent some amount of time trying to understand why my password wasn't working until I realized that, 
then I just wiped the slate clean and got a fresh cert to make it work. There were also some issues with the dependency check plugin, namely version dependencies between the material and the current time. 
I learned how to adjust for these dependencies by editing the pom.xml to account for the differences.

### How I layered Security
I added HTTPS enforcement, used SHA-256 for checksums, and kept sensitive info from being revealed in the source code. In the future I may look into some more advanced tools like CVSS to help with prioitization, and research some more 
modern plugins for checking and mitigating dependency issues.

### How I verified things were secure
I reran the static analysis test with the OWASP dependency check once I was done refactoring, checked the results again, and tested the checksum output and HTTPS access. I tested the app again for functionality to ensure it ran without any logical flaws, once done I turned it in.

### What I'd show an employer.
This assignment demonstrates how I can practice secure design, HTTPS and TLS setup, checksum logic, static code analysis, and cert management. The final outcome shows that I know how to implement and validate security features in a Java environment.
