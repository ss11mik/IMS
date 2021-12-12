# file: root Makefile
# project: "SHO ve výrobě"
# course: IMS
# authors: xmikul69, zpodes05
#   @ VUT FIT, Brno
# date: 2021
#


ZIPFILE=10_xpodes05_xmikul69.zip

all: code documentation clean zip

clean:
	rm $(ZIPFILE) || true
	cd model && make clean
	cd doc && make clean


code:
	cd model && make clean && make

documentation:
	cd doc && make clean && make

zip:
	zip -r $(ZIPFILE) doc/ims.pdf doc/ model/
