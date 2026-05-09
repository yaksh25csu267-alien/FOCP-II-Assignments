#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()

// Function to replace {name} with actual student name
std::string replaceName(std::string excuse, std::string name) {
    size_t pos = excuse.find("{name}"); // find placeholder

    if (pos != std::string::npos) {
        excuse.replace(pos, 6, name); // replace "{name}" with actual name
    }

    return excuse;
}

int main() {
    std::string studentName;

    // Ask user for name
    std::cout << "Enter student name: ";
    std::getline(std::cin, studentName);

    // List of excuse templates
    std::vector<std::string> excuses = {
        "{name} could not finish homework because the laptop suddenly stopped working.",
        "{name} forgot the assignment at home due to a rush in the morning.",
        "{name} was helping a friend and forgot to complete the homework.",
        "{name}'s internet was not working last night.",
        "{name} had a power cut while working on the assignment.",
        "{name} accidentally deleted the homework file.",
        "{name} was not feeling well and could not complete the work.",
        "{name} thought the deadline was tomorrow.",
        "{name}'s pet messed up the homework.",
        "{name} was busy attending a family function."
    };

    // Seed random number generator
    srand(time(0));

    // Generate random index
    int randomIndex = rand() % excuses.size();

    // Pick random excuse
    std::string selectedExcuse = excuses[randomIndex];

    // Replace placeholder with actual name
    std::string finalExcuse = replaceName(selectedExcuse, studentName);

    // Display result
    std::cout << "\nExcuse:\n" << finalExcuse << std::endl;

    return 0;
}
