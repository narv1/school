PDF =   bericht.pdf
SRC =   bericht.tex

all: $(PDF)

$(PDF): $(SRC) $(EPS)
	rubber -d $(SRC)

%.eps: images/%.png
	dia-normal -e $@ -t eps $<

clean:
	rm -f $(patsubst %,$(basename $(SRC)).%,aux lof log lot out toc) $(EPS) $(patsubst %.eps,%-eps-converted-to.pdf,$(EPS))

.PHONY: all clean
