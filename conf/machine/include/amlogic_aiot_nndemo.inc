#@TYPE: Machine
#@NAME: meson

#@DESCRIPTION: Machine configuration for meson AIOT NN relative systems

DISTRO_FEATURES:append = " gst-jpeg-swdec"
DISTRO_FEATURES:append = " gst-plugin-overlay"
DISTRO_FEATURES:append = " gst-plugin-nn"
DISTRO_FEATURES:append = " detect-library"
DISTRO_FEATURES:append = " detect-sample"
DISTRO_FEATURES:append = " nndemo-library"


