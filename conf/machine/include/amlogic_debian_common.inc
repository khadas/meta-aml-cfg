#@TYPE: Machine
#@NAME: meson

#@DESCRIPTION: Machine configuration for meson debian OS systems

DISTRO_FEATURES:append = " amlbian"
DISTRO_FEATURES:append = " nfs-boot"

# clear linux version extension information, keep original
LINUX_VERSION_EXTENSION ?= ""

#for debian, needn't build uboot in yocto, will be build in amlbian,
EXTRA_IMAGEDEPENDS:remove = "u-boot"
DISTRO_FEATURES:remove = "u-boot"
