#pragma once

#include <stdint.h> // cstdint not available on Macs

// Get the time in seconds since epoch.
uint64_t CurrentTimeSeconds();
