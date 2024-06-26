//
// Created by Володя on 19.04.2024.
//

#include "Validator.h"
#include "Assert.h"

void validateVendor(const std::string &vendor) {
    assert_course_in(vendor.size(), 1, 30, "Vendor length");
}

void validateModel(const std::string &model) {
    assert_course_in(model.size(), 1, 30, "Model length");
}

void validateRamType(const std::string &ramType) {
    assert_not_empty(ramType, "RAM type");
}

void validateImei(const std::string &imei) {
    assert_number(imei, "IMEI");
    assert_course_in(imei.size(), 14, 15, "IMEI size");
}

void validateCpuFrequency(int cpuFrequency) {
    assert_greater_than_n(cpuFrequency, 0, "CPU frequency");
}

void validateCpuCoresCount(int cpuCoresCount) {
    assert_greater_than_n(cpuCoresCount, 0, "CPU cores count");
}

void validateRamSize(int ramSize) {
    assert_greater_than_n(ramSize, 0, "RAM size");
}

void validateRomSize(int romSize) {
    assert_greater_than_n(romSize, 0, "ROM size");
}

void validateOSName(std::string &osName) {
    assert_not_empty(osName, "OS name");
}

void validateApplicationName(std::string &value) {
    assert_not_empty(value, "Application name");
}

void validateApplicationPackageName(std::string &value) {
    assert_not_empty(value, "Package name");
}

void validateApplicationSize(int value) {
    assert_greater_than_n(value, 1, "Application size");
}

void validateInstalledApplications(int usageSize, int totalRomSize, int currentUsageSize) {
    assert_not_less_than_n(usageSize, 0, "Installed applications count");
    if (usageSize == 0)
        throw std::invalid_argument("Count and usageSize can be 0 only together");
    assert_not_greater_than_n(usageSize, totalRomSize - currentUsageSize, "Applications size");
}
