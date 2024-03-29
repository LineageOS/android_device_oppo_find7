/*
   Copyright (c) 2014, The CyanogenMod Project
   Copyright (c) 2018-2020, The LineageOS Project

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <android-base/file.h>
#include <android-base/strings.h>

#include "DeviceLibinit.h"
#include "init_msm8974.h"
#include "vendor_init.h"

using android::base::ReadFileToString;
using android::base::Split;

void import_kernel_cmdline(const std::function<void(const std::string&, const std::string&)>& fn) {
    std::string cmdline;
    android::base::ReadFileToString("/proc/cmdline", &cmdline);

    for (const auto& entry : android::base::Split(android::base::Trim(cmdline), " ")) {
        std::vector<std::string> pieces = android::base::Split(entry, "=");
        if (pieces.size() == 2) {
            fn(pieces[0], pieces[1]);
        }
    }
}

static void import_kernel_nv(const std::string& key, const std::string& value)
{
    if (key.empty()) return;

    if (key == "oppo.pcb_version") {
        if (value == "20" || value == "21" ||
                value == "22" || value == "23") {
            property_set("ro.oppo.device", "find7s");
            property_set("ro.power_profile.override", "power_profile_find7s");
            property_set("ro.sf.lcd_density", "640");
        } else {
            property_set("ro.oppo.device", "find7");
            property_set("ro.power_profile.override", "power_profile_find7");
            property_set("ro.sf.lcd_density", "480");
        }
    }

    if (key == "oppo.rf_version") {
        property_override("ro.oppo.rf_version", value.c_str());
    } else if (key == "oppo.pcb_version") {
        property_override("ro.oppo.pcb_version", value.c_str());
    }
}

void vendor_load_device_properties()
{
    import_kernel_cmdline(import_kernel_nv);
}
