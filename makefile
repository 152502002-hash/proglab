CC = gcc

TARGET = hospital
SRCS = main.c doctor.c patient.c appointment.c
OBJS = main.o doctor.o patient.o appointment.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

