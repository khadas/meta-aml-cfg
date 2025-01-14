SUMMARY = "Amlogic Yocto packgegroup"

LICENSE = "MIT"

PACKAGE_ARCH = "${TUNE_PKGARCH}"
inherit packagegroup

PACKAGES = "\
    packagegroup-amlogic-baserootfs \
    "

RDEPENDS:packagegroup-amlogic-baserootfs = "\
    toybox \
    sqlite3 \
    icu \
    libarchive \
    libunwind \
    libdaemon \
    libffi \
    libfastjson \
    glibc \
    expat \
    tinyalsa \
    alsa-utils \
    dnsmasq \
    bash \
    systemd \
    curl \
    dropbear \
    e2fsprogs \
    e2fsprogs-e2fsck \
    e2fsprogs-mke2fs \
    e2fsprogs-tune2fs \
    fuse-exfat \
    exfat-utils \
    ntfs-3g \
    glib-2.0 \
    gnutls \
    cmake \
    opencv \
    opencv-dev \
    libopencv-imgproc-dev \
    libopencv-core-dev \
    libopencv-videoio-dev \
    libopencv-imgcodecs-dev \
    libopencv-highgui-dev \
    opencv-samples \
    opencv-staticdev \
    iozone3 \
    iperf3 \
    fio \
    v4l-utils \
    git \
    jansson \
    libgcrypt \
    libgpg-error \
    libpcre \
    libsoup-2.4 \
    libxml2 \
    neon \
    popt \
    spawn-fcgi \
    yajl \
    procps \
    libnl \
    dbus \
    faad2 \
    libopus \
    android-tools \
    aml-hdcp \
    liblog \
    android-tools-logcat \
    iw \
    wpa-supplicant \
    wifi-amlogic \
    procrank \
    zram \
    modules-load \
    system-config \
    aml-libdvr \
    aml-mp-sdk \
    aml-pqserver \
    aml-subtitleserver \
    aml-ubootenv \
    aml-utils-simulate-key \
    vulkan-loader \
    ${@bb.utils.contains('DISTRO_FEATURES', 'aml-iptv', 'iptv-middlewave-bin', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'swupdate', 'cpio update-swfirmware', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'system-user', 'useradd', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'verimatrix', 'vmx-sdk-rel', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'aml-cas', 'drmplayer-bin ffmpeg-vendor', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'amlogic-tv', '', 'aml-hdmicec', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'amlogic-tv', 'aml-tvserver', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'dtvkit', 'dtvkit-release-prebuilt', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'aml-dtv', 'aml-dtvdemod', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'playready', 'playready', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'wfd-hdcp', 'wfd-hdcp', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'optee', 'optee-userspace', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'optee', 'tee-supplicant', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'optee', 'optee-video-firmware', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'widevine', 'aml-mediadrm-widevine', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'aml-libjpeg', 'libjpeg', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'aml-libmultienc', 'libmultienc libge2d libion', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'aml-libvpcodec', 'libvpcodec h264bitstream libion', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'aml-libvphevcodec', 'libvphevcodec libge2d libion', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'aml-libamvenc-264', 'libamvenc-264 h264bitstream libion', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'aml-libamvenc-265', 'libamvenc-265 libge2d libion', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'aml-libamvenc', 'libamvenc libion', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'mediactrlsrc', 'mediactrlsrc mediactrlsrc-dev', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'gstreamer1', \
        'gstreamer1.0-plugins-good \
        gstreamer1.0-plugins-bad \
        gst-plugin-aml-asink \
        gst-plugin-video-sink \
        gst-plugin-aml-v4l2dec \
        gst-aml-drm-plugins \
        gstreamer1.0-libav \
        gst-player \
        ', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'weston', \
        'wayland \
        weston-init \
        meson-display \
        fbscripts \
        ', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'qt5', \
        'qtbase \
        qtwebkit \
        qtwayland \
        qtquickcontrols2 \
        qtdeclarative \
        qtxmlpatterns \
        fontconfig \
        openssl \
        ', '', d)} \
    pulseaudio \
    ffmpeg \
    gst-agmplayer \
    libvideorender \
    playscripts \
    ${@bb.utils.contains('DISTRO_FEATURES', 'westeros', \
        'westeros westeros-soc-drm westeros-sink', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'aml-thunder', \
        'wpeframework wpeframework-ui thunder-services', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'cobalt', \
        'cobalt-plugin aml-cobalt-starboard', '', d)} \
    dolby-ms12 \
    aml-audio-hal \
    aml-provision \
    tinyalsa-tools \
    aml-audio-service aml-audio-service-testapps \
    ${@bb.utils.contains('DISTRO_FEATURES', 'tts', 'wpeframework-plugin-amltts', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'netflix', \
        'wpeframework-plugin-netflix netflix-aml aml-netflix-esn', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'bluetooth', \
        'bluetooth-mgr bluetooth-core', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'amazon-plugin', \
        'amazon-prime-plugin amazon-prime-src', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'aml-launcher', \
        'aml-launcher libhtmllocal htmllocal-plugin', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'aml-thunder', \
        'device-properties', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'aml-thunder', \
        'aml-dial', '', d)} \
    tzdata \
    tzcode \
    ${@bb.utils.contains('DISTRO_FEATURES', 'bluez-alsa', 'bluez-alsa', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'brcm-patchram-plus', 'brcm-patchram-plus', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'aml-libgdc', 'libgdc', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'bluetooth', 'bluez5-obex', '', d)} \
    web-ui-wifi \
    "

#VENC related
RDEPENDS:packagegroup-amlogic-baserootfs += " \
    ${@bb.utils.contains('DISTRO_FEATURES', 'gst-plugin-venc', bb.utils.contains('DISTRO_FEATURES', 'aml-libjpeg', 'gst-plugin-venc-jpeg', '', d), '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'gst-plugin-venc', bb.utils.contains('DISTRO_FEATURES', 'aml-libamvenc', 'gst-plugin-venc-amlvenc', '', d), '', d)} \
    "

#AML linux_sample_app screencapture related
RDEPENDS:packagegroup-amlogic-baserootfs += " \
    ${@bb.utils.contains('DISTRO_FEATURES', 'aml-screencapture', 'aml-screencapture', '', d)} \
    "

#AML gstreamer aml utils, common lib for other plugins
#AML gstreamer overlay and nnsdk demo plugin
RDEPENDS:packagegroup-amlogic-baserootfs += " \
    ${@bb.utils.contains('DISTRO_FEATURES', 'gst-plugin-overlay', 'gst-plugin-overlay', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'gst-plugin-nn', 'gst-plugin-nn', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'detect-library', 'detect-library', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'gst-plugin-conv', 'gst-plugin-conv', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'gst-aml-gfx2d', 'gst-aml-gfx2d', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'gst-aml-videotranscoding', 'gst-aml-videotranscoding', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'videotranscoding-demo', 'videotranscoding-demo', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'dma-allocator', 'dma-allocator', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'gst-aml-dma-allocator', 'gst-aml-dma-allocator', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'gst-jpeg-swdec', 'gst-jpeg-swdec', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'nnstreamer', 'nnstreamer', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'tensorflow-lite', 'tensorflow-lite', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'nnstreamer-example', 'nnstreamer-example', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'detect-sample', 'detect-sample', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'nndemo-library', 'nndemo-library', '', d)} \
    "

#AML test
RDEPENDS:packagegroup-amlogic-baserootfs += " \
    ${@bb.utils.contains('DISTRO_FEATURES', 'aml-test', 'aml-test', '', d)} \
    "

RDEPENDS:packagegroup-amlogic-baserootfs += " \
    ${@bb.utils.contains('DISTRO_FEATURES', 'amazon-prebuilt-pkg', 'amazon-prebuilt-pkg', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'cobalt-prebuilt-pkg', 'cobalt-prebuilt-pkg', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'netflix-prebuilt-pkg', 'netflix-prebuilt-pkg', '', d)} \
    "

#For Nagra CAS
RDEPENDS:packagegroup-amlogic-baserootfs += " \
    ${@bb.utils.contains('DISTRO_FEATURES', 'nagra', 'nagra-sdk', '', d)} \
    "

#Add ubifs tools
RDEPENDS:packagegroup-amlogic-baserootfs += "${@bb.utils.contains('DISTRO_FEATURES', 'nand', 'mtd-utils-ubifs', '',d)}"

#AVS related
RDEPENDS:packagegroup-amlogic-baserootfs += " \
    ${@bb.utils.contains('DISTRO_FEATURES', 'avs-sdk', 'avs-sdk', '', d)} \
    "

#ASS related
RDEPENDS:packagegroup-amlogic-baserootfs += " \
    ${@bb.utils.contains('DISTRO_FEATURES', 'ass-sdk', 'ass-sdk', '', d)} \
    "

#softap
RDEPENDS:packagegroup-amlogic-baserootfs += " \
    ${@bb.utils.contains('DISTRO_FEATURES', 'softap', 'wifi-ap-amlogic hostapd', '', d)} \
    "
#aml-utils
RDEPENDS:packagegroup-amlogic-baserootfs += " \
    ${@bb.utils.contains('DISTRO_FEATURES', 'input-event', 'aml-utils', '', d)} \
"

