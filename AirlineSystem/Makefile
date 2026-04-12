






# ============================================================
#   Makefile - Airline Management System
# ============================================================

# Compiler and flags
CXX      = g++
CXXFLAGS = -std=c++17 -Wall

# Final executable name
TARGET = AirlineSystem

# Source files to compile
# (header-only files like .h are included automatically)
SRCS = src/main.cpp \
       src/menus.cpp

# Object files (one .o per .cpp)
OBJS = src/main.o \
       src/menus.o

# ============================================================
#   Default target : build the executable
# ============================================================
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@echo "Build successful ! Run with: ./$(TARGET)"

# ============================================================
#   Compile each .cpp into a .o
# ============================================================
src/main.o: src/main.cpp src/menus.h \
            include/Passenger.h \
            include/BookingOffice.h \
            include/Ticket.h \
            include/Flight.h \
            data_structures/LinkedList.h \
            data_structures/Stack.h \
            data_structures/Queue.h
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o src/main.o

src/menus.o: src/menus.cpp src/menus.h \
             include/Passenger.h \
             include/BookingOffice.h \
             include/Ticket.h \
             include/Flight.h \
             data_structures/LinkedList.h \
             data_structures/Stack.h \
             data_structures/Queue.h
	$(CXX) $(CXXFLAGS) -c src/menus.cpp -o src/menus.o

# ============================================================
#   Clean : remove all .o files and the executable
# ============================================================
clean:
	rm -f src/main.o src/menus.o $(TARGET)
	@echo "Cleaned successfully !"