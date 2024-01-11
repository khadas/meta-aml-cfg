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

MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS += " \
        wififw-qca6174 \
        qca6174 \
        tuner-prebuilt \
        aucpu-fw \
        gpu \
        coreutils \
        "

CHIPSET_NAME = "S905X4"
PREFERRED_VERSION:qca6174 = "5.15"
RDEPENDS:packagegroup-amlogic-baserootfs:remove = "aml-subtitleserver"
RDEPENDS:packagegroup-amlogic-baserootfs:remove = " gst-aml-drm-plugins"
RDEPENDS:packagegroup-amlogic-baserootfs:remove = " fuse-exfat"
KERNEL_DEVICETREE = "sc2_s905x4_ah212_linux.dtb"
UBOOT_MACHINE = "sc2_ah212_config"
KERNEL_MODULE_AUTOLOAD += " cxd2856_fe_64"
KERNEL_MODULE_AUTOLOAD += " snd-soc-dummy_codec"
KERNEL_MODULE_AUTOLOAD += " snd-soc-aml_t9015"
KERNEL_MODULE_AUTOLOAD += " meson_ir"
KERNEL_MODULE_AUTOLOAD += " btqca"
KERNEL_MODULE_PROBECONF += "btqca"
KERNEL_MODULE_AUTOLOAD += " hci_uart"
KERNEL_MODULE_PROBECONF += "hci_uart"
KERNEL_MODULE_AUTOLOAD += "aml_aucpu"
KERNEL_MODULE_AUTOLOAD += "dolby_fw"
KERNEL_MODULE_AUTOLOAD += "meson-cpufreq"

DISTRO_FEATURES:append = " drm"
DISTRO_FEATURES:append = " gpt-partition"
DISTRO_FEATURES:append = " kernel_515"

DISTRO_FEATURES:append = " secure-u-boot optee "

DISTRO_FEATURES:append = " alsa "
DISTRO_FEATURES:append = " pam"
DISTRO_FEATURES_BACKFILL_CONSIDERED = "sysvinit"
DEFAULT_DISTRO_FEATURES += " systemd"
DISTRO_FEATURES:append = " systemd"
DISTRO_FEATURES:remove = " sysvinit"
DISTRO_FEATURES:append = " gstreamer1"
DISTRO_FEATURES:append = " aml-dtv "
DISTRO_FEATURES:append = " recovery "
DISTRO_FEATURES:append = " swupdate "
DISTRO_FEATURES:append = " aml-libjpeg "
DISTRO_FEATURES:append = " aml-libamvenc-264"
DISTRO_FEATURES:append = " aml-libamvenc-265"
DISTRO_FEATURES:append = " aml-libamvenc"
DISTRO_FEATURES:append = " gst-plugin-venc "
DISTRO_FEATURES:append = " mediactrlsrc"

OVERRIDES .= ":ah212:sc2:onepass"
MACHINEOVERRIDES .= ":client"

DISTRO_FEATURES:append = " bt-qca"
DISTRO_FEATURES:append = " bluetooth bluez5 "
EXTRA_BLUETOOTH_STUFF := "${@bb.utils.contains('DISTRO_FEATURES', 'bluetooth', bb.utils.contains('DISTRO_FEATURES', 'bluez5', ' bluez5', ' bluez4', d), '', d)}"
EXTRA_BLUETOOTH_STUFF += " bluez-alsa"
DISTRO_FEATURES:append = "${EXTRA_BLUETOOTH_STUFF}"

