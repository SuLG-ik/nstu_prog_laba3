//
// Created by Володя on 19.04.2024.
//

#include "Validator.h"
#include "Assert.h"

void validateVendor(const std::string &vendor) {
    assert_not_empty(vendor, "Vendor");
}

void validateModel(const std::string &model) {
    assert_not_empty(model, "Model");
}

void validateRamType(const std::string &ramType) {
    assert_not_empty(ramType, "RAM type");
}

void validateImei(const std::string &imei) {
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

void validateInstalledApplications(int count, int usageSize, int totalRomSize, int currentUsageSize) {
    assert_not_less_than_n(count, 0, "Installed applications count");
    assert_not_less_than_n(usageSize, 0, "Installed applications count");
    if ((count == 0 && usageSize != 0) || count != 0 && usageSize == 0)
        throw std::invalid_argument("Count and usageSize can be 0 only together");
    assert_not_greater_than_n(usageSize, totalRomSize - currentUsageSize, "Applications size");
}
