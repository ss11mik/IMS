# file: root Makefile
# project: "SHO ve výrobě"
# course: IMS
# authors: xmikul69, zpodes05
#   @ VUT FIT, Brno
# date: 2021
#


ZIPFILE=ims.zip

all: clean code documentation zip

clean:
	rm $(ZIPFILE) || true

code:
	cd model && make

documentation:
	cd doc && make

zip:
	zip -r $(ZIPFILE) doc/ims.pdf doc/
