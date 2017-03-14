// Example usage for Amulet_Serial_Communication_Library library by Brian Deters.

#include "amulet_Serial_Communication_Library.h"

// Initialize objects from the lib
Amulet_Serial_Communication_Library amulet_Serial_Communication_Library;

void setup() {
    // Call functions on initialized library objects that require hardware
    amulet_Serial_Communication_Library.begin();
}

void loop() {
    // Use the library's initialized objects and functions
    amulet_Serial_Communication_Library.process();
}
