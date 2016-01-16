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

DEVICE_PATH := device/oppo/find7

# Kernel
BOARD_KERNEL_CMDLINE := androidboot.hardware=qcom ehci-hcd.park=3
TARGET_KERNEL_CONFIG := lineageos_find7_defconfig
TARGET_KERNEL_SOURCE := kernel/oppo/msm8974

# Assert
TARGET_OTA_ASSERT_DEVICE := find7,find7a,find7s,FIND7,X9006,X9007,X9076,X9077

# Audio
AUDIO_FEATURE_LOW_LATENCY_PRIMARY := true
USE_XML_AUDIO_POLICY_CONF := 1

# Bluetooth
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := $(DEVICE_PATH)/bluetooth

# Display
TARGET_MSM8974_1440P_EGL_WORKAROUND := true

# Filesystem
BOARD_BOOTIMAGE_PARTITION_SIZE     := 16777216
BOARD_CACHEIMAGE_PARTITION_SIZE    := 536870912
BOARD_PERSISTIMAGE_PARTITION_SIZE  := 33554432
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 16777216
BOARD_ROOT_EXTRA_FOLDERS := firmware persist
BOARD_SYSTEMIMAGE_PARTITION_SIZE   := 1388314624
BOARD_USERDATAIMAGE_PARTITION_SIZE := 3221209088 # 3221225472-16384 for crypto footer

TARGET_FS_CONFIG_GEN := device/oppo/find7/config.fs

# Init
SOONG_CONFIG_OPPO_MSM8974_INIT_DEVICE_LIB := //$(DEVICE_PATH):libinit_find7

# Properties
TARGET_SYSTEM_PROP += $(DEVICE_PATH)/system.prop

# Recovery
TARGET_RECOVERY_FSTAB := $(DEVICE_PATH)/rootdir/etc/fstab.recovery

# TWRP
ifeq ($(WITH_TWRP),true)
TARGET_RECOVERY_DEVICE_DIRS += $(DEVICE_PATH)/twrp
endif

# Inherit from the proprietary version
include vendor/oppo/find7/BoardConfigVendor.mk
