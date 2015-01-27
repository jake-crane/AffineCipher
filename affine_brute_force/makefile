OBJ=affine_brute_force.o ../affinelib/affinelib.o
TARGET=affine_brute_force
CFLAGS=-I../affinelib -std=c99

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) 

affine.o:
../affinelib/affinelib.o:
clean:
	rm -f $(TARGET) $(OBJ)
