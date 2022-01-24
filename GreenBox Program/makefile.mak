
sum: main.o customer.o customers.o movie.o movies.o transaction.o transactions.o entitem.o games.o
	g++ -o sum main.o customer.o customers.o movie.o movies.o transaction.o transactions.o entitem.o games.o
	
main.o: main.cpp customer.h customers.h movie.h movies.h transaction.h transactions.h entitem.h games.h
	g++ -c main.cpp
	
customer.o: customer.cpp customer.h
	g++ -c customer.cpp
	
customers.o: customers.cpp customers.h
	g++ -c customers.cpp
	
movie.o: movie.cpp movie.h
	g++ -c movie.cpp
	
movies.o: movies.cpp movies.h
	g++ -c movies.cpp
	
transaction.o: transaction.cpp transaction.h
	g++ -c transaction.cpp
	
transactions.o: transactions.cpp transactions.h
	g++ -c transactions.cpp
	
entitem.o: entitem.cpp entitem.h
	g++ -c entitem.cpp
	
games.o: games.cpp games.h
	g++ -c games.cpp