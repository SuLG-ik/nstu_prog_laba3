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

bool inputIsContinue() {
    std::string input = stringInputWithLabel("Continue? (Y/n)");
    return input == "y" || input == "yes" || input == "Y" || input == "YES";
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

Application inputApplication() {
    std::string name = stringInputWithLabel("Application name");
    std::string packageName = stringInputWithLabel("Application package name (unique)");
    int size = intInputWithLabel("Applcation size");
    return Application(name, packageName, size);
}

void installApplications(Smartphone &smartphone) {
    while (true) {
        try {
            std::cout << "— Installing applications —" << std::endl;
            Application application = inputApplication();
            smartphone.installApplication(application);
            if (!inputIsContinue())
                return;
        }
        catch (std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
            std::cout << "Error during installing, restart..." << std::endl;
        }
    }
}

void uninstallApplications(Smartphone &smartphone) {
    std::cout << smartphone;
    while (true) {
        try {
            std::cout << "— Uninstalling applications —" << std::endl;
            std::string packageName = stringInputWithLabel("Application package name to install");
            smartphone.uninstallApplicationByPackageName(packageName);
            std::cout << smartphone;
            if (!inputIsContinue())
                return;
            else
                std::cout << smartphone;
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
    std::cout << smartphone;
    changeOS(smartphone);
    std::cout << smartphone;
    installApplications(smartphone);
    std::cout << smartphone;
    std::cout << "Hard reset" << std::endl;
    smartphone.hardReset();
    std::cout << smartphone;
    installApplications(smartphone);
    std::cout << smartphone;
    uninstallApplications(smartphone);
    return 0;
}