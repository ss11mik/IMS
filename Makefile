# file: root Makefile
# project: "SHO ve výrobě"
# course: IMS
# authors: xmikul69, zpodes05
#   @ VUT FIT, Brno
# date: 2021
#


ZIPFILE=10_xpodes05_xmikul69.zip
DOCFILE=doc.pdf

all: code documentation zip

clean:
	rm $(ZIPFILE) $(DOCFILE) || true
	cd model && make clean || true
	cd doc && make clean || true


code:
	cd model && make

documentation:
	cd doc && make
	mv doc/ims.pdf $(DOCFILE)

zip:
	zip -r $(ZIPFILE) $(DOCFILE) model/
