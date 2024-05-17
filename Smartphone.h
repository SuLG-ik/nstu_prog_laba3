//
// Created by Володя on 18.04.2024.
//

#pragma once

#include <iostream>
#include <list>
#include "Application.h"

#define OS_NAME_NONE "NONE"

class Smartphone {
public:
    ~Smartphone();

    Smartphone();

    Smartphone(const std::string &imei, const std::string &ramType, const std::string &model, const std::string &vendor,
               int cpuFrequency, int cpuCoresCount, int ramSize, int romSize);

    std::string getVendor() const;

    std::string getModel() const;

    std::string getRamType() const;

    std::string getImei() const;

    std::string getOsName() const;

    int getCpuFrequency() const;

    int getCpuCoresCount() const;

    int getRamSize() const;

    int getRomSize() const;

    int getInstalledApplicationsCount() const;

    void installApplication(Application &application);

    int getRomInUseSize() const;

    void uninstallApplicationByPackageName(const std::string &packageName);

    bool isInstalled(Application &application);

    void hardReset();

    void setOSName(std::string osName);

    /**
     * Calculate average count of applications available for install
     * @return average count of applications available for install
     */
    int getAvailableApplicationsCountForInstall() const;

private:
    std::string vendor, model, ramType, imei, osName = OS_NAME_NONE;
    int cpuFrequency = 0, cpuCoresCount = 0, ramSize = 0, romSize = 0;
    bool isInitialized = false;
    std::list<Application> installedApplications;

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

    friend std::ostream &operator<<(std::ostream &os, const Smartphone &smartphone);

    /**
     * Validate all fields and set @Smartphone as initialized
     */
    void validate();
};
