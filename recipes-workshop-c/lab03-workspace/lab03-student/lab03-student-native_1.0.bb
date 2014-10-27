DESCRIPTION = "Starting bitbake recipe for lab 03"
LICENSE="PD"
LIC_FILES_CHKSUM = "file://${S}/LICENSE;md5=d41d8cd98f00b204e9800998ecf8427e"

PR = "r0"

SRC_URI = "file://LICENSE"

S="${WORKDIR}"

# use base prefix when defining bindir for native and nativesdk classes 
bindir = "${base_prefix}/home/user/workshop"

do_compile() {
	:
}

do_install() {
	:
}


