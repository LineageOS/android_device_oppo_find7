/*
   Copyright (c) 2014, The CyanogenMod Project

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

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_msm8974.h"

static void set_xxhdpi_properties()
{
    // dalvik
    property_set("dalvik.vm.heapstartsize", "16m");
    property_set("dalvik.vm.heapgrowthlimit", "192m");
    property_set("dalvik.vm.heapsize", "512m");
    property_set("dalvik.vm.heaptargetutilization", "0.75");
    property_set("dalvik.vm.heapminfree", "2m");
    property_set("dalvik.vm.heapmaxfree", "8m");

    // hwui
    property_set("ro.hwui.texture_cache_size", "72");
    property_set("ro.hwui.layer_cache_size", "48");
    property_set("ro.hwui.r_buffer_cache_size", "8");
    property_set("ro.hwui.path_cache_size", "32");
    property_set("ro.hwui.gradient_cache_size", "1");
    property_set("ro.hwui.drop_shadow_cache_size", "6");
    property_set("ro.hwui.texture_cache_flushrate", "0.4");
    property_set("ro.hwui.text_small_cache_width", "1024");
    property_set("ro.hwui.text_small_cache_height", "1024");
    property_set("ro.hwui.text_large_cache_width", "2048");
    property_set("ro.hwui.text_large_cache_height", "1024");

    // density
    property_set("ro.sf.lcd_density", "480");
}

static void set_xxxhdpi_properties()
{
    // dalvik
    property_set("dalvik.vm.heapstartsize", "8m");
    property_set("dalvik.vm.heapgrowthlimit", "288m");
    property_set("dalvik.vm.heapsize", "768m");
    property_set("dalvik.vm.heaptargetutilization", "0.75");
    property_set("dalvik.vm.heapminfree", "2m");
    property_set("dalvik.vm.heapmaxfree", "8m");

    // hwui
    property_set("ro.hwui.texture_cache_size", "88");
    property_set("ro.hwui.layer_cache_size", "58");
    property_set("ro.hwui.r_buffer_cache_size", "8");
    property_set("ro.hwui.path_cache_size", "32");
    property_set("ro.hwui.gradient_cache_size", "2");
    property_set("ro.hwui.drop_shadow_cache_size", "8");
    property_set("ro.hwui.shape_cache_size", "4");
    property_set("ro.hwui.text_small_cache_width", "2048");
    property_set("ro.hwui.text_small_cache_height", "2048");
    property_set("ro.hwui.text_large_cache_width", "4096");
    property_set("ro.hwui.text_large_cache_height", "4096");

    // density
    property_set("ro.sf.lcd_density", "640");
}

static void import_kernel_nv(const std::string& key,
        const std::string& value, bool for_emulator __attribute__((unused)))
{
    if (key.empty()) return;

    if (key == "oppo.pcb_version") {
        if (value == "20" || value == "21" ||
                value == "22" || value == "23") {
            property_set("ro.oppo.device", "find7s");
            property_set("ro.power_profile.override", "find7s");
            set_xxxhdpi_properties();
        } else {
            property_set("ro.oppo.device", "find7");
            property_set("ro.power_profile.override", "find7");
            set_xxhdpi_properties();
        }
    }

    if (key == "oppo.rf_version") {
        property_set("ro.oppo.rf_version", value.c_str());
    } else if (key == "oppo.pcb_version") {
        property_set("ro.oppo.pcb_version", value.c_str());
    }
}

void init_target_properties()
{
    import_kernel_cmdline(0, import_kernel_nv);
}
