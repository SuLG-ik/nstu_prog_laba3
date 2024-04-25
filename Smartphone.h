//
// Created by Володя on 18.04.2024.
//

#pragma once

#include <iostream>

#define OS_NAME_NONE "NONE"

class Smartphone {
public:
    ~Smartphone();

    Smartphone();

    Smartphone(const std::string &imei, const std::string &ramType, const std::string &model, const std::string &vendor,
               int cpuFrequency, int cpuCoresCount, int ramSize, int romSize);

    std::string &getVendor();

    std::string &getModel();

    std::string &getRamType();

    std::string &getImei();

    std::string &getOsName();

    int getCpuFrequency();

    int getCpuCoresCount();

    int getRamSize();

    int getRomSize();

    int getInstalledApplicationsCount();

    int getRomInUseSize();

    void installApplications(int count, int usageSize);

    void hardReset();

    void setOSName(std::string osName);

    /**
     * Calculate average count of applications available for install
     * @return average count of applications available for install
     */
    int getAvailableApplicationsCountForInstall();

private:
    std::string vendor, model, ramType, imei, osName = OS_NAME_NONE;
    int cpuFrequency = 0, cpuCoresCount = 0, ramSize = 0, romSize = 0, installedApplicationsCount = 0, romInUsageSize = 0;
    bool isInitialized = false;

    void set(const std::string &imei, const std::string &ramType, const std::string &model, const std::string &vendor,
             int cpuFrequency, int cpuCoresCount, int ramSize, int romSize);

public:
    void setVendor(const std::string &vendor);

    void setModel(const std::string &model);

    void setRamType(const std::string &ramType);

    void setImei(const std::string &imei);

    void setCpuFrequency(int cpuFrequency);

    void setCpuCoresCount(int cpuCoresCount);

    void setRamSize(int ramSize);

    void setRomSize(int romSize);

    void log(std::ostream &stream);

    /**
     * Validate all fields and set @Smartphone as initialized
     */
    void validate();
};
