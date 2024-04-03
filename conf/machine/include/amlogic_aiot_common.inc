#@TYPE: Machine
#@NAME: meson

#@DESCRIPTION: Machine configuration for meson AIOT systems

CONNECTIVITY_CHECK_URIS = "https://www.yoctoproject.org/"


RDEPENDS:packagegroup-amlogic-baserootfs:remove = " aml-subtitleserver"
RDEPENDS:packagegroup-amlogic-baserootfs:remove = " gst-aml-drm-plugins"
RDEPENDS:packagegroup-amlogic-baserootfs:remove = " gst-agmplayer"
RDEPENDS:packagegroup-amlogic-baserootfs:remove = " fuse-exfat"

KERNEL_MODULE_AUTOLOAD += " meson_ir"
KERNEL_MODULE_AUTOLOAD += " hci_uart"
KERNEL_MODULE_PROBECONF += "hci_uart"
KERNEL_MODULE_AUTOLOAD += "meson-cpufreq"

DISTRO_FEATURES_BACKFILL_CONSIDERED = "sysvinit"
DEFAULT_DISTRO_FEATURES += " systemd"
DISTRO_FEATURES:append = " systemd"
DISTRO_FEATURES:remove = " sysvinit"
DISTRO_FEATURES:append = " gstreamer1"

DISTRO_FEATURES:append = " recovery"
DISTRO_FEATURES:append = " swupdate"

DISTRO_FEATURES:append = " aml-libgdc"
DISTRO_FEATURES:append = " secure-u-boot optee "
DISTRO_FEATURES:append = " alsa "
DISTRO_FEATURES:append = " pam"
#DISTRO_FEATURES:append = " aml-dtv "
DISTRO_FEATURES:append = " drm"

DISTRO_FEATURES:append = " gst-aml-gfx2d"
DISTRO_FEATURES:append = " dma-allocator"
DISTRO_FEATURES:append = " gst-aml-dma-allocator"
DISTRO_FEATURES:append = " gst-plugin-conv"
DISTRO_FEATURES:append = " aml-screencapture"
DISTRO_FEATURES:append = " aml-test"

DISTRO_FEATURES:append = " mediactrlsrc"
