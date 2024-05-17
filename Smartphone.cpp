//
// Created by Володя on 18.04.2024.
//

#include "Smartphone.h"
#include "Validator.h"
#include "Assert.h"

std::string Smartphone::getVendor() const {
    return vendor;
}

std::string Smartphone::getModel() const {
    return model;
}

std::string Smartphone::getRamType() const {
    return ramType;
}

std::string Smartphone::getImei() const {
    return imei;
}

std::string Smartphone::getOsName() const {
    return osName;
}

int Smartphone::getCpuFrequency() const {
    return cpuFrequency;
}

int Smartphone::getCpuCoresCount() const {
    return cpuCoresCount;
}

int Smartphone::getRamSize() const {
    return ramSize;
}

int Smartphone::getRomSize() const {
    return romSize;
}

int Smartphone::getInstalledApplicationsCount() const {
    return installedApplications.size();
}

int Smartphone::getRomInUseSize() const {
    int sum = 0;
    for (const auto &item: installedApplications) {
        sum += item.getSize();
    }
    return sum;
}

void Smartphone::setVendor(const std::string &vendor) {
    validateVendor(vendor);
    Smartphone::vendor = vendor;
}

void Smartphone::setModel(const std::string &model) {
    validateModel(model);
    Smartphone::model = model;
}

void Smartphone::setRamType(const std::string &ramType) {
    validateRamType(ramType);
    Smartphone::ramType = ramType;
}

void Smartphone::setImei(const std::string &imei) {
    validateImei(imei);
    Smartphone::imei = imei;
}

void Smartphone::setCpuFrequency(int cpuFrequency) {
    validateCpuFrequency(cpuFrequency);
    Smartphone::cpuFrequency = cpuFrequency;
}

void Smartphone::setCpuCoresCount(int cpuCoresCount) {
    validateCpuCoresCount(cpuCoresCount);
    Smartphone::cpuCoresCount = cpuCoresCount;
}

void Smartphone::setRamSize(int ramSize) {
    validateRamSize(ramSize);
    Smartphone::ramSize = ramSize;
}

void Smartphone::setRomSize(int romSize) {
    validateRomSize(romSize);
    Smartphone::romSize = romSize;
}

Smartphone::Smartphone(const std::string &imei, const std::string &ramType, const std::string &model,
                       const std::string &vendor, int cpuFrequency, int cpuCoresCount, int ramSize, int romSize) {
    set(imei, ramType, model, vendor, cpuFrequency, cpuCoresCount, ramSize, romSize);
}

void Smartphone::set(const std::string &imei, const std::string &ramType, const std::string &model,
                     const std::string &vendor, int cpuFrequency, int cpuCoresCount, int ramSize, int romSize) {
    setImei(imei);
    setRamType(ramType);
    setModel(model);
    setVendor(vendor);
    setCpuFrequency(cpuFrequency);
    setCpuCoresCount(cpuCoresCount);
    setRamSize(ramSize);
    setRomSize(romSize);
}

void Smartphone::setOSName(std::string osName) {
    validateOSName(osName);
    Smartphone::osName = osName;
}

Smartphone::~Smartphone() = default;

Smartphone::Smartphone() = default;

void Smartphone::hardReset() {
    installedApplications.clear();
}

void Smartphone::validate() {
    validateVendor(vendor);
    validateModel(model);
    validateRamType(ramType);
    validateImei(imei);
    validateCpuFrequency(cpuFrequency);
    validateCpuCoresCount(cpuCoresCount);
    validateRamSize(ramSize);
    validateRomSize(romSize);
    isInitialized = true;
}

int Smartphone::getAvailableApplicationsCountForInstall() const {
    if (installedApplications.empty())
        return -1;
    int romInUseSize = getRomInUseSize();
    return (romSize - romInUseSize) / (romInUseSize / getInstalledApplicationsCount());
}

void Smartphone::installApplication(Application &application) {
    if (isInstalled(application)) {
        throw std::invalid_argument("Application already installed");
    }
    validateInstalledApplications(getRomInUseSize() + application.getSize(), getRomSize(), getRomInUseSize());
    installedApplications.push_back(application);
}

bool Smartphone::isInstalled(Application &application) {
    for (const auto &item: installedApplications) {
        if (application == item)
            return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const Smartphone &smartphone) {
    os << std::endl << "——— Smartphone info ———" << std::endl;
    os << "valid: " << smartphone.isInitialized << std::endl;
    os << "IMEI: " << smartphone.getImei() << std::endl;
    os << "OS name: " << smartphone.getOsName() << std::endl;
    os << "Vendor: " << smartphone.getVendor() << std::endl;
    os << "Model: " << smartphone.getModel() << std::endl;
    os << "RAM size: " << smartphone.getRamSize() << " byte" << std::endl;
    os << "RAM type: " << smartphone.getRamType() << std::endl;
    os << "ROM size: " << smartphone.getRomSize() << " byte" << std::endl;
    os << "ROM in use size: " << smartphone.getRomInUseSize() << " byte" << std::endl;
    os << "CPU cores count: " << smartphone.getCpuCoresCount() << std::endl;
    os << "CPU frequency: " << smartphone.getCpuFrequency() << " Hz" << std::endl;
    os << "Installed applications count: " << smartphone.getInstalledApplicationsCount() << std::endl;
    os << "Available applications for install: "
       << (smartphone.getAvailableApplicationsCountForInstall() == -1 ? "none" :
           std::to_string(smartphone.getAvailableApplicationsCountForInstall()))
       << std::endl << std::endl;
    os << "Installed applications list:" << std::endl;
    for (const auto &item: smartphone.installedApplications) {
        os << item << std::endl;
    }
    return os;
}

void Smartphone::uninstallApplicationByPackageName(const std::string &packageName) {
    installedApplications.remove_if([&](const auto &item) {
        return packageName == item.getPackageName();
    });
}
