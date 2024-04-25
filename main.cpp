#include <iostream>
#include "Smartphone.h"

std::string stringInputWithLabel(const std::string &label) {
    std::string result;
    std::cout << "Text " << label << ": ";
    std::getline(std::cin, result);
    return result;
}

int intInputWithLabel(const std::string &label) {
    std::string value;
    do {
        std::cout << "Text " << label << ": ";
        std::getline(std::cin, value);
        try {
            int iValue = std::stoi(value);
            return iValue;
        } catch (...) {
            std::cout << "Invalid number entered! Try again\n";
            std::cin.clear();
        }

    } while (true);
}

Smartphone setup() {
    Smartphone smartphone;
    while (true) {
        std::cout << "Setup smartphone" << std::endl;
        try {
            smartphone.setVendor(stringInputWithLabel("vendor"));
            smartphone.setModel(stringInputWithLabel("model"));
            smartphone.setOSName(stringInputWithLabel("OS name"));
            smartphone.setCpuCoresCount(intInputWithLabel("CPU cores count"));
            smartphone.setCpuFrequency(intInputWithLabel("CPU frequency (in HZ)"));
            smartphone.setRamSize(intInputWithLabel("RAM size (in bytes)"));
            smartphone.setRamType(stringInputWithLabel("RAM type"));
            smartphone.setRomSize(intInputWithLabel("ROM size (in bytes)"));
            smartphone.setImei(stringInputWithLabel("IMEI"));
            smartphone.validate();
            return smartphone;
        } catch (std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
            std::cout << "Error during setup, restart..." << std::endl << std::endl;
        }
    }
}

void installApplications(Smartphone &smartphone) {
    while (true) {
        try {
            std::cout << "— Installing applications —" << std::endl;
            smartphone.installApplications(intInputWithLabel("Count"), intInputWithLabel("size"));
            break;
        }
        catch (std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
            std::cout << "Error during installing, restart..." << std::endl;
        }
    }
}

void changeOS(Smartphone &smartphone) {
    while (true) {
        try {
            std::cout << "— Change OS —" << std::endl;
            smartphone.setOSName(stringInputWithLabel("OS name"));
            break;
        }
        catch (std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
            std::cout << "Error during installing, restart..." << std::endl;
        }
    }
}

int main() {
    Smartphone smartphone = setup();
    smartphone.log(std::cout);
    changeOS(smartphone);
    smartphone.log(std::cout);
    installApplications(smartphone);
    smartphone.log(std::cout);
    installApplications(smartphone);
    smartphone.log(std::cout);
    std::cout << "Hard reset" << std::endl;
    smartphone.hardReset();
    smartphone.log(std::cout);
    installApplications(smartphone);
    smartphone.log(std::cout);
    return 0;
}
