# Compiler
CXX = g++

# Flags de compilation
CXXFLAGS = -std=c++23 -Iinclude

# Dossier des fichiers source
SRCDIR = src

# Dossier des fichiers objets
BUILDDIR = obj

# Liste des fichiers source, excluant le main.cpp
SOURCES := $(filter-out $(SRCDIR)/main.cpp, $(wildcard $(SRCDIR)/*.cpp))

# Liste des fichiers objets à générer à partir des fichiers source
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

# Fichier main.cpp
MAIN = main.cpp

# Nom de l'exécutable
EXECUTABLE = out

# Règle de construction de l'exécutable
$(EXECUTABLE): $(OBJECTS) $(BUILDDIR)/$(MAIN:.cpp=.o)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Règle de construction des fichiers objets
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Règle de construction de l'objet main
$(BUILDDIR)/$(MAIN:.cpp=.o): $(MAIN)
	mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers intermédiaires et l'exécutable
clean:
	rm -rf $(BUILDDIR) $(EXECUTABLE)

# Définition de la règle "all" pour construire l'exécutable
all: $(EXECUTABLE)

# Cible pour exécuter le programme
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Définition de la règle "default" comme alias pour "all"
.DEFAULT_GOAL := all
