# current nativesdk qt4 is used as a cross compiler, so the native libraries are missing

do_mylibs() {
	install -d ${STAGING_DIR_HOST}/${prefix}/share/qt4 
	install -d ${STAGING_DIR_HOST}/${prefix}/include/qt4 
	cp -Rf ${STAGING_DIR_NATIVE}/usr/share/qt4/* ${STAGING_DIR_HOST}/${prefix}/share/qt4
	cp -Rf ${STAGING_DIR_NATIVE}/usr/include/qt4/* ${STAGING_DIR_HOST}/${prefix}/include/qt4
	cp -Rf ${STAGING_DIR_NATIVE}/usr/lib/* ${STAGING_DIR_HOST}/${prefix}/lib/
}

EXPORT_FUNCTIONS do_mylibs

addtask mylibs after do_install before do_package
