## CS230 Software Design Document README

### Client & Software Requirements
- The Gaming Room wanted to take their mobile game Draw It or Lose It and make it work as a web application. It was only available on Android,
so they needed help making it cross platform and scalable. Creative Technology Solutions (CTS) was brought int ot design the environment,
since the client didn't have the expertise to manage multi platform deployment themselves.

### What I did well
- I believe I did well keeping the design clean and modular. Using Java with object-oriented design and patterns like the singleton and iterator
cut down on duplicate code and helped make it scalable and easy to maintain.

### The helpful parts of the process
- Working through this design doc made me look hard at the scalability, unique IDs, and security for the app from the get-go.
Having that laid out before the code development started made it easier to see how the pieces connect and where potential constraints are.

### What I'd revise 
- If I had to revise anything, I would revise the security. I would dig a bit more into how the identity management and monitoring for the role based
authentication, encryption, and SELinux would work in actual practice.

### Interpretation of Users' needs
- The customer passed along the users' needs in the requirements. There was unique names and IDs, support across multiple devices,
and scaling with downtime. I implemented those needs by having the Game, Team, and Play classes inherit from an abstracted class named Entity,
IDs were made unique withe GameService, and I accounted for load balancing and persistence so the system is reliable and consistent for each user.

### My Approach to software design
- I approached this with object oriented principles and patterns with a focus on scalability and modularity. I'd use the same approach again in the future,
but put a bit more emphasis on documentation for security related issues and distributed systems since those become more important the bigger the game
gets.
