#
# Copyright (C) 2014 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# Inherit from msm8974-common
-include device/oppo/msm8974-common/BoardConfigCommon.mk

# Kernel
BOARD_KERNEL_CMDLINE := console=ttyHSL0,115200,n8 androidboot.hardware=qcom user_debug=31 msm_rtb.filter=0x3F ehci-hcd.park=3
TARGET_KERNEL_CONFIG := lineageos_find7_defconfig
TARGET_KERNEL_SOURCE := kernel/oppo/msm8974

# Assert
TARGET_OTA_ASSERT_DEVICE := find7,find7a,find7s,FIND7,X9006,X9007,X9076,X9077

# Audio
AUDIO_FEATURE_LOW_LATENCY_PRIMARY := true
USE_XML_AUDIO_POLICY_CONF := 1

# Bluetooth
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := device/oppo/find7/bluetooth

# Camera
USE_DEVICE_SPECIFIC_CAMERA := true

# Display
TARGET_MSM8974_1440P_EGL_WORKAROUND := true

# Filesystem
BOARD_BOOTIMAGE_PARTITION_SIZE     := 16777216
BOARD_CACHEIMAGE_PARTITION_SIZE    := 536870912
BOARD_PERSISTIMAGE_PARTITION_SIZE  := 33554432
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 16777216
BOARD_SYSTEMIMAGE_PARTITION_SIZE   := 1073741824
BOARD_USERDATAIMAGE_PARTITION_SIZE := 13747929088 # 13747945472 - 16384 for crypto footer
#BOARD_USERDATAIMAGE_PARTITION_SIZE := 3221225472

# Init
TARGET_LIBINIT_MSM8974_DEFINES_FILE := device/oppo/find7/init/init_find7.cpp

# Properties
TARGET_SYSTEM_PROP += device/oppo/find7/system.prop

# Recovery
TARGET_RECOVERY_FSTAB := device/oppo/find7/rootdir/etc/fstab.recovery

# Shipping API
PRODUCT_SHIPPING_API_LEVEL := 18

# TWRP
ifeq ($(WITH_TWRP),true)
TARGET_RECOVERY_DEVICE_DIRS += device/oppo/find7/twrp
endif

# Inherit from the proprietary version
include vendor/oppo/find7/BoardConfigVendor.mk
