# This recipe is based on the recipe by Koen in meta-texasinstruments
DESCRIPTION = "Scripts to initialize usb gadgets"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/LICENSE;md5=3f40d7994397109285ec7b81fdeb3b58"

COMPATIBLE_MACHINE = "ti33x"
PACKAGE_ARCH = "${MACHINE_ARCH}"

PR = "r1"

SRC_URI = "file://g_ether.conf"

do_install() {
    install -d ${D}${sysconfdir}/modules-load.d
    install -m 0755 ${WORKDIR}/g_ether.conf ${D}${sysconfdir}/modules-load.d/g_ether.conf
}

FILES_${PN} = "${sysconfdir}"
RRECOMMENDS_${PN} += "kernel-module-g-ether"
