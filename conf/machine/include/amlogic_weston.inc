#For Weston
DISTRO_FEATURES:append = " weston wayland weston-init"
PREFERRED_VERSION_weston = "10.0.0"
DISTRO_FEATURES:remove = " mesa mesa-gl x11"
DISTRO_FEATURES:remove = " amazon-plugin cobalt netflix selinux"
DISTRO_FEATURES:append = " dual_display"

#Remove netflix related
RDEPENDS:packagegroup-amlogic-baserootfs:remove = "netflix-aml wpeframework-plugin-netflix"
#Remove thunder framework related
RDEPENDS:packagegroup-amlogic-baserootfs:remove = "bluetooth-mgr bluetooth-core"
RDEPENDS:packagegroup-amlogic-baserootfs:append = "sshfs-fuse"
