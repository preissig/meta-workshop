DESCRIPTION = "Generic build script for all workshop lab exercises"
LICENSE="PD"
LIC_FILES_CHKSUM = "file://${WORKDIR}/LICENSE;md5=d41d8cd98f00b204e9800998ecf8427e"

MYBASENAME = "${PN}"

INC_PR = "r0"

FILESPATH = "${FILE_DIRNAME}/files/usr/src/debug/${MYBASENAME}/1.0-r0.0/"

SRC_URI = "file://*.pro \
	   file://*.c \
	   file://*.cpp \
	   file://*.h \
	   file://LICENSE"

S="${WORKDIR}"

bindir = "${base_prefix}/home/user/workshop"

do_install() {
	oe_runmake INSTALL_ROOT=${D} INSTALL_PATH=${bindir} install
}
