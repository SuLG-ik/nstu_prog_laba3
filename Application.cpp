//
// Created by Володя on 16.05.2024.
//

#include "Application.h"
#include "Validator.h"

bool Application::operator==(const Application &rhs) const {
    return packageName == rhs.packageName;
}

bool Application::operator!=(const Application &rhs) const {
    return !(rhs == *this);
}

Application::Application(const std::string &name, const std::string &packageName, int size) {
    set(name, packageName, size);
}

const std::string &Application::getName() const {
    return name;
}

const std::string &Application::getPackageName() const {
    return packageName;
}

int Application::getSize() const {
    return size;
}

void Application::set(const std::string &name, const std::string &packageName, int size) {
    Application::name = name;
    Application::packageName = packageName;
    Application::size = size;
}

std::ostream &operator<<(std::ostream &os, const Application &application) {
    os << "name: " << application.name << " packageName: " << application.packageName << " size: " << application.size;
    return os;
}

void Application::setName(std::string &name) {
    validateApplicationName(name);
    Application::name = name;
}

void Application::setPackageName(std::string &packageName) {
    validateApplicationPackageName(packageName);
    Application::packageName = packageName;
}

void Application::setSize(int size) {
    validateApplicationSize(size);
    Application::size = size;
}
