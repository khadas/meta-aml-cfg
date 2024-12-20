#@TYPE: Machine
#@NAME: meson

#@DESCRIPTION: Machine configuration for meson systems

include conf/machine/include/amlogic_weston.inc
include conf/machine/include/amlogic_aiot_common.inc
include conf/machine/include/amlogic_aiot_nndemo.inc
include conf/machine/include/amlogic_enc_common.inc

require conf/machine/include/amlogic_dvalin.inc

MACHINE_EXTRA_RRECOMMENDS += " \
        gpu \
        wififw-ap6398 \
        ap6xxx \
        npu \
        coreutils \
        "

RDEPENDS:packagegroup-amlogic-baserootfs:append = " npu-common"

BOARD_NAME = "vim3l"
CHIPSET_NAME = "S905D3"
KERNEL_DEVICETREE = "sm1_kvim3l.dtb"
UBOOT_MACHINE = " kvim3l_config"
KERNEL_MODULE_AUTOLOAD += " dhd"
KERNEL_MODULE_PROBECONF += "dhd"
module_conf_dhd = "options dhd firmware_path=../../etc/wifi/6398/ nvram_path=../../etc/wifi/6398/"
KERNEL_MODULE_AUTOLOAD += " snd-soc-dummy_codec"
KERNEL_MODULE_AUTOLOAD += " snd-soc-aml_t9015"
KERNEL_MODULE_AUTOLOAD += " snd-soc-tas5707"
KERNEL_MODULE_AUTOLOAD += " snd-soc-aml_codec_tl1_acodec"

DISTRO_FEATURES:append = " aml-libjpeg"
DISTRO_FEATURES:append = " aml-libamvenc-264"
DISTRO_FEATURES:append = " aml-libamvenc-265"
DISTRO_FEATURES:append = " aml-libamvenc"
DISTRO_FEATURES:append = " softap"

DISTRO_FEATURES:append = " mediactrlsrc-hdmi"

OVERRIDES .= ":ac200:sm1:onepass"
MACHINEOVERRIDES .= ":client"

DISTRO_FEATURES:append = " bt-bcm"
EXTRA_BLUETOOTH_STUFF := "${@bb.utils.contains('DISTRO_FEATURES', 'bluetooth', bb.utils.contains('DISTRO_FEATURES', 'bluez5', ' bluez5', ' bluez4', d), '', d)}"
EXTRA_BLUETOOTH_STUFF += " bluez-alsa"
EXTRA_BLUETOOTH_STUFF += " brcm-patchram-plus"
DISTRO_FEATURES:append = "${EXTRA_BLUETOOTH_STUFF}"

