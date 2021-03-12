hostname_to_ip_test: main.c hostname_to_ip.o
	gcc $^ -o $@

clean:
	rm *.o

run: hostname_to_ip_test
	./hostname_to_ip_test
