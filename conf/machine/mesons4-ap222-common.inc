#@TYPE: Machine
#@NAME: meson

#@DESCRIPTION: Machine configuration for meson systems

include conf/machine/include/amlogic_weston.inc
include conf/machine/include/amlogic_aiot_common.inc

require conf/machine/include/amlogic_dvalin.inc

MACHINE_EXTRA_RRECOMMENDS += " \
        gpu \
        wififw-qca6174 \
        qca6174 \
        aucpu-fw \
        coreutils \
        "

CHIPSET_NAME = "S905Y4"
KERNEL_DEVICETREE = "s4_s905y4_ap222_linux.dtb"
UBOOT_MACHINE = "s4_ap222_config"
KERNEL_MODULE_AUTOLOAD += " btqca"
KERNEL_MODULE_PROBECONF += "btqca"
KERNEL_MODULE_AUTOLOAD += " snd-soc-dummy_codec"
KERNEL_MODULE_AUTOLOAD += " snd-soc-aml_t9015"
KERNEL_MODULE_AUTOLOAD += "aml_aucpu"
KERNEL_MODULE_AUTOLOAD += " media_sync"

DISTRO_FEATURES:append = " gpt-partition"
DISTRO_FEATURES:append = " kernel_515"

OVERRIDES .= ":ap222:s4:onepass"
MACHINEOVERRIDES .= ":client"

DISTRO_FEATURES:append = " bt-qca"
EXTRA_BLUETOOTH_STUFF := "${@bb.utils.contains('DISTRO_FEATURES', 'bluetooth', bb.utils.contains('DISTRO_FEATURES', 'bluez5', ' bluez5', ' bluez4', d), '', d)}"
EXTRA_BLUETOOTH_STUFF += " bluez-alsa"
DISTRO_FEATURES:append = "${EXTRA_BLUETOOTH_STUFF}"

