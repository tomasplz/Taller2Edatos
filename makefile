# Especifica el compilador
CXX = g++-13

# Opciones de compilación
CXXFLAGS = -std=c++11 -Wall -static-libgcc -static-libstdc++

# Directorios de inclusión
INCLUDES = -I.

# Lista de archivos fuente
SRCS = main.cpp System/Sys.cpp Classes/category.cpp Classes/client.cpp Classes/clientHandicapped.cpp \
	Classes/clientPregnant.cpp Classes/clientNormal.cpp Classes/clientOld.cpp \
	Classes/clientFactory.cpp Classes/product.cpp

# Lista de objetos a generar
OBJS = $(SRCS:.cpp=.o)

# Nombre del ejecutable
EXEC = programa

# Regla para generar el ejecutable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(EXEC) $(OBJS)

# Regla para compilar cada archivo fuente
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Eliminar archivos objeto y ejecutable
clean:
	$(RM) $(OBJS) $(EXEC)

