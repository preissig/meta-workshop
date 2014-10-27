require ${PN}_${PV}.inc

PR="${INC_PR}.0"

bindir = "${base_prefix}/home/root/workshop"

# This is a bad cheat
# would be more natural to rebuild full rootfs which would rebuild this dependency in it
# but we cant afford to rebuild the entire rootfs every time we recompile

TARGET_ROOTFS = "${WORKDIR}/../../../am335x_evm-oe-linux-gnueabi/tisdk-rootfs-image/1.0-r0/rootfs"

do_my_package_write_ipk() {
	install -d ${TARGET_ROOTFS}
	cp -R ${WORKDIR}/package/* ${TARGET_ROOTFS}
}

do_package_write_ipk_append() {
bb.build.exec_func("do_my_package_write_ipk", d)
}

EXPORT_FUNCTIONS do_my_package_write_ipk

