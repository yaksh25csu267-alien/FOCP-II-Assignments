#include <iostream>
#include <vector>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
#include <string>    // For string operations

int main() {
    std::string name;

    // Ask the user to enter their name
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    // Store roast messages in a vector
    // Each message contains a placeholder {name}
    std::vector<std::string> roasts = {
        "{name}, even Google can't find your talent.",
        "{name}, you bring everyone so much joy... when you leave.",
        "{name}, your brain has more lag than slow internet.",
        "{name}, you're not useless, you can be used as a bad example.",
        "{name}, you have something on your chin... no, the third one down.",
        "{name}, your secrets are always safe with me. I never even listen.",
        "{name}, you're like a cloud. When you disappear, it's a beautiful day.",
        "{name}, you have the personality of unseasoned food.",
        "{name}, even a mirror avoids reflecting your attitude.",
        "{name}, if laziness were a sport, you'd come second… because you're too lazy to win."
    };

    // Initialize random seed using current time
    // This ensures different output each time the program runs
    std::srand(std::time(0));

    // Generate a random index based on the size of the vector
    int index = std::rand() % roasts.size();

    // Select a random roast message
    std::string selectedRoast = roasts[index];

    // Find the position of "{name}" in the selected roast
    std::size_t pos = selectedRoast.find("{name}");

    // If the placeholder is found, replace it with the actual name
    if (pos != std::string::npos) {
        selectedRoast.replace(pos, 6, name); // 6 is length of "{name}"
    }

    // Display the final roast message
    std::cout << "\n🔥 Roast: " << selectedRoast << std::endl;

    return 0;
}    
