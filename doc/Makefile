# file: documentation Makefile
# project: "SHO ve výrobě"
# course: IMS
# authors: xmikul69, zpodes05
#   @ VUT FIT, Brno
# date: 2021
#


all:
	pdflatex ims.tex
	bibtex ims
	pdflatex ims.tex
	pdflatex ims.tex

clean:
	rm *.log *.out *.aux *.toc *.dvi *.blg *.bbl
	rm *.pdf
