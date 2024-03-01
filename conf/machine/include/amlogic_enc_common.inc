#@TYPE: Machine
#@NAME: meson

#@DESCRIPTION: Machine configuration for encoder

DISTRO_FEATURES:append = " gst-plugin-venc"
DISTRO_FEATURES:append = " gst-aml-videotranscoding"
DISTRO_FEATURES:append = " videotranscoding-demo "