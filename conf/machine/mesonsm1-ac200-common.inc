#@TYPE: Machine
#@NAME: meson

#@DESCRIPTION: Machine configuration for meson systems

include conf/machine/include/amlogic_weston.inc
include conf/machine/include/amlogic_aiot_common.inc
include conf/machine/include/amlogic_aiot_nndemo.inc
include conf/machine/include/amlogic_enc_common.inc

PREFERRED_PROVIDER_virtual/mesa = "libgles-eabihf-dvalin-wayland-drm"
PREFERRED_PROVIDER_virtual/mesa-gl = "libgles-eabihf-dvalin-wayland-drm"
PREFERRED_PROVIDER_virtual/libgbm = "libgles-eabihf-dvalin-wayland-drm"
PREFERRED_PROVIDER_virtual/egl = "libgles-eabihf-dvalin-wayland-drm"
PREFERRED_PROVIDER_virtual/libgl = "libgles-eabihf-dvalin-wayland-drm"
PREFERRED_PROVIDER_virtual/libgles1 = "libgles-eabihf-dvalin-wayland-drm"
PREFERRED_PROVIDER_virtual/libgles2 = "libgles-eabihf-dvalin-wayland-drm"

MACHINE_EXTRA_RRECOMMENDS += " \
        gpu \
        wififw-ap6398 \
        ap6xxx \
        npu \
        coreutils \
        "

RDEPENDS:packagegroup-amlogic-baserootfs:remove = " aml-subtitleserver"
RDEPENDS:packagegroup-amlogic-baserootfs:remove = " gst-aml-drm-plugins"
RDEPENDS:packagegroup-amlogic-baserootfs:remove = " gst-agmplayer"
RDEPENDS:packagegroup-amlogic-baserootfs:remove = " fuse-exfat"
RDEPENDS:packagegroup-amlogic-baserootfs:append = " npu-common"

CHIPSET_NAME = "S905D3"
KERNEL_DEVICETREE = "sm1_s905d3_ac200_linux.dtb"
UBOOT_MACHINE = " sm1_ac200_v1_config"
KERNEL_MODULE_AUTOLOAD += " dhd"
KERNEL_MODULE_PROBECONF += "dhd"
module_conf_dhd = "options dhd firmware_path=../../etc/wifi/6398/ nvram_path=../../etc/wifi/6398/"
KERNEL_MODULE_AUTOLOAD += " snd-soc-dummy_codec"
KERNEL_MODULE_AUTOLOAD += " snd-soc-aml_t9015"
KERNEL_MODULE_AUTOLOAD += " snd-soc-tas5707"
KERNEL_MODULE_AUTOLOAD += " snd-soc-aml_codec_tl1_acodec"
KERNEL_MODULE_AUTOLOAD += " meson_ir"
KERNEL_MODULE_AUTOLOAD += " hci_uart"
KERNEL_MODULE_PROBECONF += "hci_uart"
KERNEL_MODULE_AUTOLOAD += "meson-cpufreq"

DISTRO_FEATURES:append = " drm"

DISTRO_FEATURES:append = " secure-u-boot optee "
DISTRO_FEATURES:append = " alsa "
DISTRO_FEATURES:append = " pam"
DISTRO_FEATURES_BACKFILL_CONSIDERED = "sysvinit"
DEFAULT_DISTRO_FEATURES += " systemd"
DISTRO_FEATURES:append = " systemd"
DISTRO_FEATURES:remove = " sysvinit"
DISTRO_FEATURES:append = " gstreamer1"
DISTRO_FEATURES:append = " aml-dtv "
DISTRO_FEATURES:append = " gst-plugin-venc"
DISTRO_FEATURES:append = " aml-libjpeg"
DISTRO_FEATURES:append = " aml-libamvenc-264"
DISTRO_FEATURES:append = " aml-libamvenc-265"
DISTRO_FEATURES:append = " aml-libamvenc"
DISTRO_FEATURES:append = " softap"
DISTRO_FEATURES:append = " aml-libgdc"
DISTRO_FEATURES:append = " swupdate"
DISTRO_FEATURES:append = " recovery"

DISTRO_FEATURES:append = " mediactrlsrc"

MACHINEOVERRIDES .= ":client"

DISTRO_FEATURES:append = " bt-bcm"
EXTRA_BLUETOOTH_STUFF := "${@bb.utils.contains('DISTRO_FEATURES', 'bluetooth', bb.utils.contains('DISTRO_FEATURES', 'bluez5', ' bluez5', ' bluez4', d), '', d)}"
EXTRA_BLUETOOTH_STUFF += " bluez-alsa"
EXTRA_BLUETOOTH_STUFF += " brcm-patchram-plus"
DISTRO_FEATURES:append = "${EXTRA_BLUETOOTH_STUFF}"

