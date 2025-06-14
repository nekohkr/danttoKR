#include "serviceManager.h"

std::optional<std::reference_wrapper<Service>> ServiceManager::findServiceById(uint32_t serviceId) {
    for (auto& service : services) {
        if (service.serviceId == serviceId) {
            return service;
        }
    }
    return {};
}

std::optional<std::reference_wrapper<Service>> ServiceManager::findServiceByIp(uint32_t dstIp, uint16_t dstPort)
{
    for (auto& service : services) {
        if (service.slsDestinationIpAddress == dstIp &&
            service.slsDestinationUdpPort == dstPort) {
            return service;
        }
    }
    return {};
}

bool ServiceManager::AddService(const Service& service)
{
    // Check if service already exists
    auto it = std::find_if(services.begin(), services.end(),
        [&](const Service& s) { return s.serviceId == service.serviceId; });
    if (it != services.end()) {
        return false;
    }

    // Find the available index
    uint32_t i = 0;
    for (i = 0; i < 255; i++) {
        if (std::find_if(services.begin(), services.end(),
            [&](const Service& s) { return s.idx == i; }) == services.end()) {
            break;
        }
    }
    if (i >= 255) {
        return false;
    }

    Service serviceCopy = service;
    serviceCopy.idx = i;
    services.push_back(serviceCopy);
    return true;
}
