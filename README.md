Overview:
The PhotoGram application is designed to allow users to manage their photos in a simple and efficient manner. This version of the application includes a master list of photos that can be used to create albums. A photo can appear in more than one album and deleting an album will not delete the photos contained in them.

MediaFactory:
To simplify the creation of photos and albums, we have implemented a MediaFactory. This factory can create different types of media objects, such as photos and albums, and can handle disk access (e.g. downloading from an SD card or phone).

Search Functionality:
The application includes a simple search function for photos. The search function allows users to find photos based on certain criteria and add them to an album. We have implemented a Criteria class that encapsulates the search details and allows for the addition of future search criteria without changing the core algorithm.

Templated Collection Class:
We have also implemented a proper templated collection class to manage the photos and albums in the application. This collection class can handle different types of media objects and provides a flexible and efficient way to manage the data.

Memory Management:
To ensure that there are no memory leaks, we have made sure that photos are only deleted when the application exits.

Conclusion:
The PhotoGram application provides users with an efficient and user-friendly way to manage their photos. With the MediaFactory, search functionality, and templated collection class, the application is flexible and can handle different types of media objects. The memory management ensures that there are no memory leaks and the application is safe to use.
