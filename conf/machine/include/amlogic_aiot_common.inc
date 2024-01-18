#@TYPE: Machine
#@NAME: meson

#@DESCRIPTION: Machine configuration for meson AIOT systems

DISTRO_FEATURES:append = " gst-aml-gfx2d"
DISTRO_FEATURES:append = " dma-allocator"
DISTRO_FEATURES:append = " gst-aml-dma-allocator"
DISTRO_FEATURES:append = " gst-plugin-conv"
