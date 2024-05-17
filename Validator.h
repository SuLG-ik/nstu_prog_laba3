//
// Created by Володя on 19.04.2024.
//

#pragma once

#include <iostream>

void validateVendor(const std::string &vendor);

void validateModel(const std::string &model);

void validateRamType(const std::string &ramType);

void validateImei(const std::string &imei);

void validateCpuFrequency(int cpuFrequency);

void validateCpuCoresCount(int cpuCoresCount);

void validateRamSize(int ramSize);

void validateRomSize(int romSize);

void validateOSName(std::string &osName);

void validateInstalledApplications(int usageSize, int totalRomSize, int currentUsageSize);

void validateApplicationName(std::string &value);

void validateApplicationPackageName(std::string &value);

void validateApplicationSize(int value);