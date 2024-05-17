//
// Created by Володя on 16.05.2024.
//

#pragma once

#include <iostream>


class Application {
    std::string name, packageName;
    int size;
private:
    void set(const std::string &name, const std::string &packageName, int size);

public:
    void setName(std::string &name);

    void setPackageName(std::string &packageName);

    void setSize(int size);

public:
    friend std::ostream &operator<<(std::ostream &os, const Application &application);

    bool operator==(const Application &rhs) const;

    bool operator!=(const Application &rhs) const;

    const std::string &getName() const;

    const std::string &getPackageName() const;

    int getSize() const;

    Application(const std::string &name, const std::string &packageName, int size);
};