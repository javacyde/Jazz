objects := bin/groups.o bin/hex.o bin/jazz.o bin/main.o

bin/main.exe: $(objects)
	g++ $^ -o $@

$(objects): bin/%.o: src/%.cc
	g++ -c $^ -o $@

bin/%.o: src/%.cc
	touch $@

src/%.cc:
	touch $@

clean:
	rm -f bin/*