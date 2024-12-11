#@TYPE: Machine
#@NAME: meson

#@DESCRIPTION: Machine configuration for meson systems

include conf/machine/include/amlogic_weston.inc
include conf/machine/include/amlogic_aiot_common.inc

require conf/machine/include/amlogic_dvalin.inc

MACHINE_EXTRA_RRECOMMENDS += " \
        gpu \
        wififw-ap6256 \
        ap6xxx \
        aucpu-fw \
        coreutils \
        "

RDEPENDS:packagegroup-amlogic-baserootfs:append = " khadas-custom"
RDEPENDS:packagegroup-amlogic-baserootfs:append = " brcm-patchram-plus "

BOARD_NAME = "vim1s"
CHIPSET_NAME = "S905Y4"
KERNEL_DEVICETREE = "s4_kvim1s.dtb"
UBOOT_MACHINE = "s4_kvim1s_config"
KERNEL_MODULE_AUTOLOAD += " dhd"
KERNEL_MODULE_PROBECONF += "dhd"
module_conf_dhd = "options dhd firmware_path=../../etc/wifi/6256/ nvram_path=../../etc/wifi/6256/nvram_ap6256.txt"
KERNEL_MODULE_AUTOLOAD += " snd-soc-dummy_codec"
KERNEL_MODULE_AUTOLOAD += " snd-soc-aml_t9015"
KERNEL_MODULE_AUTOLOAD += "aml_aucpu"
KERNEL_MODULE_AUTOLOAD += " media_sync"

DISTRO_FEATURES:append = " gpt-partition"
DISTRO_FEATURES:append = " kernel_515"

OVERRIDES .= ":ap222:s4:onepass"
MACHINEOVERRIDES .= ":client"

DISTRO_FEATURES:append = " bt-bcm"
EXTRA_BLUETOOTH_STUFF := "${@bb.utils.contains('DISTRO_FEATURES', 'bluetooth', bb.utils.contains('DISTRO_FEATURES', 'bluez5', ' bluez5', ' bluez4', d), '', d)}"
EXTRA_BLUETOOTH_STUFF += " bluez-alsa"
DISTRO_FEATURES:append = "${EXTRA_BLUETOOTH_STUFF}"

DISTRO_FEATURES:append = " wififw "
