OOBECOPY := "${OOBE}"
OOBE_ti33x = "${@bb.data.getVar('OOBECOPY',d,1).replace('gadget-init','gadget-ether-usb')}"

