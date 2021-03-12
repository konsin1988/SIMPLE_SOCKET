receive_data: main.c hostname_to_ip.o
	gcc $^ -o $@

clean:
	rm *.o

run: receive_data
	./receive_data
