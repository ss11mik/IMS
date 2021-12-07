
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
