DESCRIPTION = "Generic build script for all workshop lab exercises"
LICENSE="PD"
LIC_FILES_CHKSUM = "file://LICENSE;md5=d41d8cd98f00b204e9800998ecf8427e"

MYBASENAME = "${PN}"

INC_PR = "r0"

FILESPATH = "${FILE_DIRNAME}/files/usr/src/debug/${MYBASENAME}/1.0-r0.0/"

SRC_URI = "file://*.c \
	   file://*.h \
	   file://LICENSE \
	  "

S="${WORKDIR}"

# use base prefix when defining bindir for native and nativesdk classes 
bindir = "${base_prefix}/home/user/workshop"

# we need to append -O0 to CFLAGS in order to remove optimization for debugging
# don't forget the preceding space!
CFLAGS_append = " -O0"


do_compile() {
	${CC} ${S}/*.c ${CFLAGS} ${LDFLAGS} -o ${MYBASENAME}
}

do_install() {
	install -d ${D}${bindir}/
	install -m 0755 ${S}/${MYBASENAME} ${D}${bindir}/
}


