//
// Created by Володя on 18.04.2024.
//

#include "Smartphone.h"
#include "Validator.h"
#include "Assert.h"
#include <stdexcept>

std::string &Smartphone::getVendor() {
    return vendor;
}

std::string &Smartphone::getModel() {
    return model;
}

std::string &Smartphone::getRamType() {
    return ramType;
}

std::string &Smartphone::getImei() {
    return imei;
}

std::string &Smartphone::getOsName() {
    return osName;
}

int Smartphone::getCpuFrequency() {
    return cpuFrequency;
}

int Smartphone::getCpuCoresCount() {
    return cpuCoresCount;
}

int Smartphone::getRamSize() {
    return ramSize;
}

int Smartphone::getRomSize() {
    return romSize;
}

int Smartphone::getInstalledApplicationsCount() {
    return installedApplicationsCount;
}

int Smartphone::getRomInUseSize() {
    return romInUsageSize;
}

void Smartphone::installApplications(int count, int usageSize) {
    assert_true(isInitialized, "Initialized");
    validateInstalledApplications(count, usageSize, romSize, romInUsageSize);
    count = Smartphone::installedApplicationsCount + count;
    usageSize = Smartphone::romInUsageSize + usageSize;
    Smartphone::installedApplicationsCount = count;
    Smartphone::romInUsageSize = usageSize;
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
    setCpuCoresCount(cpuFrequency);
    setRamSize(ramSize);
    setRomSize(romSize);
}

void Smartphone::setOSName(std::string osName) {
    validateOSName(osName);
    Smartphone::osName = osName;
}

void Smartphone::log(std::ostream &stream) {
    stream << std::endl << "——— Smartphone info ———" << std::endl;
    stream << "valid: " << isInitialized << std::endl;
    stream << "IMEI: " << getImei() << std::endl;
    stream << "OS name: " << getOsName() << std::endl;
    stream << "Vendor: " << getVendor() << std::endl;
    stream << "Model: " << getModel() << std::endl;
    stream << "RAM size: " << getRamSize() << " byte" << std::endl;
    stream << "RAM type: " << getRamType() << std::endl;
    stream << "ROM size: " << getRomSize() << " byte" << std::endl;
    stream << "ROM in use size: " << getRomInUseSize() << " byte" << std::endl;
    stream << "CPU cores count: " << getCpuCoresCount() << std::endl;
    stream << "CPU frequency: " << getCpuFrequency() << " Hz" << std::endl;
    stream << "Installed applications count: " << getInstalledApplicationsCount() << std::endl;
    stream << "Available applications for install: "
           << (getAvailableApplicationsCountForInstall() == -1 ? "none" :
               std::to_string(getAvailableApplicationsCountForInstall()))
           << std::endl << std::endl;
}

Smartphone::~Smartphone() = default;

Smartphone::Smartphone() = default;

void Smartphone::hardReset() {
    Smartphone::romInUsageSize = 0;
    Smartphone::installedApplicationsCount = 0;
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

int Smartphone::getAvailableApplicationsCountForInstall() {
    if (installedApplicationsCount == 0) {
        return -1;
    }
    return (romSize - romInUsageSize) / (romInUsageSize / installedApplicationsCount);
}

