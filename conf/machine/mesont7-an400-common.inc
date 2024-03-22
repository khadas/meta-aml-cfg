#@TYPE: Machine
#@NAME: meson

#@DESCRIPTION: Machine configuration for meson systems

include conf/machine/include/amlogic_weston.inc
include conf/machine/include/amlogic_aiot_common.inc
include conf/machine/include/amlogic_aiot_nndemo.inc
include conf/machine/include/amlogic_enc_common.inc
include conf/machine/include/amlogic_nnstreamer.inc

PREFERRED_PROVIDER_virtual/mesa = "libgles-eabihf-gondul-wayland-drm"
PREFERRED_PROVIDER_virtual/mesa-gl = "libgles-eabihf-gondul-wayland-drm"
PREFERRED_PROVIDER_virtual/libgbm = "libgles-eabihf-gondul-wayland-drm"
PREFERRED_PROVIDER_virtual/egl = "libgles-eabihf-gondul-wayland-drm"
PREFERRED_PROVIDER_virtual/libgl = "libgles-eabihf-gondul-wayland-drm"
PREFERRED_PROVIDER_virtual/libgles1 = "libgles-eabihf-gondul-wayland-drm"
PREFERRED_PROVIDER_virtual/libgles2 = "libgles-eabihf-gondul-wayland-drm"

MACHINE_EXTRA_RRECOMMENDS += " \
        gpu \
        wififw-ap6398 \
        ap6xxx \
        adla-driver \
		coreutils \
        "

RDEPENDS:packagegroup-amlogic-baserootfs:append = " isp isp-dev"
RDEPENDS:packagegroup-amlogic-baserootfs:append = " cve libcve"
RDEPENDS:packagegroup-amlogic-baserootfs:append = " adla-lib"
RDEPENDS:packagegroup-amlogic-baserootfs:append = " npu-common"

PREFERRED_VERSION_isp = "5.15"
PREFERRED_VERSION_ap6xxx = "5.15"
CHIPSET_NAME = "A311D2"
KERNEL_DEVICETREE = "t7_a311d2_an400_linux.dtb t7c_a311d2_an400_linux.dtb"
UBOOT_MACHINE = "t7_an400_lpddr4x_config"
KERNEL_MODULE_AUTOLOAD += " dhd"
KERNEL_MODULE_PROBECONF += "dhd"
module_conf_dhd = "options dhd firmware_path=../../etc/wifi/6398/ nvram_path=../../etc/wifi/6398/"
KERNEL_MODULE_AUTOLOAD += " snd-soc-dummy_codec"
KERNEL_MODULE_AUTOLOAD += " snd-soc-aml_t9015"
KERNEL_MODULE_AUTOLOAD += " snd-soc-tas5707"
KERNEL_MODULE_AUTOLOAD += " snd-soc-aml_codec_tl1_acodec"

DISTRO_FEATURES:append = " aml-libjpeg"
DISTRO_FEATURES:append = " aml-libmultienc"
DISTRO_FEATURES:append = " aml-libamvenc"
DISTRO_FEATURES:append = " aml-isp arm-isp "
DISTRO_FEATURES:append = " amlogic-tv "
DISTRO_FEATURES:append = " softap"

DISTRO_FEATURES:append = " mediactrlsrc-cam"
DISTRO_FEATURES:append = " mediactrlsrc-hdmi"
OVERRIDES .= ":an400:t7:onepass"
MACHINEOVERRIDES .= ":client"

DISTRO_FEATURES:append = " bt-bcm"
EXTRA_BLUETOOTH_STUFF := "${@bb.utils.contains('DISTRO_FEATURES', 'bluetooth', bb.utils.contains('DISTRO_FEATURES', 'bluez5', ' bluez5', ' bluez4', d), '', d)}"
EXTRA_BLUETOOTH_STUFF += " bluez-alsa"
EXTRA_BLUETOOTH_STUFF += " brcm-patchram-plus"
DISTRO_FEATURES:append = "${EXTRA_BLUETOOTH_STUFF}"
